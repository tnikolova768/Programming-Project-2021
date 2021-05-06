all: tictactoe

game.o: game.hpp game.cpp
player.o: player.hpp player.cpp
human.o: human.cpp human.hpp
ai.o: ai.cpp ai.hpp
main.o: main.cpp game.hpp


tictactoe: main.o game.o player.o human.o ai.o
	g++ main.o game.o player.o human.o ai.o 

clean:
	rm -f *.o a.out
