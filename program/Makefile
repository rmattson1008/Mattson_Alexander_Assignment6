CXXFLAGS = -std=c++0x

main: main.o ItemType.o Heap.o
		$(CXX) $(CXXFLAGS) -o main main.o ItemType.o Heap.o
main.o: main.cpp ItemType.h Heap.h
		$(CXX) $(CXXFLAGS) -c main.cpp
Heap.o: Heap.h ItemType.h

clean:
		rm -rf *.o
		rm -rf main
compile:
		g++ $(CXXFLAGS) -c main.cpp
		g++ $(CXXFLAGS) -c Heap.cpp
		g++ $(CXXFLAGS) -c ItemType.cpp
		g++ -o main main.o ItemType.o Heap.o
run:
		g++ $(CXXFLAGS) -c main.cpp
		g++ $(CXXFLAGS) -c Heap.cpp
		g++ $(CXXFLAGS) -c ItemType.cpp
		g++ -o main main.o ItemType.o Heap.o

		./main ordered.txt