# Makefile
CXX = g++
CXXFLAGS = -Iinclude -std=c++11
SRC = $(wildcard src/*.cpp)
OUT = library_app

all:
	$(CXX) $(SRC) $(CXXFLAGS) -o $(OUT)

clean:
	del $(OUT).exe  # Use rm $(OUT) on Linux/Mac
