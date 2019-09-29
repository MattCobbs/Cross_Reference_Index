runMain: main.o bstree.o node.o
	g++ main.o bstree.o node.o -o runMain

main.o: main.cpp bstree.h node.h
	g++ -c main.cpp

node.o: node.cpp node.h
	g++ -c node.cpp

bstree.o: bstree.cpp bstree.h node.h
	g++ -c bstree.cpp

clean:
	rm -f *.o
	rm runMain
	rm sampleOut.txt

run: runMain
	./runMain

valgrind: 
	valgrind ./runMain
