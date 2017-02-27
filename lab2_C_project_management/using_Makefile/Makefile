program.bin: module1.o module2.o differnet_file.o main.o
	gcc module1.o module2.o differnet_file.o main.o -o program.bin

main.o: main.c
	gcc main.c -c

module1.o: module1.c
	gcc module1.c -c

module2.o: module2.c
	gcc module2.c -c

differnet_file.o: differnet_file.c
	gcc differnet_file.c -c
