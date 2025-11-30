#include <SFML/Graphics.hpp>
#include "bomb.h"
//#include "monster.h"
#include<string.h>
#include<iostream>
using namespace sf;
using namespace std;
class enemy
{
public:
bomb * alpha_weapon_ptr=NULL;
bomb * beta_weapon_ptr=NULL;
bomb * gamma_weapon_ptr=NULL;
bomb * weapon_ptr=NULL;

	Sprite sprite;
	Texture tex;
	float x;
	float y;
virtual void m_rightmove()
{
}

virtual void m_leftmove()
{
}

virtual void fire(Player * playerptr=NULL)=0;	

virtual void left_fire()
{
}
virtual void mid_fire()
{
}
virtual void right_fire()
{
}


};
class INVADERS:public enemy
{
public:

void fire(Player * playerptr=NULL)
{
if(alpha_weapon_ptr==NULL)
	{
	weapon_ptr= new bomb("img/PNG/Lasers/laserRed08.png",this->sprite.getPosition().x+35,this->sprite.getPosition().y);
		
	}

}

};
class alpha:public INVADERS
{
public:

alpha()
{
	x=340;
	y=10;
	tex.loadFromFile("img/enemy_1.png");
	sprite.setTexture(tex);
	sprite.setPosition(x,y);
	sprite.setScale(0.75, 0.75);
	//sprite.setScale(0.3, 0.3);
}
alpha( string png_path, int loc_x, int loc_y)
{
	tex.loadFromFile(png_path);
	sprite.setTexture(tex);
	x=loc_x;
	y=loc_y;
	sprite.setPosition(x,y);
	sprite.setScale(0.75, 0.75);
}


void fire(Player * playerptr=NULL)
{
	if(alpha_weapon_ptr==NULL)
	{
	alpha_weapon_ptr= new bomb("img/PNG/Lasers/laserRed08.png",this->sprite.getPosition().x+35,this->sprite.getPosition().y);
		
	}

}

};

class betas:public INVADERS
{
public:
betas()
{
	x=440;
	y=10;
	tex.loadFromFile("img/enemy_2.png");
	sprite.setTexture(tex);
	sprite.setPosition(x,y);
	sprite.setScale(0.75, 0.75);
}
betas( string png_path, int loc_x, int loc_y)
{
	tex.loadFromFile(png_path);
	sprite.setTexture(tex);
	x=loc_x;
	y=loc_y;
	sprite.setPosition(x,y);
	sprite.setScale(0.75, 0.75);
}
void fire(Player * playerptr=NULL)
{
	if(beta_weapon_ptr==NULL)
	{
	beta_weapon_ptr= new bomb("img/PNG/Lasers/laserRed08.png",this->sprite.getPosition().x+35,this->sprite.getPosition().y);
		
	}

}


};

class gammas:public INVADERS
{
public:
gammas()
{
	x=240;
	y=10;
	tex.loadFromFile("img/enemy_2.png");
	sprite.setTexture(tex);
	sprite.setPosition(x,y);
	sprite.setScale(0.75, 0.75);
}
gammas( string png_path, int loc_x, int loc_y)
{
	tex.loadFromFile(png_path);
	sprite.setTexture(tex);
	x=loc_x;
	y=loc_y;
	sprite.setPosition(x,y);
	sprite.setScale(0.6, 0.6);
}

void fire(Player * playerptr=NULL)
{
	if(gamma_weapon_ptr==NULL)
	{
	gamma_weapon_ptr= new bomb("img/PNG/Lasers/laserRed08.png",this->sprite.getPosition().x+35,this->sprite.getPosition().y);
		
	}

}


};

class monster: public enemy
{
public:
float monster_speed=0.1;

monster()
{
tex.loadFromFile("img/monster1.png");
sprite.setTexture(tex);
}

monster(string png_path,int monster_x, int monster_y)
{
tex.loadFromFile("img/monster1.png");
sprite.setTexture(tex);

this->x=monster_x;
this->y=monster_y;

sprite.setPosition(x,y); 
sprite.setScale(0.5, 0.5);	// image size is set
}


void m_rightmove()
{
x+=0.2;
sprite.setPosition(x, y);
}

void m_leftmove()
{
x-=0.2;
sprite.setPosition(x, y);
}

void fire(Player * playerptr=NULL)
{
	if(weapon_ptr!=NULL)
	{
	weapon_ptr=NULL;
	}
	if(1)
	{
	weapon_ptr= new bomb("img/PNG/Lasers/laserGreen02.png",this->sprite.getPosition().x+135,this->sprite.getPosition().y+250, 5, 20);
		
	}



}

};


class dragon: public enemy
{
public:


dragon()
{
tex.loadFromFile("img/dragon1.png");
sprite.setTexture(tex);
}

dragon(string png_path,int dragon_x, int dragon_y)
{

tex.loadFromFile("img/dragon1.png");
sprite.setTexture(tex);

this->x=dragon_x;
this->y=dragon_y;

sprite.setPosition(x,y); 
sprite.setScale(2, 2);	// image size is set

}

void left_fire()
 {
 
weapon_ptr= new bomb("img/PNG/left_fire.png",-190,260, 1.9, 1.9);
	return;
 }
 void mid_fire()
 {
 
	weapon_ptr= new bomb("img/PNG/down_fire.png",80,440, 2.3, 1.3);
	return;
 }
 
 void right_fire()
 {
 
	weapon_ptr= new bomb("img/PNG/right_fire.png",190,240, 1.9, 1.9);
	return; 
 }

void fire(Player * playerptr)
{
//cout<<"yoohooo"<<endl;

if(weapon_ptr==NULL)
{
cout<<playerptr->sprite.getPosition().x<<endl;
int player_position=playerptr->sprite.getPosition().x;
	if(player_position > 260 && player_position <520 )
	{
	weapon_ptr= new bomb("img/PNG/down_fire.png",215,450, 1.3, 1.3);
	return;
	}
	if(player_position < 260 )
	{
	weapon_ptr= new bomb("img/PNG/left_fire.png",-190,260, 1.9, 1.9);
	return;
	}
	if(player_position > 520 )
	{
	weapon_ptr= new bomb("img/PNG/right_fire.png",190,240, 1.9, 1.9);
	return;
	}

}


}

};
































