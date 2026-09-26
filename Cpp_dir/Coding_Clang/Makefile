main: main.o sniffer.o
	g++ main.o sniffer.o -o main

main.o: main.cpp sniffer.h
	g++ -c main.cpp -o main.o

sniffer.o: sniffer.cpp sniffer.h
	g++ -c sniffer.cpp -o sniffer.o

clean:
	rm -f *.o main