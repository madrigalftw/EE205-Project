#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include "buildings.cpp"

class Units {
	protected:
		std::string name;
		sf::Sprite unit;
		float hp;
		float x;
		float y;
		int attack;
		int number;
		int movement;
		std::vector<sf::Texture>& tset;
		sf::Vector2f position;
	public:
		Units(float x_, float y_, std::vector<sf::Texture>& t);
		sf::Sprite getSprite();
		int getAttack();
		int getNumber();
		sf::Vector2f getPosition();
		void setPosition(const sf::Vector2f& pos);
		void setName(std::string n);
		std::string getName();
		void setMovement(int m);
		std::vector<sf::Sprite> displayMovement(std::vector<Units> ux);
};

class Ground: public Units {
	protected: 
		bool red;
	public:
		Ground(float x_, float y_, std::vector<sf::Texture>& t, bool r);
		bool getSide();
};

class Infantry: public Ground {
	public:
		Infantry(float x_, float y_, std::vector<sf::Texture>& t, bool r);
		void beginCapture(Building b);
};

class Bazooka: public Ground {
	public:
		Bazooka(float x_, float y_, std::vector<sf::Texture>& t, bool r);
};

class Tank: public Ground {
	public:
		Tank(float x_, float y_, std::vector<sf::Texture>& t, bool r);
};
