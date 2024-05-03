#include <pthread.h>

struct estacao {
    int free_seats; // number of free seats in the train, -if one exists at station-.
    int passengers_waiting; // number of passengers waiting at station
    int passengers_leaving; // number of passengers who have found a free seat
    pthread_mutex_t mutex;
    pthread_cond_t free_seats_available; // train arrived with free seats
    pthread_cond_t passengers_on_board; // all leaving passengers have been seated
};


void estacao_init(struct estacao *estacao) {
    /* initially, station is empty */
    estacao->free_seats = 0;
    estacao->passengers_waiting = 0;
    estacao->passengers_leaving = 0;
    /* initialize station mutex and condition variables */
    pthread_mutex_init(&(estacao->mutex), NULL);
    pthread_cond_init(&(estacao->free_seats_available), NULL);
    pthread_cond_init(&(estacao->passengers_on_board), NULL);
}

void estacao_preencher_vagao(struct estacao * estacao, int count) {
    pthread_mutex_lock(&(estacao->mutex)); // enter critical section
    if (!count || ! estacao->passengers_waiting) { // no free seats available or no passengers waiting
        pthread_mutex_unlock(&(estacao->mutex)); // release the lock and leave critical section
        return; // train must leave the station promptly
    }
    estacao->free_seats = count;
    pthread_cond_broadcast(&(estacao->free_seats_available)); // wake up all passengers waiting for a free seat
    pthread_cond_wait(&(estacao->passengers_on_board), &(estacao->mutex)); // waiting for all passengers to get on board
    estacao->free_seats = 0;
    pthread_mutex_unlock(&(estacao->mutex)); // leave critical section
}

void estacao_espera_pelo_vagao(struct estacao * estacao) {
    pthread_mutex_lock(&(estacao->mutex)); // enter critical section
    estacao->passengers_waiting++;
    while (! estacao->free_seats)
        pthread_cond_wait(&(estacao->free_seats_available), &(estacao->mutex)); // waiting for a train with free seats
    estacao->passengers_waiting--;
    estacao->passengers_leaving++;
    estacao->free_seats--;
    pthread_mutex_unlock(&(estacao->mutex)); // leave critical section
}

void estacao_embarque(struct estacao * estacao) {
    pthread_mutex_lock(&(estacao->mutex)); // enter critical section
    estacao->passengers_leaving--;
    if (! estacao->passengers_leaving && !(estacao->passengers_waiting && estacao->free_seats)) // all leaving passengers are on board, and no other passengers can get on the train
        pthread_cond_signal(&(estacao->passengers_on_board));
    pthread_mutex_unlock(&(estacao->mutex)); // leave critical section
}
