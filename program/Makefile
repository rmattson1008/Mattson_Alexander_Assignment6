CXXFLAGS = -std=c++0x

main: main.o ItemType.o Heap.o Sorting.o
		$(CXX) $(CXXFLAGS) -o main main.o ItemType.o Heap.o Sorting.o
main.o: main.cpp ItemType.h Heap.h Sorting.h
		$(CXX) $(CXXFLAGS) -c main.cpp
Heap.o: Heap.h ItemType.h
Sorting.o: Heap.h ItemType.h Sorting.h

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
		g++ $(CXXFLAGS) -c Sorting.cpp
		g++ -o main main.o ItemType.o Heap.o Sorting.o

		# ./main ordered.txt
		./main reverse.txt
		# ./main random.txt