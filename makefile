main : main.o link.o socket.o
	cc -o main main.o link.o socket.o -lpthread
main.o : main.c
	cc -c main.c
link.o : src/link.c
	cc -c src/link.c
socket.o : src/socket.c
	cc -c src/socket.c
clean :
	rm main main.o link.o socket.o
