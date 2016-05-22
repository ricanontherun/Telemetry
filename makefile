COMPILER=g++
FLAGS=-g -std=c++11
FILES=main.cpp api/API.cpp api/ProcessAPI.cpp core/process/Process.cpp core/util/file.c core/sys/SystemInfo.cpp
EXECUTABLE=p

all:
	$(COMPILER) $(FLAGS) $(FILES) -o $(EXECUTABLE)
