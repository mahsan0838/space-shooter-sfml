#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "menu.h"
#include<cmath>
using namespace std;
#include "player.h"
#include "enemy.h"
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
public:
Sprite background; //Game background sprite
Texture bg_texture;
Player* p; //player 
// add other game attributes
bool monster_reached_right=false;
bool monster_stop=false;
//int LIVES=3;
bool dead=false;


bool dragon_kills=false;
bool monster_kills=false;
int SCORE=0;

int invincible_time;
int fire_addon_time;
int alpha_bomb_check=20;
int beta_bomb_check=20;
int gamma_bomb_check=20;


bool powerup_switch=false;
bool life_switch=false;
bool fire_switch=false;
bool danger_switch=false;

int p_a_x, p_a_y;
int add_x, add_y;
float player_addon_distance;


int bomb_x, bomb_y;
int pxr, pxl,py;
float right_distance, left_distance;
int player_y_up, player_y_down;
float right_D,left_D;
float Monster_D;


int q=0;
enemy ** enemyptr;
enemy * enemy_monsterptr;
enemy * enemy_dragonptr;
int temp;
bool alphas=false;
int dx;
int dy;
bool alpha_bomb=false;
float distance_left;
float distance_right;
////////////////////////

int bullet_pos_x;
int bullet_pos_y;
int enemy_pos_x_right;
int enemy_pos_x_left;
int enemy_pos_y;


int number_of_enemies=9;

Menu M;

//////////

Game()
{
p=new Player("img/player_ship.png");//sending image nto plyer





enemy_dragonptr= new dragon("img/dragon1.png", 150, 0);
enemy_monsterptr= new monster("img/monster1.png", 240, 100);
enemyptr= new enemy*[number_of_enemies];




bg_texture.loadFromFile("img/BG.png");
background.setTexture(bg_texture);
background.setScale(1.5, 1.5);

}
void start_game()
{
    srand(time(0));
    Music sound;
	sound.setVolume(50);
	sound.openFromFile("onlymp3.to-Jocelyn-Flores-_Lofi-Fruits-Release_-bAGaY3f9HOI-256k-1657218689511_1_.wav");
	sound.setLoop(true);
	sound.play();
    RenderWindow window(VideoMode(780, 780), title);
    M.display_front_screen(window, background);
    Clock clock;
    float timer=0;
    ///////////////////////////////////
    float alpha_timer=0;
     float beta_timer=0;
      float gamma_timer=0;
       float dragonTimer = 0; 
    float dragon_fire_time=0.0;
    float monsterTimer=0.0;
    
    int powerup_current_time=40;
    int lives_current_time=40;
    int fire_current_time=40;
    int danger_current_time=40;
    
    float alpha_bomb_drop_interval = 5.0f;
    float beta_bomb_drop_interval = 3.0f;
    float gamma_bomb_drop_interval = 2.0f;
    float dragonInterval = 20.0f; 
    float monsterInterval=10.0f;
  

   ////////////////////////////////////////////////////////////////////  LEVELS IMPLEMENTATION
    bool gameover=false;
    bool newlevel=false;
    int LEVEL=1;
    int wave=1;
    int current_enemies=9;
    /*
    if(LEVEL==1)
    {
    	if(wave==1)
    	{
	    	enemyptr[0]= new alpha("img/enemy_1.png", 340, 10 );
		enemyptr[1]= new alpha("img/enemy_1.png", 240,10 );
		enemyptr[2]= new alpha("img/enemy_1.png", 140,10 );
		enemyptr[3]= new betas("img/enemy_2.png", -100,10 );
		enemyptr[4]= new betas("img/enemy_2.png", 140,110 );
		enemyptr[5]= new betas("img/enemy_2.png", 340,110 );
		enemyptr[6]= new gammas("img/enemy_3.png", 340 ,210 );
		enemyptr[7]= new gammas("img/enemy_3.png", 240 ,210 );
		enemyptr[8]= new gammas("img/enemy_3.png", 140, 210);
    	}
    
    }*/
    
  ////////////////////////////////////////////////////////////////////
    bool dragon=false;
    bool monster=false;
    
    
    //-------------------------------------    
    
    while (window.isOpen())
    {
      srand(time(nullptr));
    // int random_num = rand() % 20 + 10;
     
    
    
        float time = clock.getElapsedTime().asSeconds(); 	  //getElapsedTime() gives time taken for each iteration of this whle loop
        clock.restart();
        timer += time;  
        
        ////////////////////////////////////////
        alpha_timer += time;
        beta_timer += time;    
        gamma_timer += time;  
        dragonTimer+=time;
        monsterTimer+=time;
        ///////////////////////////
        
      	temp=(int)timer;
 	Event e;
        while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game                        	    
        }
          
	if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
            p->move("l");    // Player will move to left
	if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
            p->move("r");  //player will move to right
	if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
            p->move("u");    //playet will move upwards
	if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
            p->move("d");  //player will move downwards
            
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

if(newlevel==false && temp<1)
{						//rectangle
					enemyptr[0]= new alpha("img/enemy_1.png", 340, 10 );
					enemyptr[1]= new alpha("img/enemy_1.png", 240,10 );
					enemyptr[2]= new alpha("img/enemy_1.png", 140,10 );
					enemyptr[3]= new betas("img/enemy_2.png", -100,10 );
					enemyptr[4]= new betas("img/enemy_2.png", 140,110 );
					enemyptr[5]= new betas("img/enemy_2.png", 340,110 );
					enemyptr[6]= new gammas("img/enemy_3.png", 340 ,210 );
					enemyptr[7]= new gammas("img/enemy_3.png", 240 ,210 );
					enemyptr[8]= new gammas("img/enemy_3.png", 140, 210);

}
if(newlevel==true)
{
			if(LEVEL==1)
			{
				if(wave==1)
				{

					wave=2;			// cross
					enemyptr[0]= new alpha("img/enemy_1.png", 340, 10 );
					enemyptr[1]= new alpha("img/enemy_1.png", 240,210 );
					enemyptr[2]= new alpha("img/enemy_1.png", 340,110 );
					enemyptr[3]= new betas("img/enemy_2.png", 140,210 );
					enemyptr[4]= new betas("img/enemy_2.png", 340,210 );
					enemyptr[5]= new betas("img/enemy_2.png", 540,210 );
					enemyptr[6]= new gammas("img/enemy_3.png", 340 ,310 );
					enemyptr[7]= new gammas("img/enemy_3.png", 340 ,410 );
					enemyptr[8]= new gammas("img/enemy_3.png", 440, 210);
					current_enemies=9;
					newlevel=false;
				}
				else if( wave==2 && newlevel==true)
				{

					current_enemies=9;		
					wave=3;
					// tiangle
					enemyptr[0]= new alpha("img/enemy_1.png", 340, 10 );
					enemyptr[1]= new alpha("img/enemy_1.png", 240,110 );
					enemyptr[2]= new alpha("img/enemy_1.png", 440,110 );
					enemyptr[3]= new betas("img/enemy_2.png", 140,210 );
					enemyptr[4]= new betas("img/enemy_2.png", 540,210 );
					enemyptr[5]= new betas("img/enemy_2.png", 40,330 );
					enemyptr[6]= new gammas("img/enemy_3.png", 640 ,350 );
					enemyptr[7]= new gammas("img/enemy_3.png", 240 ,350 );
					enemyptr[8]= new gammas("img/enemy_3.png", 440, 350);
					newlevel=false;
				}
				else if(wave==3 && newlevel==true)
				{
					LEVEL=2;
					wave=1;
					current_enemies=9;	
					// circle
					enemyptr[0]= new alpha("img/enemy_1.png", 340, 10 );
					enemyptr[1]= new alpha("img/enemy_1.png", 240,110 );
					enemyptr[2]= new alpha("img/enemy_1.png", 440,110 );
					enemyptr[3]= new betas("img/enemy_2.png", 560,210 );
					enemyptr[4]= new betas("img/enemy_2.png", 160,210 );
					enemyptr[5]= new betas("img/enemy_2.png", 460,310 );
					enemyptr[6]= new gammas("img/enemy_3.png", 340 ,410 );
					enemyptr[7]= new gammas("img/enemy_3.png", 260 ,310 );
					enemyptr[8]= new gammas("img/enemy_3.png", -100, 10);
					newlevel=false;
				}
			}
			if(LEVEL==2 && newlevel==true)
			{
				if(wave==1 && newlevel==true)
				{
					wave=2;		//diamond
					enemyptr[0]= new alpha("img/enemy_1.png", 340, 10 );
					enemyptr[1]= new alpha("img/enemy_1.png", 240,110 );
					enemyptr[2]= new alpha("img/enemy_1.png", 440,110 );
					enemyptr[3]= new betas("img/enemy_2.png", 140,210 );
					enemyptr[4]= new betas("img/enemy_2.png", 540,210 );
					enemyptr[5]= new betas("img/enemy_2.png", 240,310 );
					enemyptr[6]= new gammas("img/enemy_3.png", 440 ,310 );
					enemyptr[7]= new gammas("img/enemy_3.png", 340 ,410 );
					enemyptr[8]= new gammas("img/enemy_3.png", -100, 10);
					
					current_enemies=9;	
					newlevel=false;
				}
				else if(wave==2 && newlevel==true)
				{		//
					wave=3;
					newlevel=false;
					//heart
					enemyptr[0]= new alpha("img/enemy_1.png", 340, 170 );
					enemyptr[1]= new alpha("img/enemy_1.png", 240,110 );
					enemyptr[2]= new alpha("img/enemy_1.png", 440,110 );
					enemyptr[3]= new betas("img/enemy_2.png", 140,210 );
					enemyptr[4]= new betas("img/enemy_2.png", 540,210 );
					enemyptr[5]= new betas("img/enemy_2.png", 240,310 );
					enemyptr[6]= new gammas("img/enemy_3.png", 440 ,310 );
					enemyptr[7]= new gammas("img/enemy_3.png", 340 ,410 );
					enemyptr[8]= new gammas("img/enemy_3.png", -100, 10);
					
					current_enemies=9;	
					
				}
				else if( wave==3 && newlevel==true)
				{
					LEVEL=3;
					wave=1;
					newlevel=false;			//filled rectangle
					enemyptr[0]= new alpha("img/enemy_1.png", 340, 10 );
					enemyptr[1]= new alpha("img/enemy_1.png", 240,10 );
					enemyptr[2]= new alpha("img/enemy_1.png", 140,10 );
					enemyptr[3]= new betas("img/enemy_2.png", 240,110 );
					enemyptr[4]= new betas("img/enemy_2.png", 140,110 );
					enemyptr[5]= new betas("img/enemy_2.png", 340,110 );
					enemyptr[6]= new gammas("img/enemy_3.png", 340 ,210 );
					enemyptr[7]= new gammas("img/enemy_3.png", 240 ,210 );
					enemyptr[8]= new gammas("img/enemy_3.png", 140, 210);
					current_enemies=9;	
					
				}
			}
			if(LEVEL==3 && newlevel==true)
			{
				if( wave==1 && newlevel==true)
				{
				
					wave=2;
					//filled diamond
					enemyptr[0]= new alpha("img/enemy_1.png", 340, 10 );
					enemyptr[1]= new alpha("img/enemy_1.png", 240,110 );
					enemyptr[2]= new alpha("img/enemy_1.png", 440,110 );
					enemyptr[3]= new betas("img/enemy_2.png", 140,210 );
					enemyptr[4]= new betas("img/enemy_2.png", 540,210 );
					enemyptr[5]= new betas("img/enemy_2.png", 240,310 );
					enemyptr[6]= new gammas("img/enemy_3.png", 440 ,310 );
					enemyptr[7]= new gammas("img/enemy_3.png", 340 ,410 );
					enemyptr[8]= new gammas("img/enemy_3.png", 340, 210);
					current_enemies=9;	
					newlevel=false;
				}
				else if(wave==2 && newlevel==true)
				{
					wave=3;
					// filled tiangle
					enemyptr[0]= new alpha("img/enemy_1.png", 340, 10 );
					enemyptr[1]= new alpha("img/enemy_1.png", 240,110 );
					enemyptr[2]= new alpha("img/enemy_1.png", 440,110 );
					enemyptr[3]= new betas("img/enemy_2.png", 140,210 );
					enemyptr[4]= new betas("img/enemy_2.png", 540,210 );
					enemyptr[5]= new betas("img/enemy_2.png", 40,330 );
					enemyptr[6]= new gammas("img/enemy_3.png", 640 ,350 );
					enemyptr[7]= new gammas("img/enemy_3.png", 340 ,210 );
					enemyptr[8]= new gammas("img/enemy_3.png", 440, 350);
					newlevel=false;
					current_enemies=9;
				}
				else if( wave==3 && newlevel==true)
				{
				current_enemies=9;
					gameover=true;
					newlevel=false;
				}
			}


}

if(current_enemies==1 && wave==1 && LEVEL==1)
{
	newlevel=true;
}

if(current_enemies==1 && wave==1 && LEVEL==2)
{
	newlevel=true;
}

if(current_enemies==1 && wave==3 && LEVEL==2)
{
	newlevel=true;
}


if(current_enemies==1 && wave==2 && LEVEL==2)
{
	newlevel=true;
}
if(current_enemies==1 && wave==1 && LEVEL==3)
{
	newlevel=true;
}

if(current_enemies==0  )
{
	newlevel=true;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////  Call your functions here            ////
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) // SPACEBAR FIRING
		{
			
			p->fire();  
			
    		}
	/////////////////////////////////////////////////////// WRAPPING FIELD
	if(p->sprite.getPosition().x > 740)
	{
		p->sprite.setPosition(0,p->sprite.getPosition().y);
	}
	if(p->sprite.getPosition().x < 0)
	{
		p->sprite.setPosition(740,p->sprite.getPosition().y);
	}
	if(p->sprite.getPosition().y > 740)
	{
		p->sprite.setPosition(p->sprite.getPosition().x, 0);
	}
	if(p->sprite.getPosition().y < 0) 
	{
		p->sprite.setPosition(p->sprite.getPosition().x, 740);
	}
	
////////////////////////////////////////////////////////////	ENEMIES

	
	//////////////////////////////////////////////
	////////setting things on screen/////////////
	window.clear(Color::Black); //clears the screen
	window.draw(background);  // setting background
	window.draw(p->sprite);   // setting player on screen


	
	
//////////////////calling/moving/deleting bullets/////////
// MULTIPLE BULLETS moving and deletion
/*
	 for(int i=0; i<p->Bcounter; i++)
	 {
	  if(p->b!=nullptr)
	  {
        	window.draw(p->b[i].sprite);
          	p->b[i].bmove();       
		if(p->b[i].sprite.getPosition().y<=0)
		{
		//p->b[i].destroy(p->b, i );
			//delete[] p->b[i];
			//p->b[i]=NULL;
		}
       	 }
        }
       */ 
/////////////////////////////////////////////////////// SINGLE BULLET DELETION

	  if(p->b!=nullptr)
	  {
        	window.draw(p->b->sprite);
          	p->b->bmove();       
		if(p->b->sprite.getPosition().y<=0)
		{
		
		 delete p->b;
		 p->b=NULL;
		}
        }
        

///////////////////////////////////////////////////////// DELETION OF SINGLE BULLET AND DESTROYING ENEMY
		for(int i=0; i<number_of_enemies; i++)
		{
			 if(p->b!=nullptr && enemyptr[i]!=nullptr && monster==false && dragon==false)
	  		{
	  			bullet_pos_x=p->b->sprite.getPosition().x;
		bullet_pos_y=p->b->sprite.getPosition().y;
		enemy_pos_x_right=enemyptr[i][0].sprite.getPosition().x+70;
				enemy_pos_x_left=enemyptr[i][0].sprite.getPosition().x;
		enemy_pos_y=enemyptr[i][0].sprite.getPosition().y;
		
		distance_right= sqrt(  (bullet_pos_x-enemy_pos_x_right)*(bullet_pos_x-enemy_pos_x_right) + (bullet_pos_y - enemy_pos_y)*(bullet_pos_y - enemy_pos_y)	   );
		distance_left= sqrt(  (bullet_pos_x-enemy_pos_x_left)*(bullet_pos_x-enemy_pos_x_left) + (bullet_pos_y - enemy_pos_y)*(bullet_pos_y - enemy_pos_y)	   );
		
		if(p->fire_instead_of_bullet==false)
			{
				if(distance_right<40)
				{
						enemyptr[i][0].sprite.setPosition(900,900); 
						--current_enemies;
						if(i<=2 && i>=0) //alpha
						{
							SCORE+=(LEVEL*10);
							
						}
						
						else if(i<=5 && i>=3) //beta
						{
							SCORE+=(LEVEL*20);
							
						}
						
						else if(i<=8 && i>=6) //gamma
						{
							SCORE+=(LEVEL*30);
							
						}
						
						
					if(p->fire_instead_of_bullet==false)
					{	
						 delete p->b;
					 	p->b=NULL; 
					}
				
						break;
				}
				if(distance_left<10)
				{
						enemyptr[i][0].sprite.setPosition(900,900); 
						--current_enemies;
						if(p->fire_instead_of_bullet==false)
						{	
						 delete p->b;
					 	p->b=NULL; 
						}
					
				 	
						break;
				}
			}
				
		else if(p->fire_instead_of_bullet==true)
			{
				if(distance_left<20 || distance_right<20 )
				{
				enemyptr[i][0].sprite.setPosition(900,900); 
					
				--current_enemies; 
				break;	
				}
			}
	  		
	  		
	  		
	       		}
	       
	  	}    
	  	


//////////////////////////////////////////   MAKING ADD-ONS	



if(temp!=0)
{
		////////////////////////////// POWER_UP
		if(temp>powerup_current_time)
		{
			if(p->adptr[0]==NULL)
			{
			p->adptr[0]=new powerup_A;
			}
		}
		if(temp%39==0)
		{
			powerup_switch=true;
		}
		
		if(p->adptr[0]!=NULL && powerup_switch==true)
		{
			powerup_current_time=temp;
		window.draw(p->adptr[0]->sprite);
		p->adptr[0]->move_down();
		
		p_a_x=p->sprite.getPosition().x+20;
		p_a_y=p->sprite.getPosition().y; 
		add_x=p->adptr[0]->sprite.getPosition().x;
		add_y=p->adptr[0]->sprite.getPosition().y;

player_addon_distance=sqrt(  (p_a_x-add_x)*(p_a_x-add_x) + (p_a_y - add_y)*(p_a_y - add_y)	);

			if(player_addon_distance<40)
			{
			
			p->invincible=true;
			// GAIN 7 bullet ABILITY
			p->speed=0.7;
			invincible_time=temp; 
			p->adptr[0]=NULL;
			powerup_switch=false;
			}
		
			else if( p->adptr[0]->sprite.getPosition().y>780 )
			{
				p->adptr[0]=NULL;
				powerup_switch=false;
			}
		}

		//////////////////////////////// LIVES
		if(temp>lives_current_time)
		{
			if(p->adptr[1]==NULL)
			{
				p->adptr[1]=new lives_A;
			}
		}
		if(temp%19==0)
		{
			life_switch=true;
		}
		
		if( life_switch==true && p->adptr[1]!=NULL )
		{
		
		lives_current_time=temp;
		window.draw(p->adptr[1]->sprite);
		p->adptr[1]->move_down();
		p_a_x=p->sprite.getPosition().x+20;
		p_a_y=p->sprite.getPosition().y; 
		add_x=p->adptr[1]->sprite.getPosition().x;
		add_y=p->adptr[1]->sprite.getPosition().y;

player_addon_distance=sqrt(  (p_a_x-add_x)*(p_a_x-add_x) + (p_a_y - add_y)*(p_a_y - add_y)	);

		
		if(player_addon_distance<40)
		{
		(p->LIVES)++;
		cout<<"Current lives are "<<p->LIVES<<endl;
		p->adptr[1]=NULL;
			life_switch=false;
		}

			else if( p->adptr[1]->sprite.getPosition().y>780 )
			{
				p->adptr[1]=NULL;
				life_switch=false;
			}
		}
		
		/////////////////////////////// FIRE
		if(temp>fire_current_time)
		{
			if(p->adptr[2]==NULL)
			{
				p->adptr[2]=new fire_A;		
			}
		}
		if(temp%29==0)
		{
			fire_switch=true;
		}
		
		if(  fire_switch==true && p->adptr[2]!=NULL  )
		{
		
		fire_current_time=temp;
		window.draw(p->adptr[2]->sprite);
		p->adptr[2]->move_down();
		p_a_x=p->sprite.getPosition().x+20;
		p_a_y=p->sprite.getPosition().y; 
		add_x=p->adptr[2]->sprite.getPosition().x;
		add_y=p->adptr[2]->sprite.getPosition().y;

player_addon_distance=sqrt(  (p_a_x-add_x)*(p_a_x-add_x) + (p_a_y - add_y)*(p_a_y - add_y)	);

		if(player_addon_distance<40)
		{
		p->fire_instead_of_bullet=true;
		fire_addon_time=temp;
		p->adptr[2]=NULL;
		fire_switch=false;

		}

			else if( p->adptr[2]->sprite.getPosition().y>780 )
			{
				p->adptr[2]=NULL;
				fire_switch=false;
			}
		}
		/////////////////////////////// DANGER
		if(temp>danger_current_time)
		{
			if(p->adptr[3]==NULL)
			{
				p->adptr[3]=new danger_A;
			}
		}
		if(temp%9==0)
		{
			danger_switch=true;
		}
		if(  danger_switch==true && p->adptr[3]!=NULL )
		{
		danger_current_time=temp;
		window.draw(p->adptr[3]->sprite);
		p->adptr[3]->move_down();
		p_a_x=p->sprite.getPosition().x+20;
		p_a_y=p->sprite.getPosition().y; 
		add_x=p->adptr[3]->sprite.getPosition().x;
		add_y=p->adptr[3]->sprite.getPosition().y;

player_addon_distance=sqrt(  (p_a_x-add_x)*(p_a_x-add_x) + (p_a_y - add_y)*(p_a_y - add_y)	);

		if(player_addon_distance<40)
		{
		(p->LIVES)--;
		p->adptr[3]=NULL;
		danger_switch=false;

		}

			else if( p->adptr[3]->sprite.getPosition().y>780 )
			{
				p->adptr[3]=NULL;
				danger_switch=false;
				SCORE+=5;
			}
		}
		
		
} 	 

//////////////////////	RESETTING ADDON AFTER 5 SECONDS	////////////
if(temp==invincible_time+7 && p->invincible==true )
{
p->speed=0.3;
p->invincible=false;
//    7 BULLET ABILITY LOST
}

if(temp==fire_addon_time+17 && p->fire_instead_of_bullet==true )
{
	p->fire_instead_of_bullet=false;
}




///////////////////////////////////////// DRAWING ALL ENEMIES AND CHECKING ENEMY-PLAYER COLLISION
if( monster==false && dragon==false)
{
	for(int i=0; i<number_of_enemies; i++)
	{
		window.draw(enemyptr[i][0].sprite);
	}
	
	for(int i=0; i<number_of_enemies; i++)
	{
		pxr=p->sprite.getPosition().x+30;
		pxl=p->sprite.getPosition().x;
		player_y_up=p->sprite.getPosition().y; 
		player_y_down=p->sprite.getPosition().y+30; 
						enemy_pos_x_right=enemyptr[i][0].sprite.getPosition().x+70;
						enemy_pos_x_left=enemyptr[i][0].sprite.getPosition().x;
						enemy_pos_y=enemyptr[i][0].sprite.getPosition().y;
						
					right_D=sqrt(  (pxr-enemy_pos_x_right)*(pxr-enemy_pos_x_right) + (player_y_up - enemy_pos_y)*(player_y_up - enemy_pos_y)	);
					left_D=sqrt(  (pxl-enemy_pos_x_left)*(pxl-enemy_pos_x_left) + (player_y_up - enemy_pos_y)*(player_y_up - enemy_pos_y)	);
					
					
				
					if(right_D<40)
					{
						enemyptr[i][0].sprite.setPosition(900,900);  	
						--current_enemies;
						 p->reduce_lives();
				
					}
					else if(left_D<60)
					{
						enemyptr[i][0].sprite.setPosition(900,900);  	
						--current_enemies;
						 p->reduce_lives();
					}
		
	}
	

///////////////////////////////////////////////////////  ALL BOMB DRAWING AND MOVING

for(int i=0; i<number_of_enemies; i++)
	{
		if(enemyptr[i][0].alpha_weapon_ptr!=NULL)
		{
			window.draw(enemyptr[i][0].alpha_weapon_ptr->sprite);
			enemyptr[i][0].alpha_weapon_ptr->bmove();  
		}
		if(enemyptr[i][0].beta_weapon_ptr!=NULL)
		{
			window.draw(enemyptr[i][0].beta_weapon_ptr->sprite);
			enemyptr[i][0].beta_weapon_ptr->bmove();  
		}
		if(enemyptr[i][0].gamma_weapon_ptr!=NULL)
		{
			window.draw(enemyptr[i][0].gamma_weapon_ptr->sprite);
			enemyptr[i][0].gamma_weapon_ptr->bmove();  
		}
	}
//temp++;
	
	
	
///////////////////////////////////////////////////////  ALPHAS BOMB DRAWING AND BOMBING
	
 if (alpha_timer >= alpha_bomb_drop_interval)
 {
    // Drop the bombs here
    
    for(int i=0; i<3; i++)
	{
		enemyptr[i][0].fire(p);
		alpha_bomb_check=temp;
		window.draw(enemyptr[i][0].alpha_weapon_ptr->sprite);
          	enemyptr[i][0].alpha_weapon_ptr->bmove();       
          	
	}
    alpha_timer = 0.0f; // Reset the timer
}
 if(temp<alpha_bomb_check+2 )
 {
 	for(int i=0; i<3; i++)
	{
		if(enemyptr[i][0].alpha_weapon_ptr!=NULL)
		{
				bomb_x=enemyptr[i][0].alpha_weapon_ptr->sprite.getPosition().x;
			bomb_y=enemyptr[i][0].alpha_weapon_ptr->sprite.getPosition().y;
			pxr=p->sprite.getPosition().x+40;
			pxl=p->sprite.getPosition().x;
			py=p->sprite.getPosition().y;			
			right_distance= sqrt(  (bomb_x-pxr)*(bomb_x-pxr) + (bomb_y - py)*(bomb_y - py)	   );
			left_distance= sqrt(  (bomb_x-pxl)*(bomb_x-pxl) + (bomb_y - py)*(bomb_y - py)	   );
					if(enemyptr[i][0].alpha_weapon_ptr->sprite.getPosition().y>780)
					{
						delete enemyptr[i][0].alpha_weapon_ptr;
						 enemyptr[i][0].alpha_weapon_ptr=NULL;
					 }
					else if(right_distance<30)
					{
					 	delete enemyptr[i][0].alpha_weapon_ptr;
						enemyptr[i][0].alpha_weapon_ptr=NULL;
						 p->reduce_lives();	 				
					}
					else if(left_distance<20)
					{
						delete enemyptr[i][0].alpha_weapon_ptr;
						enemyptr[i][0].alpha_weapon_ptr=NULL;
						 p->reduce_lives();		 
					}
		}			
	}
 }



//////////////////////////////////////////////////////////////////// BETAS BOMB DRAWING AND BOMBING


if (beta_timer >= beta_bomb_drop_interval) {
    // Drop the bombs here
    
    for(int i=3; i<6; i++)
	{
		enemyptr[i][0].fire(p);
		beta_bomb_check=temp;
		window.draw(enemyptr[i][0].beta_weapon_ptr->sprite);
          	enemyptr[i][0].beta_weapon_ptr->bmove(); 
	}
    
    
    beta_timer = 0.0f; // Reset the timer
}

if(temp<beta_bomb_check+2)
{
	 for(int i=3; i<6; i++)
	{
		if(enemyptr[i][0].beta_weapon_ptr!=NULL)
		{
		bomb_x=enemyptr[i][0].beta_weapon_ptr->sprite.getPosition().x;
	bomb_y=enemyptr[i][0].beta_weapon_ptr->sprite.getPosition().y;
	pxr=p->sprite.getPosition().x+40;
	pxl=p->sprite.getPosition().x;
	py=p->sprite.getPosition().y;
	
	right_distance= sqrt(  (bomb_x-pxr)*(bomb_x-pxr) + (bomb_y - py)*(bomb_y - py)	   );
	left_distance= sqrt(  (bomb_x-pxl)*(bomb_x-pxl) + (bomb_y - py)*(bomb_y - py)	   );

	
			 if(enemyptr[i][0].beta_weapon_ptr->sprite.getPosition().y>780)
			{
				delete enemyptr[i][0].beta_weapon_ptr;
				 enemyptr[i][0].beta_weapon_ptr=NULL;
			 }
			
			 if(right_distance<30)
			{
			 	delete enemyptr[i][0].beta_weapon_ptr;
				enemyptr[i][0].beta_weapon_ptr=NULL;
				 p->reduce_lives();
			}
			else if(left_distance<20)
			{
				delete enemyptr[i][0].beta_weapon_ptr;
				enemyptr[i][0].beta_weapon_ptr=NULL;
				 p->reduce_lives();
			}
		
		}
	}
}



///////////////////////////// GAMMAS BOMB DRAWING AND BOMBING
	
if (gamma_timer >= gamma_bomb_drop_interval) 
{
    // Drop the bombs here
    for(int i=6; i<number_of_enemies; i++)
	{
		enemyptr[i][0].fire(p);
		gamma_bomb_check=temp;
		window.draw(enemyptr[i][0].gamma_weapon_ptr->sprite);
          	enemyptr[i][0].gamma_weapon_ptr->bmove();       
	}
    gamma_timer = 0.0f; // Reset the timer
}
if(temp<gamma_bomb_check+2)
{
	for(int i=6; i<number_of_enemies; i++)
	{
		if(enemyptr[i][0].gamma_weapon_ptr!=NULL)
		{	
			bomb_x=enemyptr[i][0].gamma_weapon_ptr->sprite.getPosition().x;
			bomb_y=enemyptr[i][0].gamma_weapon_ptr->sprite.getPosition().y;
		pxr=p->sprite.getPosition().x+40;
		pxl=p->sprite.getPosition().x;
		py=p->sprite.getPosition().y;
		
		right_distance= sqrt(  (bomb_x-pxr)*(bomb_x-pxr) + (bomb_y - py)*(bomb_y - py)	   );
		left_distance= sqrt(  (bomb_x-pxl)*(bomb_x-pxl) + (bomb_y - py)*(bomb_y - py)	   );

		  	
		  	
			if(enemyptr[i][0].gamma_weapon_ptr->sprite.getPosition().y>780)
			{
			
			delete enemyptr[i][0].gamma_weapon_ptr;
			enemyptr[i][0].gamma_weapon_ptr=NULL;
			}
			 else if(right_distance<20)
				{
				 	delete enemyptr[i][0].gamma_weapon_ptr;
					enemyptr[i][0].gamma_weapon_ptr=NULL;
					 p->reduce_lives();
				}
				else if(left_distance<20)
				{
					delete enemyptr[i][0].gamma_weapon_ptr;
					enemyptr[i][0].gamma_weapon_ptr=NULL;
					 p->reduce_lives();
				}
		}
	}
}


}
	

/////////////////////////////////////////////////////////////////  DRAWING AND MOVING MONSTER


if(monsterTimer>monsterInterval+7)
{
monsterInterval=rand() % 20+10; 
if(monster_kills==true)
{
p->reduce_lives();

}

	if(monster_kills==false)
	{
		SCORE+=40;
	}
monster_kills=false;
monster=false;
monsterTimer=0;
}


if(temp%7==0)
{
monster_stop=true;
}
else
{
monster_stop=false;
}


if(monsterTimer >= monsterInterval && dragon==false)
{
monster=true;

	window.draw(enemy_monsterptr->sprite);		
						/////// CHECKING PLAYER-MONSTER COLLISION
	pxr=p->sprite.getPosition().x+30;
	player_y_down=p->sprite.getPosition().y+30; 
	enemy_pos_x_right=enemy_monsterptr->sprite.getPosition().x+150;
	enemy_pos_y=enemy_monsterptr->sprite.getPosition().y+150;
						
					Monster_D=sqrt(  (pxr-enemy_pos_x_right)*(pxr-enemy_pos_x_right) + (player_y_down - enemy_pos_y)*(player_y_down - enemy_pos_y)	);
					
					if(Monster_D<100)
					{
						
						monster_kills=true;
					}
	
	
	
	if(monster_stop==false)
	{
		if(enemy_monsterptr->sprite.getPosition().x<580 && monster_reached_right==false)
		{
			enemy_monsterptr->m_rightmove();
		}
		if(enemy_monsterptr->sprite.getPosition().x>=580)
		{
		monster_reached_right=true;
		}
		if(enemy_monsterptr->sprite.getPosition().x>-130 && monster_reached_right==true)
		{
			enemy_monsterptr->m_leftmove();
		}
		if(enemy_monsterptr->sprite.getPosition().x<=-130)
		{
			monster_reached_right=false;
		}
	}	
	if(monster_stop==true)
	{
		enemy_monsterptr->fire(p);
		window.draw(enemy_monsterptr->weapon_ptr->sprite);
		enemy_monsterptr->weapon_ptr->bmove();
		if(p->sprite.getPosition().x>=enemy_monsterptr->sprite.getPosition().x +80 && p->sprite.getPosition().x<=enemy_monsterptr->sprite.getPosition().x +200 && p->sprite.getPosition().y>=enemy_monsterptr->sprite.getPosition().y +200  )
		{
			
			monster_kills=true;
		}
	}
}



/////////////////////////////// DRAWING AND FIRING DRAGON AND CHECKING PLAYER-DRAGON COLLISION


if(dragonTimer>dragonInterval+7)
{
dragonInterval=rand() % 11 +30; 
dragon=false;
if(dragon_kills==true)
{
p->reduce_lives();

}
	if(dragon_kills==false)
	{
	SCORE+=50;
	}
	dragon_kills=false;
dragonTimer=0;
}


if(dragonTimer >= dragonInterval && monster==false)
{
dragon=true;
	window.draw(enemy_dragonptr->sprite);
	pxr=p->sprite.getPosition().x+30;
	player_y_down=p->sprite.getPosition().y+30; 
	enemy_pos_x_right=enemy_dragonptr->sprite.getPosition().x+270;
	enemy_pos_y=enemy_dragonptr->sprite.getPosition().y+270;
						
	Monster_D=sqrt(  (pxr-enemy_pos_x_right)*(pxr-enemy_pos_x_right) + (player_y_down - enemy_pos_y)*(player_y_down - enemy_pos_y)	);
					
					if(Monster_D<100)
					{
						
						dragon_kills=true;
					}
	if(temp%3==0)
	{
	dragon_fire_time+=0.002;
		q=(int)p->sprite.getPosition().x;
			if(q>260 && q<430)
			{
				enemy_dragonptr->mid_fire();
				window.draw(enemy_dragonptr->weapon_ptr->sprite);
				if(p->sprite.getPosition().x>260 && p->sprite.getPosition().x<430 && p->sprite.getPosition().y>450)
				{
					
					
					dragon_kills=true;
				}
			}
			if(q<260)
			{
				enemy_dragonptr->left_fire();
				window.draw(enemy_dragonptr->weapon_ptr->sprite);
				if(p->sprite.getPosition().x<260 && p->sprite.getPosition().y>500)
				{
				
					
					dragon_kills=true;
				}
			}
			if(q>430)
			{
				enemy_dragonptr->right_fire();
				window.draw(enemy_dragonptr->weapon_ptr->sprite);
				if(p->sprite.getPosition().x>430 && p->sprite.getPosition().y>500)
				{
					
					
					dragon_kills=true;
				}
			}
			
	}		
	
	
}




if(gameover==true || p->LIVES==0)
{
break;
}



	window.display();  //Displying all the sprites
    }
cout<<"Game ended"<<endl;
cout<<"YOUR SCORE IS "<<SCORE;
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




