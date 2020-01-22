#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class IGame {
	protected:
		std::string name;
		sf::RenderWindow& window;
		sf::Event event;
		std::vector<sf::Font> f;
		bool back;
	public:
		void setName(std::string n);
		std::string getName();
		IGame(std::string n, sf::RenderWindow& w_, sf::Event e, std::vector<sf::Font> fs);
		virtual void run() = 0;
		virtual void display() = 0;
		virtual void load() = 0;
		bool getBack();
		void setBack(bool n);
};
