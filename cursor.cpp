#include <SFML/Graphics.hpp>
#include "cursor.hpp"

Cursor::Cursor(std::vector<sf::Texture>& t, sf::RenderWindow& s, std::vector<Building>& b, std::vector<Units>& u, std::vector<Units>& se, std::vector<sf::Font>& fs): 
	stats(s), tset(t), buildings(b), units(u), self(se), f(fs){
	cursor.setPosition(0,0);
	cursor.setTexture(t[12]);
	building.setPosition(0, 275);
	unit.setPosition(0, 25);

	sf::Text t1("Unit", f[3], 25);
	sf::Text n1("Type: ", f[3], 25);
	sf::Text h1("Number: ", f[3], 25);
	sf::Text a1("Attack: ", f[3], 25);
	t1.setFillColor(sf::Color::White);
	n1.setFillColor(sf::Color::White);
	h1.setFillColor(sf::Color::White);
	a1.setFillColor(sf::Color::White);
	t1.setPosition(0, 0);
	n1.setPosition(0, 75);
	h1.setPosition(0, 100);
	a1.setPosition(0, 125);
	text.push_back(t1); text.push_back(n1); 
	text.push_back(h1); text.push_back(a1);

	sf::Text t2("Building", f[3], 25);
	sf::Text n2("Type: ", f[3], 25);
	sf::Text h2("Defense: ", f[3], 25);
	sf::Text a2("Captured: ", f[3], 25);
	t2.setFillColor(sf::Color::White);
	n2.setFillColor(sf::Color::White);
	h2.setFillColor(sf::Color::White);
	a2.setFillColor(sf::Color::White);
	t2.setPosition(0, 250);
	n2.setPosition(0, 325);
	h2.setPosition(0, 350);
	a2.setPosition(0, 375);
	text.push_back(t2); text.push_back(n2);
	text.push_back(h2); text.push_back(a2);

	sf::Text s1("Press S to save", f[3], 25);
	sf::Text e("Press Esc to exit", f[3], 25);
	s1.setFillColor(sf::Color::White);
	e.setFillColor(sf::Color::White);
	s1.setPosition(0, 450);
	e.setPosition(0, 475);
	text.push_back(s1); text.push_back(e);
}

sf::Sprite Cursor::getCursor(){return cursor;}

void Cursor::moveCursor(sf::Keyboard::Key x){
	switch(x){
		case sf::Keyboard::Left:
			if((cursor.getPosition().x - 50) < 0) break;
			else {
				cursor.setPosition(cursor.getPosition().x - 50, cursor.getPosition().y);
				break;
			}
		case sf::Keyboard::Right:
			if((cursor.getPosition().x + 50) > 450) break;
			else {
				cursor.setPosition(cursor.getPosition().x + 50, cursor.getPosition().y);
				break;
			}
		case sf::Keyboard::Up:
			if((cursor.getPosition().y - 50) < 0) break;
			else {
				cursor.setPosition(cursor.getPosition().x, cursor.getPosition().y - 50);
				break;
			}
		case sf::Keyboard::Down:
			if((cursor.getPosition().y + 50) > 450) break;
			else {
				cursor.setPosition(cursor.getPosition().x, cursor.getPosition().y + 50);
				break;
			}
		case sf::Keyboard::Space:
			for(auto i = movement.begin(); i != movement.end(); i++){
				if((*i).getPosition() == cursor.getPosition()){
					for(auto m = self.begin(); m != self.end(); m++){
						if((*m).getSprite().getPosition() == movement[0].getPosition()){
							(*m).setPosition(cursor.getPosition());
							movement.clear();
							goto done;
						}
					}
				}
			}
				
			for(auto i = self.begin(); i != self.end(); i++){
				if((*i).getSprite().getPosition() == cursor.getPosition()){
					movement = (*i).displayMovement(units);
				}
			}
			done:
			break;
		case sf::Keyboard::X:
			movement.clear();
			break;
		case sf::Keyboard::S:
			// Save function
			std::cout << "Function currently not available" << std::endl;
			break;
		}
		update();
}

void Cursor::confirm(){
	stats.requestFocus();
	sf::Text wait("Wait", f[3], 25);
	sf::Text capture("Capture", f[3], 25);
	sf::Text attack("Attack", f[3], 25);
}

std::vector<sf::Sprite> Cursor::getMovement(){return movement;}

void Cursor::update(){
	stats.clear();
	for(int i = 0; i < text.size(); i++){
		stats.draw(text[i]);
	}
	for(auto it = units.begin(); it != units.end(); it++){
		if((*it).getSprite().getPosition() == cursor.getPosition()){
			unit.setTexture(*(*it).getSprite().getTexture());
			stats.draw(unit);
			text[1].setString("Type: " + (*it).getName());
			text[2].setString("Number: " + std::to_string((*it).getNumber()));
			text[3].setString("Attack: " + std::to_string((*it).getAttack()));
			stats.draw(text[1]); stats.draw(text[2]); stats.draw(text[3]);
		}
		else{
			text[1].setString("Type: ");
			text[2].setString("Number: ");
			text[3].setString("Attack: ");
			stats.draw(text[1]); stats.draw(text[2]); stats.draw(text[3]);
		}
	}
	for(auto it = self.begin(); it != self.end(); it++){
		if((*it).getSprite().getPosition() == cursor.getPosition()){
			unit.setTexture(*(*it).getSprite().getTexture());
			stats.draw(unit);
			text[1].setString("Type: " + (*it).getName());
			text[2].setString("Number: " + std::to_string((*it).getNumber()));
			text[3].setString("Attack: " + std::to_string((*it).getAttack()));
			stats.draw(text[1]); stats.draw(text[2]); stats.draw(text[3]);
		}
		else{
			text[1].setString("Type: ");
			text[2].setString("Number: ");
			text[3].setString("Attack: ");
			stats.draw(text[1]); stats.draw(text[2]); stats.draw(text[3]);
		}
	}
	for(auto it = buildings.begin(); it != buildings.end(); it++){
		if((*it).getSprite().getPosition() == cursor.getPosition()){
			building.setTexture(*(*it).getSprite().getTexture());
			stats.draw(building);
			text[5].setString("Type: " + (*it).getName());
                        text[6].setString("Defense: " + std::to_string((*it).getDef()));
			text[7].setString("Captured: " + std::to_string((*it).getHP()));
			stats.draw(text[5]); stats.draw(text[6]); stats.draw(text[7]);
		}
		else{
			text[5].setString("Type: ");
			text[6].setString("Defense: ");
			text[7].setString("Captured: ");
			stats.draw(text[5]); stats.draw(text[6]); stats.draw(text[7]);
		}
	}
	stats.display();
}
