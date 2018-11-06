main: main.o table.o min.o entry.o
	g++ -std=c++11 -o main main.o table.o min.o entry.o

main.o: main.cpp table.h entry.h
	g++ -std=c++11 -c main.cpp

table.o: table.cpp table.h
	g++ -std=c++11 -c table.cpp 

min.o: min.cpp min.h
	g++ -std=c++11 -c min.cpp 

entry.o: entry.cpp entry.h
	g++ -std=c++11 -c entry.cpp 

clean:
	rm -f main main.o table.o min.o entry.o