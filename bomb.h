#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
using namespace std;
#include<iostream>

class bomb{
public:

Texture tex; //is image u use, only image no display
Sprite sprite; // to display image
float speed=1;   //0.5 causes to move quicker
float x,y;     //bullet coordinates


bomb()
{
tex.loadFromFile("img/PNG/Lasers/laserRed08.png");
sprite.setTexture(tex);
}


bomb(string png_path,int player_x, int player_y, float scale_x=0.75, float scale_y=0.75)
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

 y += (speed)*0.3; 
sprite.setPosition(x, y);

}




~bomb()
{
//delete b[];
}




};
