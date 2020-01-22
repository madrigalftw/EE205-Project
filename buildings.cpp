#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "utility.hpp"

class Terrain {
	protected:
		sf::Sprite terrain;
		int defense;
		sf::Vector2f position;
		std::vector<sf::Texture>& tset;
		std::string name;
	public:
		Terrain(float x_, float y_, std::vector<sf::Texture>& t): 
			tset(t){
			position.x = 50*x_;
			position.y = 50*y_;
			terrain.setPosition(position);	
		}
		sf::Sprite getSprite(){return terrain;}
		int getDef(){return defense;}
		std::string getName(){return name;}
		void setName(std::string n){name = n;}
};

class Building: public Terrain {
	protected: 
		bool red;
		int income;
		int hp;
	public:
		Building(float x_, float y_, std::vector<sf::Texture>& t, bool r): 
			Terrain(x_, y_, t), red(r), hp(20){}
		bool getSide(){return red;}
		virtual void changeSide(){red = !red;}
		int getIncome(){return income;}
		void setHP(int h){hp = h;}
		int getHP(){return hp;}
		void interact(){	
		}
};

class HQ: public Building {
	private:
		bool captured;
	public:
		HQ(float x_, float y_, std::vector<sf::Texture>& t, bool r):
			Building(x_, y_, t, r){
			defense = 10;
			income = 5;
			captured = 0;
			if(r) terrain.setTexture(t[6]);
			else terrain.setTexture(t[7]);
			setName("HQ");
		}
		bool getCaptured(){return captured;}
		void setCaptured(){captured = 1;}
		virtual void changeSide(){
			red = !red;
			if(red) terrain.setTexture(tset[6]);
			else terrain.setTexture(tset[7]);
		}
};

class Town: public Building {
	public:
		Town(float x_, float y_, std::vector<sf::Texture>& t, bool r):
			Building(x_, y_, t, r){
			defense = 10;
			income = 5;
			if(r) terrain.setTexture(t[10]);
			else terrain.setTexture(t[11]);
			setName("Town");
		}
		virtual void changeSide(){
			red = !red;
			if(red) terrain.setTexture(tset[10]);
			else terrain.setTexture(tset[11]);
		}
};

class Industry: public Building {
	private:
		std::vector<sf::Sprite> units;
	public:
		Industry(float x_, float y_, std::vector<sf::Texture>& t, bool r):
	                Building(x_, y_, t, r){
			defense = 10;
			income = 0;
			if(r) terrain.setTexture(t[8]);
			else terrain.setTexture(t[9]);
			setName("Industry");
		}
		virtual void changeSide(){
			red = !red;
			if(red) terrain.setTexture(tset[8]);
			else terrain.setTexture(tset[9]);
		}
		sf::Sprite buildUnit(std::string n){
			
		}
};
