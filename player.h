#include <SFML/Graphics.hpp>
#include<string.h>
#include "bullet.h"
#include "add_ons.h"
using namespace std;
#include<iostream>
using namespace sf;
class Player{
public:
bullet *b;
add_ons **adptr;
Texture tex; //is image u use, only image no display
Sprite sprite;	// to display image
float speed=0.3;	//0.5 causes to move quicker
int x,y;		//player coordinates
int Bcounter;
int LIVES=3;

bool invincible=false;
bool fire_instead_of_bullet=false;

Player(std::string png_path)
{
adptr= new add_ons*[4];

adptr[0]=new powerup_A;
adptr[1]=new lives_A;
adptr[2]=new fire_A;
adptr[3]=new danger_A;




tex.loadFromFile(png_path);	//loadfrom file. image path
sprite.setTexture(tex);		//we display tex, to load image
x=340;y=700;			//starting cordinates for player
sprite.setPosition(x,y);	//packs two components, has float type (maybe changed with new file)
sprite.setScale(0.75,0.75);	// image size is set
b=nullptr;
Bcounter=0;
}
void fire()
{


	if(b==nullptr)
	{
		if(fire_instead_of_bullet==true)
		{
		b=new bullet("img/PNG/Lasers/fireball.png",this->sprite.getPosition().x,this->sprite.getPosition().y,0.03,0.03);
		}
	else if(fire_instead_of_bullet==false)
	{
	b=new bullet("img/PNG/Lasers/laserBlue12.png",this->sprite.getPosition().x+35,this->sprite.getPosition().y, 0.75,0.75);
	}
		this->Bcounter++;
	}
	else
	{
	/*
	//this->Bcounter++;
	bullet* temp = new bullet[Bcounter + 1]; // Create a new array with one more bullet
        for (int i = 0; i < Bcounter; i++)
        {
            temp[i] = b[i]; // Copy the old bullets to the new array
        }
      temp[Bcounter] = bullet("img/PNG/Lasers/laserBlue07.png", this->sprite.getPosition().x + 35, this->sprite.getPosition().y); // Add the new bullet to the new array
        Bcounter++;
     // delete[] b; // Delete the old array
        b = temp; // Set the bullet array to the new array
*/
	}

}
void move(std::string s){
float delta_x=0,delta_y=0;
if(s=="l")
	delta_x=-1;//move the player left
else if(s=="r")
	delta_x=1;//move the player right
if(s=="u")
	delta_y=-1;
else if(s=="d")
	delta_y=1;

delta_x*=speed;
delta_y*=speed;

//cout<<sprite.getPosition().x<<"  "<<sprite.getPosition().y<<endl;
sprite.move(delta_x, delta_y);
}


void reduce_lives()
{
if(invincible==false && LIVES>0)
	{
	--(this->LIVES);
	//cout<<"LIVES REMAINING: "<<LIVES<<endl;
	}
}

void addon()
{

}



~Player() {
    delete[] b;
    cout<<"woooooo";
}
};
