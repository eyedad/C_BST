all: tree run

run: tree
	./bin/tree.out

tree: main BST
	gcc build/BST.o build/main.o -o bin/tree.out

main: src/main.c
	gcc -c src/main.c -o build/main.o

BST: src/BST.c
	gcc -c src/BST.c -o build/BST.o

clean:
	rm -f build/*.o bin/tree.out