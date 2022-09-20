CXX = g++
CXXFLAGS = -std=c++17 -Wall -c 
LXXFLAGS = -std=c++17 
OBJECTS = main.o circle.o square.o cube.o shape.o sphere.o point.o
TARGET = main

$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX)	$(CXXFLAGS)	main.cpp
circle.o: circle.cpp circle.h
	$(CXX)	$(CXXFLAGS)	circle.cpp
square.o: square.cpp square.h
	$(CXX)	$(CXXFLAGS)	square.cpp	
cube.o: cube.cpp cube.h
	$(CXX)	$(CXXFLAGS)	cube.cpp
	
sphere.o: sphere.cpp sphere.h
	$(CXX)	$(CXXFLAGS)	sphere.cpp	
shape.o: shape.cpp shape.h
	$(CXX)	$(CXXFLAGS)	shape.cpp	

point.o: point.cpp point.h
	$(CXX)	$(CXXFLAGS)	point.cpp	
clean:
	rm -f $(TARGET) $(OBJECTS)		

	
