
all: unix_fun printer doubler

printer: printer.c
	gcc -o printer printer.c

doubler: doubler.c
	gcc -o doubler doubler.c

unix_fun: unix_fun.o
	gcc -o unix_fun unix_fun.o

unix_fun.o: unix_fun.c
	gcc -c unix_fun.c

clean:
	rm -f *.o
