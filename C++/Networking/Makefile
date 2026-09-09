decoder: main.o Port_decoder.o
	g++ Port_decoder.o main.o -o decoder
main.o: main.cpp Port_decoder.h
	g++ -c main.cpp -o main.o
Port_decoder.o: Port_decoder.cpp Port_decoder.h
	g++ -c Port_decoder.cpp -o Port_decoder.o

clean:
	rm -f *.o decoder