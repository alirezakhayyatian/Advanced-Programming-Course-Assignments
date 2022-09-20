CXX = g++
CXXFLAGS = -std=c++17 -Wall -c 
LXXFLAGS = -std=c++17 
OBJECTS = main.o maxheap.o
TARGET = main

$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX)	$(CXXFLAGS)	main.cpp
maxheap.o: maxheap.cpp maxheap.h
	$(CXX)	$(CXXFLAGS)	maxheap.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)		

	
