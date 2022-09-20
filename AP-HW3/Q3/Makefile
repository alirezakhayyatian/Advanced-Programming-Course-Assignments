CXX = g++
CXXFLAGS = -std=c++17 -Wall -c 
LXXFLAGS = -std=c++17 
OBJECTS = main.o vec.o
TARGET = main

$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX)	$(CXXFLAGS)	main.cpp
vec.o: vec.cpp vec.h
	$(CXX)	$(CXXFLAGS)	vec.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)		

	
