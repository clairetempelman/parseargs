all: parse_args.o
	gcc -o program parse_args.o

parse_args.o: parse_args.c
	gcc -c parse_args.c

run:
	./program

clean:
	rm *.o
	rm *~
