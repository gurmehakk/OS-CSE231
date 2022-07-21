OSa1q1:
	gcc -o Q1a fork.c -I.
	gcc -o Q1b thread.c -lpthread -I.
run1:
	./Q1a
run2:
	./Q1b

	