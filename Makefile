CC=gcc
CXX=g++
RM=del
EXT=exe

all:
	$(CXX) src/*.cpp -o aria 
	./aria
	$(RM) aria.$(EXT)

clean:
	$(RM) *.$(EXT) *.o *.out