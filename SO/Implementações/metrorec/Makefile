# Default to debugging flags. Set to -O3 if you want optimisations
# (either change it here, or type 'make CFLAGS=-O3' in the shell).
CFLAGS?=-g -Wall -Wno-unused-value

all: metrorec

metrorec: metrorec-runner.c metrorec.c
	$(CC) $(CFLAGS) -o metrorec metrorec-runner.c -lpthread 

clean:
	$(RM) metrorec reaction
	$(RM) -r *.dSYM
