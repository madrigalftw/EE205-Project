#include <vector>
#include <SFML/Graphics.hpp>
#include "utility.hpp"

std::vector<sf::Texture> loadTextures(){
	std::vector<sf::Texture> x;
	sf::Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14;

	// Add fonts from file
	t1.loadFromFile("Sprite/SoldierR.png"); t2.loadFromFile("Sprite/SoldierB.png");
	t3.loadFromFile("Sprite/BazookaR.png"); t4.loadFromFile("Sprite/BazookaB.png");
	t5.loadFromFile("Sprite/TankR.png"); t6.loadFromFile("Sprite/TankB.png");
	t7.loadFromFile("Sprite/HQR.png"); t8.loadFromFile("Sprite/HQB.png");
	t9.loadFromFile("Sprite/IndustryR.png"); t10.loadFromFile("Sprite/IndustryB.png");
	t11.loadFromFile("Sprite/BuildingR.png"); t12.loadFromFile("Sprite/BuildingB.png");
	t13.loadFromFile("Sprite/Cursor.png"); t14.loadFromFile("Sprite/Movement.png");
	// Add fonts to vector
	x.push_back(t1); x.push_back(t2);
	x.push_back(t3); x.push_back(t4); 
	x.push_back(t5); x.push_back(t6); 
	x.push_back(t7); x.push_back(t8); 
	x.push_back(t9); x.push_back(t10); 
	x.push_back(t11); x.push_back(t12); 
	x.push_back(t13); x.push_back(t14);

	return x;
}

std::vector<sf::Font> loadFonts(){
	std::vector<sf::Font> x;
	sf::Font f1, f2, f3, f4;
	
	// Add fonts from file
	f1.loadFromFile("Fonts/Lobster_1.3.otf"); f2.loadFromFile("Fonts/TIMESBD.TTF");
	f3.loadFromFile("Fonts/ostrich-regular.ttf"); f4.loadFromFile("Fonts/OstrichSans-Heavy.otf");

	// Add fonts to vector
	x.push_back(f1); x.push_back(f2); x.push_back(f3); x.push_back(f4);

	return x;
}
