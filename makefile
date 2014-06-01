main : main.o link.o
	cc -o main main.o link.o
main.o : main.c
	cc -c main.c
link.o : src/link.c
	cc -c src/link.c
clean :
	rm main main.o link.o
