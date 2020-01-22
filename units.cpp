#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include "units.hpp"

Units::Units(float x_, float y_, std::vector<sf::Texture>& t): 
	x(x_), y(y_), tset(t){
	position.x = 50*x_; position.y = 50*y_;
	unit.setPosition(position);
}

sf::Sprite Units::getSprite(){return unit;}

int Units::getAttack(){return attack;}

int Units::getNumber(){return number;}

sf::Vector2f Units::getPosition(){return position;}

void Units::setPosition(const sf::Vector2f& pos){
	unit.setPosition(pos);
	position.x = pos.x;
	position.y = pos.y;
}

void Units::setName(std::string n){name = n;}

std::string Units::getName(){return name;}

void Units::setMovement(int m){movement = m;}

std::vector<sf::Sprite> Units::displayMovement(std::vector<Units> ux){
	int n = movement; int k = movement - 1;
	std::vector<sf::Sprite> move;
	sf::Sprite m;
	m.setTexture(tset[13]);

	m.setPosition(position.x, position.y);
	move.push_back(m);

	for(int i = 0; i <= movement; i++){
		for(int j = n; j >= 0; j--){
			if((position.x + i*50) > 450){}
			else if(j == 0){
				m.setPosition(position.x + i*50, position.y);
				move.push_back(m);
			}
			else{
				if((position.y + j*50) > 450){}
				else{
					m.setPosition(position.x + i*50, position.y + j*50);
					move.push_back(m);
				}
				if((position.y - j*50) < 0) {}
				else{
					m.setPosition(position.x + i*50, position.y - j*50);
					move.push_back(m);
				}
			}
		}
		n--;
	}
	for(int i = 1; i <= movement; i++){
		for(int j = k; j >= 0; j--){
			if((position.x - i*50) < 0){}
			else if(j == 0){
				m.setPosition(position.x - i*50, position.y);
				move.push_back(m);
			}
			else{
				if((position.y + j*50) > 450){}
				else{
					m.setPosition(position.x - i*50, position.y + j*50);
					move.push_back(m);
				}
				if((position.y - j*50) < 0) {}
				else{
					m.setPosition(position.x - i*50, position.y - j*50);
					move.push_back(m);
				}
			}
		}
		k--;
	}
	return move;
}

Ground::Ground(float x_, float y_, std::vector<sf::Texture>& t, bool r): 
	Units(x_, y_, t), red(r){}

bool Ground::getSide(){return red;}

Infantry::Infantry(float x_, float y_, std::vector<sf::Texture>& t, bool r):
	Ground(x_, y_, t, r){
	hp = 5;
	number = 10;
	attack = 10;
	setMovement(5);
	if(r) unit.setTexture(t[0]);
	else unit.setTexture(t[1]);
	setName("Infantry");
}
void Infantry::beginCapture(Building b){
	if(!b.getHP()){
		int difference = b.getHP() - number;
		b.setHP(difference);
	}
	else{
		b.changeSide();
	}
}

Bazooka::Bazooka(float x_, float y_, std::vector<sf::Texture>& t, bool r):
	Ground(x_, y_, t, r){
	hp = 10;
	number = 2;
	attack = 15;
	setMovement(2);
	if(r) unit.setTexture(t[2]);
	else unit.setTexture(t[3]);
	setName("Bazooka");
}

Tank::Tank(float x_, float y_, std::vector<sf::Texture>& t, bool r):
	Ground(x_, y_, t, r){
	hp = 50;
	number = 1;
	attack = 30;
	setMovement(7);
	if(r) unit.setTexture(t[4]);
	else unit.setTexture(t[5]);
	setName("Tank");
}
