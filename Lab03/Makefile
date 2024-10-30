

main: main.o
	gcc main.o -o main

main.o: main.c
	gcc -c main.c -o main.o

asm: main.c
	gcc -s main.c -o main.s

main.c: 
	echo "int main(){return 0;}" > main.c

clean:
	rm -f *.o *.s main

# hello:
# 	echo "Hello"

