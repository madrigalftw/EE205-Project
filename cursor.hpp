#include <SFML/Graphics.hpp>
#include "units.hpp"

class Cursor {
	private:
		sf::Sprite building;
		sf::Sprite unit;
		sf::Sprite cursor;
		std::vector<Units>::iterator ptr;
		sf::Vector2f prev;
		sf::RenderWindow& stats;
		std::vector<sf::Texture>& tset;
		std::vector<Building>& buildings;
		std::vector<Units>& units;
		std::vector<Units>& self;
		std::vector<sf::Font>& f;
		std::vector<sf::Text> text;
		std::vector<sf::Sprite> movement;
	public:
		Cursor(std::vector<sf::Texture>& t, sf::RenderWindow& s, std::vector<Building>& b, std::vector<Units>& u, std::vector<Units>& se, std::vector<sf::Font>& fs);

		sf::Sprite getCursor();

		void moveCursor(sf::Keyboard::Key x);

		void confirm();

		std::vector<sf::Sprite> getMovement();

		void update();
};
