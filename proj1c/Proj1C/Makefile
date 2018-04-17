
cli: cli/cli.c lib.a
	mv libmath330.a lib; \
	gcc -Wall -o bin/cli cli/cli.c -Iinclude -Llib -lmath330

lib.a: exp330.o log330.o cos330.o sin330.o tan330.o
	ar r libmath330.a exp330.o log330.o cos330.o sin330.o tan330.o

exp330.o: exp/exp330.c	
	mkdir -p lib; \
	mkdir -p bin; \
	mkdir -p include; \
	cp math330.h include; \
	gcc -c exp/exp330.c -Iinclude

log330.o: exp/log330.c
	gcc -c exp/log330.c -Iinclude

cos330.o: trig/cos330.c
	gcc -c trig/cos330.c -Iinclude

sin330.o: trig/sin330.c
	gcc -c trig/sin330.c -Iinclude

tan330.o: trig/tan330.c
	gcc -c trig/tan330.c -Iinclude

clean:
	rm -f *.o; \
	rm -rf bin; \
	rm -rf include; \
	rm -rf lib
