A ?= -Wall

edf: real.c
	gcc -o edf real.c -DEDF

rate: real.c
	gcc -o rate real.c -DRATE

clean:
	rm -f edf rate edf.out rate.out

testrate:
	./rate test_rate/$(A).txt && diff rate.out test_rate/$(A).out

testedf:
	./edf test_edf/$(A).txt && diff edf.out test_edf/$(A).out