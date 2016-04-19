COMPILER=g++
FLAGS=-g -std=c++11
FILES=main.cpp api/API.cpp api/ProcessAPI.cpp core/process/Process.cpp
EXECUTABLE=p

all:
	$(COMPILER) $(FLAGS) $(FILES) -o $(EXECUTABLE)
