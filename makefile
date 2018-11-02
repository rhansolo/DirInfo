all: dir.c
	gcc dir.c

clear: a.out
	rm a.out

run: a.out
	clear
	./a.out
