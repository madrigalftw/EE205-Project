#include <SFML/Graphics.hpp>

class Tilemap : public sf::Drawable, public sf::Transformable
{
	public:
		bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, 
				unsigned int width, unsigned int height);
	private: 
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
	        	states.transform *= getTransform();
		        states.texture = &m_tileset;
			target.draw(m_vertices, states);
		}
		sf::VertexArray m_vertices;
		sf::Texture m_tileset;
};
