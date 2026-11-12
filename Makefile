
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

all: lab11

lab11: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o lab11

clean:
	rm -f lab11
