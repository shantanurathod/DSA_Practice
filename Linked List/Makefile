main: main.o linkedlist.o
	g++ main.o linkedlist.o -o main

main.o: main.cpp
	g++ -c main.cpp

linkedlist.o: linkedlist.cpp
	g++ -c linkedlist.cpp

clean:
	rm main *.o	