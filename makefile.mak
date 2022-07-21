OSa1q2:
	nasm -f elf64 -o B.o B.asm

run1:
	gcc -no-pie A.c B.o C.c -o out.bin
run2:
	./run

	