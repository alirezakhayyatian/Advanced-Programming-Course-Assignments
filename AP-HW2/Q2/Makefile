CXX = g++
CXXFLAGS = -std=c++17 -Wall -c 
LXXFLAGS = -std=c++17 
OBJECTS = main.o libArr.o libVec.o
TARGET = main

$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
ali.o: main.cpp
	$(CXX)	$(CXXFLAGS)	main.cpp
libArr.o:libArr.cpp
	$(CXX)	$(CXXFLAGS)	libArr.cpp
libVec.o:libVec.cpp
	$(CXX)	$(CXXFLAGS)	libVec.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)		

	
