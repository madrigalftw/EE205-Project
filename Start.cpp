#include <iostream>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include "Start.hpp"

Start::Start(std::map<int, IGame*> s): selection(s){
	choose = -1;
}

void Start::go2game(sf::Keyboard::Key x){
	switch(x){
		case sf::Keyboard::Num0:
			choose = 0;
			break;
		case sf::Keyboard::Num1:
			choose = 1;
			break;
		default: choose = -1;
			break;
	}
	
	if(choose < 0){}
	else{
		while(!(*selection[choose]).getBack()){
			(*selection[choose]).display();
		}

		(*selection[choose]).setBack(0);
	}
}
	
void Start::origin(sf::RenderWindow& window, std::vector<sf::Font> f){
	window.clear();

	sf::Text txt("Welcome to Palystotion X!", f[0], 25);
	txt.setFillColor(sf::Color::White);
	txt.setPosition(125, 0);
	window.draw(txt);

	txt.setString("Please select a game: ");
	txt.setFont(f[1]);
	txt.setPosition(0, 50);
	window.draw(txt);

	for(auto it = selection.begin(); it != selection.end(); it++){
		txt.setString(std::to_string(it->first) + " | " + it->second->getName());
		txt.setPosition(0, 75 + 25*(it->first));
		window.draw(txt);
	}

	window.display();
}
