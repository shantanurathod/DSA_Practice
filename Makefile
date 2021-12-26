CC=g++
flags=-Wall -pedantic -std=c++17 -Wconversion -Wextra -O2

all: slow

slow:
	$(CC) -o $(arg) $(flags) $(arg).cpp

fast:
	$(CC) -o $(arg) $(arg).cpp

clean:
	rm $(arg).o