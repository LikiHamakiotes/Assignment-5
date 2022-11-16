list.out:
	gcc list.c -o list.out

test: list.out
	./list.out
