#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "AWX.hpp"

AdvanceWarX::AdvanceWarX(std::string n, sf::RenderWindow& w_, sf::Event e, std::vector<sf::Font> fs, std::vector<sf::Texture> s): IGame(n, w_, e, fs), tset(s){}

void AdvanceWarX::run(){
	sf::Vector2i v(0,50);
	window.setPosition(v);
	sf::RenderWindow stats(sf::VideoMode(250,500), "Stats");
	v.x = v.x + 505;
	stats.setPosition(v);
	makeLevel();
	Cursor c(tset, stats, buildings, units, self, f);		
	window.requestFocus();
	while(!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
		window.clear();
		window.draw(map);
		c.update();
		for(auto i = buildings.begin(); i != buildings.end(); i++){
			window.draw((*i).getSprite());
		}
		for(auto x = units.begin(); x != units.end(); x++){
			window.draw((*x).getSprite());
		}
		for(auto l = self.begin(); l != self.end(); l++){
			window.draw((*l).getSprite());
		}
		window.requestFocus();
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
				exit(1);
			}

			if(event.type == sf::Event::KeyPressed){
				c.moveCursor(event.key.code);
			}
		}
				
		if(c.getMovement().size() != 0){
			std::vector<sf::Sprite> dis = c.getMovement();
			for(int i = 0; i < dis.size(); i++){
				window.draw(dis[i]);
			}
		}
		window.draw(c.getCursor());
		window.display();
	}

	units.clear();
	self.clear();
	buildings.clear();
}
		
void AdvanceWarX::load(){}

void AdvanceWarX::display(){
	sf::Text txt1("Advance War X", f[1], 25);
	sf::Text txt2("New Game", f[1], 25);
	sf::Text txt3("Load", f[1], 25);
	sf::Text txt4("Return to main menu", f[1], 25);
	sf::Text txt5("", f[1], 25);
	txt1.setFillColor(sf::Color::Red);
	txt2.setFillColor(sf::Color::White);
	txt3.setFillColor(sf::Color::White);
	txt4.setFillColor(sf::Color::White);
	txt5.setFillColor(sf::Color::White);
	txt1.setPosition(150,0);
	txt2.setPosition(0,50);
	txt3.setPosition(0,75);
	txt4.setPosition(0,100);
	txt5.setPosition(0,450);

	sf::Vector2f mouse(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
	while(window.pollEvent(event)){
		if(event.type == sf::Event::Closed){
			window.close();
			exit(1);
		}
	}
	
	window.clear();
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		if(txt2.getGlobalBounds().contains(mouse)){
			run();
		}
		else if(txt3.getGlobalBounds().contains(mouse)){
			load();
			txt5.setString("Function currently not available");
		}
		else if(txt4.getGlobalBounds().contains(mouse)){
		       back = 1;
		}
	}

	window.draw(txt1);
	window.draw(txt2);
	window.draw(txt3);
	window.draw(txt4);
	window.draw(txt5);
	window.display();
}

void AdvanceWarX::makeLevel(){
	const int level[] =
	{
		0, 0, 0, 0, 7, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
		0, 7, 0, 0, 0, 0, 7, 0, 0, 0,
		0, 0, 0, 7, 0, 0, 0, 7, 0, 0,
		0, 0, 0, 7, 0, 0, 0, 0, 0, 0,
		7, 0, 0, 0, 0, 0, 7, 0, 0, 7,
		0, 0, 7, 0, 0, 0, 0, 0, 7, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 7, 0, 0,
		0, 0, 0, 0, 7, 0, 0, 0, 0, 0
	};

	map.load("Map/tileset.png", sf::Vector2u(50,50), level, 10, 10);

	HQ r(1, 8, tset, 1);
	HQ b(8, 1, tset, 0);
	buildings.push_back(r); buildings.push_back(b);
	Industry ir1(1, 7, tset, 1);
	Industry ir2(2, 8, tset, 1);
	Industry ib1(7, 1, tset, 0);
	Industry ib2(8, 2, tset, 0);
	buildings.push_back(ir1); buildings.push_back(ir2);
	buildings.push_back(ib1); buildings.push_back(ib2);
	Town tr1(2, 4, tset, 1);
	Town tr2(4, 7, tset, 1);
	Town tr3(6, 0, tset, 1);
	Town tb1(5, 2, tset, 0);
	Town tb2(7, 5, tset, 0);
	Town tb3(3, 9, tset, 0);
	buildings.push_back(tr1); buildings.push_back(tr2); buildings.push_back(tr3);
	buildings.push_back(tb1); buildings.push_back(tb2); buildings.push_back(tb3);

	Infantry inb0(4, 2, tset, 0);
	Infantry inb1(3, 5, tset, 0);
	Infantry inb2(6, 7, tset, 0);
	Infantry inb3(7, 6, tset, 0);
	Infantry inb4(1, 1, tset, 0);
	Bazooka bzb1(7, 1, tset, 0);
	Bazooka bzb2(8, 2, tset, 0);
	Tank tanb1(8, 1, tset, 0);
	units.push_back(inb0); units.push_back(inb1); 
	units.push_back(inb2); units.push_back(inb3);
	units.push_back(inb4);
	units.push_back(bzb1); units.push_back(bzb2);
	units.push_back(tanb1);

	Infantry inr0(1, 7, tset, 1);
	self.push_back(inr0);
}
