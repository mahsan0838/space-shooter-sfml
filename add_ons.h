#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;
using namespace std;
#include<iostream>

class add_ons{
public:
Texture tex; //is image u use, only image no display
Sprite sprite; // to display image
float speed=0.1;   //0.5 causes to move quicker
float x,y;     //bullet coordinates

virtual void move_down()
{
}

};


class powerup_A: public add_ons
{
public:

powerup_A()
{
 srand(time(0)); 
       x=rand() % (700 - 50 + 1) + 50;
	y=10;
	tex.loadFromFile("img/PNG/Power-ups/bolt_gold.png");
	sprite.setTexture(tex);
	sprite.setPosition(x,y);
	sprite.setScale(2, 2);

}
void move_down()
{

y+=1.1*speed;
sprite.setPosition(x, y);

}


};


class lives_A: public add_ons
{
public:
lives_A()
{
 srand(time(0)); 
       x=rand() % (700 - 50 + 1) + 50;
	y=10;
	tex.loadFromFile("img/PNG/Power-ups/H2.png");
	sprite.setTexture(tex);
	sprite.setPosition(x,y);
	sprite.setScale(0.3, 0.3);

}
void move_down()
{

y+=1.1*speed;
sprite.setPosition(x, y);

}

};


class fire_A: public add_ons
{
public:
fire_A()
{
 srand(time(0)); 
       x=rand() % (700 - 50 + 1) + 50;
	y=10;
	tex.loadFromFile("img/PNG/Power-ups/fire.png");
	sprite.setTexture(tex);
	sprite.setPosition(x,y);
	sprite.setScale(0.4, 0.4);

}
void move_down()
{

y+=1.1*speed;
sprite.setPosition(x, y);

}
};


class danger_A: public add_ons
{
public:
danger_A()
{
srand(time(0)); 
       x=rand() % (700 - 50 + 1) + 50;
	y=10;
	tex.loadFromFile("img/PNG/Power-ups/danger.png");
	sprite.setTexture(tex);
	sprite.setPosition(x,y);
	sprite.setScale(0.3, 0.3);

}
void move_down()
{

y+=1.1*speed;
sprite.setPosition(x, y);

}
};




