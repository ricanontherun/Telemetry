COMPILER=g++
FLAGS=-g -std=c++11
FILES=main.cpp manager/Manager.cpp manager/ProcessManager.cpp core/process/Process.cpp core/util/file.c core/sys/SystemInfo.cpp core/SystemUser.cpp core/util/str.cpp
EXECUTABLE=p

all:
	$(COMPILER) $(FLAGS) $(FILES) -o $(EXECUTABLE)
