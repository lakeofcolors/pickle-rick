CC = cc
CFLAGS = -Wall -Werror -Wmissing-prototypes
OBJS = client.o connect.o handler.o

client: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o client

connect.o: connect.c connect.h
	$(CC) $(CFLAGS) -c connect.c

client.o: client.c
	$(CC) $(CFLAGS) -c client.c

handler.o: handler.c handler.h
	$(CC) $(CFLAGS) -c handler.c


clean:
	rm ./client
	rm client.o
	rm connect.o
	rm handler.o
