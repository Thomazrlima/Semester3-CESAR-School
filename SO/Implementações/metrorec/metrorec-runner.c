// SPDX-License-Identifier: GPL-3.0
/*
 * This file tests the implementation in sync_car.c.
 *
 * Note that passing these tests doesn't guarantee that your code is correct
 * or meets the specifications given, but hopefully it's at least pretty
 * close.
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#include "metrorec.c"

volatile int threads_completed = 0;

void *passageiros_thread(void *arg)
{
	struct estacao *estacao = (struct estacao *) arg;
	estacao_espera_pelo_vagao(estacao);
	__sync_add_and_fetch(&threads_completed, 1);
	return NULL;
}

struct vagao_args {
	struct estacao *estacao;
	int assentos_livres;
};

volatile int load_car_returned = 0;

void *vagao_thread(void *args)
{
	struct vagao_args *ltargs = (struct vagao_args *) args;
	estacao_preencher_vagao(ltargs->estacao, ltargs->assentos_livres);
	load_car_returned = 1;
	return NULL;
}

const char *alarm_error_str;
int alarm_timeout;

void _alarm(int seconds, const char *error_str)
{
	alarm_timeout = seconds;
	alarm_error_str = error_str;
	alarm(seconds);
}

void alarm_handler(int foo)
{
	fprintf(stderr, "Error: Failed to complete after %d seconds. Something's "
                    "wrong, or your system is terribly slow. Possible error hint: [%s]\n",
            alarm_timeout, alarm_error_str);
	exit(1);
}

#ifndef MIN
#define MIN(_x, _y) ((_x) < (_y)) ? (_x) : (_y)
#endif

int main(void)
{
	struct estacao estacao;
	estacao_init(&estacao);

	int retorno;

	srandom(getpid() ^ time(NULL));

	signal(SIGALRM, alarm_handler);

        // Make sure estacao_preecher_vagao() returns immediately if no waiting passengers.
	_alarm(1, "estacao_preecher_vagao() did not return immediately when no waiting passengers");
	estacao_preecher_vagao(&estacao, 0);
	estacao_preecher_vagao(&estacao, 10);
	_alarm(0, NULL);

        // Create a bunch of 'passengers', each in their own thread.
	int i;
	const int total_passengers = 100;
	int passengers_left = total_passengers;
	for (i = 0; i < total_passengers; i++) {
		pthread_t tid;
		int ret = pthread_create(&tid, NULL, passageiros_thread, &estacao);
		if (ret != 0) {
                        // If this fails, perhaps we exceeded some system limit.
			// Try reducing 'total_passengers'.
			perror("pthread_create");
			exit(1);
		}
	}

        // Make sure estacao_preecher_vagao() returns immediately if no free seats.
	_alarm(2, "estacao_preecher_vagao didn't return immediately when no free seats");
	estacao_preecher_vagao(&estacao, 0);
	_alarm(0, NULL);

	int total_passengers_boarded = 0;
	const int max_free_seats_per_car = 50;
	int pass = 0;
	while (passengers_left > 0) {
		_alarm(2, "Some more complicated issue appears to have caused passengers "
			"not to board when given the opportunity");

		int free_seats = random() % max_free_seats_per_car;

		printf("car entering station with %d free seats\n", free_seats);
		load_car_returned = 0;
		struct vagao_args args = {&estacao, free_seats};
		pthread_t lt_tid;
		int ret = pthread_create(&lt_tid, NULL, vagao_thread, &args);

		if (ret != 0) {
			perror("pthread_create");
			exit(1);
		}

		int threads_to_reap = MIN(passengers_left, free_seats);
		int threads_reaped = 0;

		while (threads_reaped < threads_to_reap) {
			if (load_car_returned) {
				fprintf(stderr, "Error: estacao_preecher_vagao ");
				fprintf(stderr, "returned early!\n");
				exit(1);
			}
			if (threads_completed > 0) {
				if ((pass % 2) == 0)
					usleep(random() % 2);
				threads_reaped++;
				estacao_embarque(&estacao);
				__sync_sub_and_fetch(&threads_completed, 1);
			}
		}

                // Wait a little bit longer. Give estacao_preecher_vagao() a chance to return
		// and ensure that no additional passengers board the train. One second
		// should be tons of time, but if you're on a horribly overloaded system,
		// this may need to be tweaked.
		for (i = 0; i < 1000; i++) {
			if (i > 50 && load_car_returned)
				break;
			usleep(1000);
		}

		if (!load_car_returned) {
			fprintf(stderr, "Error: estacao_preecher_vagao failed\n");
			exit(1);
		}

		while (threads_completed > 0) {
			threads_reaped++;
			__sync_sub_and_fetch(&threads_completed, 1);
		}

		passengers_left -= threads_reaped;
		total_passengers_boarded += threads_reaped;
		printf("car departed station with %d new passenger(s) ",
		       threads_reaped);
		printf("(expected %d)%s\n", threads_to_reap,
		       (threads_to_reap != threads_reaped) ? " *****" : "");

		if (threads_to_reap != threads_reaped) {
			fprintf(stderr, "Error: Many passengers on this car\n");
			exit(1);
		}
		pass++;
	}

	if (total_passengers_boarded == total_passengers) {
		printf("Looks good!\n");
		retorno = 0;
	} else {
		fprintf(stderr, "Error: expected %d total boarded passengers, "
			, total_passengers);
		fprintf(stderr, "but got %d!\n", total_passengers_boarded);

		retorno = 1;
	}
	return retorno;
}
