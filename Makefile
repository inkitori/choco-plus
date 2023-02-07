CC=gcc
CXX=g++
RM=rm
EXT=exe
PROGRAM_NAME=choco
FLAGS=-pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused

all:
	$(CXX) src/*.cpp -lncurses -o ${PROGRAM_NAME} ${FLAGS} 
	./${PROGRAM_NAME}
	$(RM) ${PROGRAM_NAME}

clean:
	$(RM) *.$(EXT) *.o *.out