#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "Tilemap.hpp"
#include "IGame.hpp"
#include "cursor.hpp"

class AdvanceWarX: public IGame {
	private:
		std::vector<sf::Texture> tset;
		Tilemap map;
		std::vector<Building> buildings;
		std::vector<Units> units;
		std::vector<Units> self;
	public:
		AdvanceWarX(std::string n, sf::RenderWindow& w_, sf::Event e, std::vector<sf::Font> fs, std::vector<sf::Texture> s);
		void run();
		void load();
		void display();
		void makeLevel();
};
