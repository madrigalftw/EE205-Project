#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "IGame.hpp"

void IGame::setName(std::string n){name = n;}

std::string IGame::getName(){return name;}

IGame::IGame(std::string n, sf::RenderWindow& w_, sf::Event e, std::vector<sf::Font> fs):
	name(n), window(w_), event(e), f(fs), back(0){}

bool IGame::getBack(){return back;}

void IGame::setBack(bool n){back = n;}
