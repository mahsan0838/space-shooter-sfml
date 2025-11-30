
#include <SFML/Graphics.hpp>
using namespace sf;
class Menu{
public:

//add menu attributes here
Menu()
{
// menu components to be initialized here
//constructors body
}



   void display_front_screen( sf::RenderWindow& window, sf::Sprite& background)
{
	Texture front_screen_texture;
	front_screen_texture.loadFromFile("img/PLAY.png");
	Sprite front;
	front.setTexture(front_screen_texture);
	front.setPosition(1.5,1.5);
	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{  
		    if (e.type == Event::Closed) // If cross/close is clicked/pressed
		        window.close(); //close the game                        	    
		}
		  
		if (Keyboard::isKeyPressed(Keyboard:: P))
		{	
			return;
		}
		
		window.draw(background);
		window.draw(front);
		window.display();
	}

}




};
