#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
using namespace std;
#include<iostream>

class bullet{
public:

Texture tex; //is image u use, only image no display
Sprite sprite; // to display image
float speed=0.2;   //0.5 causes to move quicker
int x,y;     //bullet coordinates


bullet()
{
tex.loadFromFile("img/PNG/Lasers/laserBlue07.png");
sprite.setTexture(tex);
}


bullet(string png_path,int player_x, int player_y, float scale_x, float scale_y)
{

tex.loadFromFile(png_path); //loadfrom file. image path
sprite.setTexture(tex);		//we display tex, to load image


this->x=player_x;
this->y=player_y;

sprite.setPosition(x,y); 
sprite.setScale(scale_x,scale_y);	// image size is set
}

void bmove()
{
//cout<<y<<endl;

 y -= (speed)*20; 
sprite.setPosition(x, y);

}


bullet & operator=(const bullet & bul)
{
 if (this != &bul) {
	x=bul.x;
	y=bul.y;
	this->tex.loadFromFile("img/PNG/Lasers/laserBlue07.png");

	}
return *this;
}

~bullet()
{
//delete b[];
}

void destroy(bullet *b, int index)
{
delete &b[index];
}



};
