#include <iostream>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include "IGame.hpp"

class Start {
private:
	std::map<int, IGame*> selection;
	int choose;
public:
	Start(std::map<int, IGame*> s);
	void go2game(sf::Keyboard::Key x);
	void origin(sf::RenderWindow& window, std::vector<sf::Font> f);
};
