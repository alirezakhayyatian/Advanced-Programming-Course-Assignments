CXX = g++
CXXFLAGS = -std=c++17 -Wall -c 
LXXFLAGS = -std=c++17 
OBJECTS = main.o
TARGET = main

$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
ali.o: main.cpp
	$(CXX)	$(CXXFLAGS)	main.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)		

	
