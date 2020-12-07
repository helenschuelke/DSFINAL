#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "Menu.h"
#include "AVL.h";
#include "Graph.h"
#include "Data.h"


using namespace std;


int main()
{
	const int windowX = 1300;
	const int windowY = 900;
	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "JINGLE JUNKIES");

	Menu m(&window);

	m.Initialize();

	sf::String playerInput;
	
	
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{


			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::TextEntered) {
				
				if (m.CheckArtist() == true || m.CheckSong() == true) {
					playerInput = event.text.unicode;
					m.AddText(playerInput);
					
				}
				m.Update();
			}
			else if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i position = sf::Mouse::getPosition(window);
					sf::Vector2f fposition(position.x, position.y);
					m.ClickButton(fposition);
					m.Update();


				}
				if (event.mouseButton.button == sf::Mouse::Right) {

					sf::Vector2i position = sf::Mouse::getPosition(window);
					sf::Vector2f fposition(position.x, position.y);
				}
				
			}
			
			
		}
	}

	TextureManager::Clear();
	return 0;

}

