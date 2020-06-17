#include "Win.h"
#include <SFML/Graphics.hpp>
#include<iostream>
#include"Level2.h"
#include"new.h"
#include"Level3.h"
#include"Level4.h"
#include"menu.h"
using namespace std;
Win::Win()
{
}
bool Win::winGame(sf::Sprite mario,int ground,sf::RenderWindow& window_now,int& active_window,int position)
{
    if(mario.getPosition().x==position)
    {
        window_now.close();
        if(active_window==1)
        {
            Level2 open;

        }
        else if(active_window==2)
        {
            Level4 open;
             if(!buffer_win.loadFromFile("smb3_enter_level.wav"))
            {
                cout<<"Not Found"<<endl;
            }
            sound_win.setBuffer(buffer_win);
            sound_win.play();
        }

        return true;
    }
    else
    return false;
}
Win::~Win()
{
    //dtor
}
