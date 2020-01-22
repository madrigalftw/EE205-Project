#include <iostream>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include "utility.hpp"
#include "Start.hpp"
#include "AWX.hpp"

int main(){
	std::vector<sf::Font> fset = loadFonts();
	std::vector<sf::Texture> tset = loadTextures();
	std::map<int, IGame*> selection;
	IGame* p = NULL;

	sf::RenderWindow window(sf::VideoMode(500, 500), "Palystotion X");
	sf::Event event;
	sf::Keyboard::Key x;

	p = new AdvanceWarX("Advance Wars X", window, event, fset, tset);
        selection[0] = p;

	Start s(selection);
	window.setFramerateLimit(60);

	while(window.isOpen()){
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
				exit(1);
			}
			if(event.type == sf::Event::KeyPressed){
				s.go2game(event.key.code);
			}
		}
		s.origin(window, fset);
	}
	return 0;
}
