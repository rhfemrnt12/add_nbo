all: add_nbo

main: add_nbo.o
	g++ -c -o add_nbo add_nbo.o

main.o: add_nbo.cpp

clean:
	rm -f *.o, add_nbo