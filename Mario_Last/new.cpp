#include"new.h"
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
nnn::nnn()
{
    sf::RenderWindow window( sf::VideoMode( 1024, 622 ), "Survival Game", sf::Style::Default );

  sf::Texture background;
  sf::Sprite backgroundImage;

 // if ( !background.loadFromFile( "Alaskan Wilderness.png" ) )
  //  std::cout << "Error: Could not display Alaskan Wilderness image" << std::endl;

  backgroundImage.setTexture( background );

  sf::Font font;
  if ( !font.loadFromFile( "MAGNETOB.TTF" ) )
    cout << "Can't find the font file" << std::endl;

  sf::Texture exitButton;
  sf::Sprite exitButtonImage;
  if ( !exitButton.loadFromFile( "Exit Button.png" ) )
    cout << "Can't find the image" << std::endl;
  exitButtonImage.setPosition( 50.0f, 500.0f );

  float exitButtonWidth = exitButtonImage.getLocalBounds().width;
  float exitButtonHeight = exitButtonImage.getLocalBounds().height;

  exitButtonImage.setTexture( exitButton );

  sf::Text startText;
  startText.setFont( font );
  startText.setStyle( sf::Text::Bold );
  startText.setString( "Create New Game" );
  startText.setFillColor( sf::Color::Black );
  startText.setCharacterSize( 48 );
  startText.setPosition( 50.0f, 320.0f );
  sf::Text loadText;
  loadText.setFont( font );
  loadText.setStyle( sf::Text::Bold );
  loadText.setString( "Load Game" );
  loadText.setFillColor( sf::Color::Black );
  loadText.setCharacterSize( 48 );
  loadText.setPosition( 50.0f, 380.0f );
  sf::Text settingsText;
  settingsText.setFont( font );
  settingsText.setStyle( sf::Text::Bold );
  settingsText.setString( "Settings" );
  settingsText.setFillColor( sf::Color::Black );
  settingsText.setCharacterSize( 48 );
  settingsText.setPosition( 50.0f, 440.0f );

  while ( window.isOpen() )
  {
    sf::Event Event;
    while ( window.pollEvent( Event ) )
    {
      switch ( Event.type )
      {
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::MouseMoved:
        {
          sf::Vector2i mousePos = sf::Mouse::getPosition( window );
          sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
          if ( exitButtonImage.getGlobalBounds().contains( mousePosF ) )
          {
            exitButtonImage.setColor( sf::Color( 250, 20, 20 ) );
          }
          else
          {
            exitButtonImage.setColor( sf::Color( 255, 255, 255 ) );
          }
        }
        break;
      case sf::Event::MouseButtonPressed:
        {
          sf::Vector2i mousePos = sf::Mouse::getPosition( window );
          sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
          if ( exitButtonImage.getGlobalBounds().contains( mousePosF ) )
          {
            std::cout << "Clicked, yay!" << std::endl;
          }
        }
        break;
      }
    }

    window.clear();
    window.draw( backgroundImage );
    window.draw( exitButtonImage );
    window.draw( startText );
    window.draw( loadText );
    window.draw( settingsText );
    window.display();
  }
}
