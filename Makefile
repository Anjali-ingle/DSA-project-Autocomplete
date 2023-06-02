SOURCE = main.c search.c intercept.c trie.c modify.c
OBJS = main.o search.o intercept.o trie.o modify.o
HEADER = trie.h
OUT = typing-assistant
CC = gcc
FLAGS = -g -c

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)

main.o : main.c
	$(CC) $(FLAGS) main.c

trie.o : trie.c
	$(CC) $(FLAGS) trie.c

intercept.o : intercept.c
	$(CC) $(FLAGS) intercept.c

modify.o : modify.c
	$(CC) $(FLAGS) modify.c

search.o : search.c
	$(CC) $(FLAGS) search.c

build : $(SOURCE)
	$(CC) -o $(OUT) $(SOURCE)

clean : 
	rm -f $(OBJS) $(OUT)

rebuild : clean build


