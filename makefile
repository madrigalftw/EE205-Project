all: console

console: main.o IGame.o AWX.o Start.o buildings.o Tilemap.o utility.o cursor.o units.o
	g++ main.o IGame.o Start.o AWX.o buildings.o Tilemap.o utility.o cursor.o units.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
main.o: main.cpp
	g++ -c main.cpp
IGame.o: IGame.cpp IGame.hpp
	g++ -c IGame.cpp
AWX.o: AWX.cpp AWX.hpp
	g++ -c AWX.cpp
Start.o: Start.cpp Start.hpp
	g++ -c Start.cpp
buildings.o: buildings.cpp
	g++ -c buildings.cpp
Tilemap.o: Tilemap.cpp Tilemap.hpp
	g++ -c Tilemap.cpp
utility.o: utility.cpp utility.hpp
	g++ -c utility.cpp
cursor.o: cursor.cpp cursor.hpp
	g++ -c cursor.cpp
units.o: units.cpp units.hpp
	g++ -c units.cpp

clean:
	rm -f *.o
