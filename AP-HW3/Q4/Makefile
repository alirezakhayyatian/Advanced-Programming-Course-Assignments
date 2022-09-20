CXX = g++
CXXFLAGS = -std=c++17 -Wall -c 
LXXFLAGS = -std=c++17 
OBJECTS = main.o human.o oracle.o
TARGET = main

$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX)	$(CXXFLAGS)	main.cpp
human.o:human.cpp human.h
	$(CXX)	$(CXXFLAGS)	human.cpp
oracle.o:oracle.cpp oracle.h
	$(CXX)	$(CXXFLAGS)	oracle.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)		

	
