#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "Menu.h"


using namespace std;


int main()
{
	const int windowX = 1000;
	const int windowY = 800;
	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "JINGLE JUNKIES");
	//sf::RenderWindow songs(sf::VideoMode(windowX, windowY), "JINGLE JUNKIES");
	Menu m(&window);

	m.Initialize();
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{


			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::TextEntered) {

			}
			else if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i position = sf::Mouse::getPosition(window);
					sf::Vector2f fposition(position.x, position.y);
					cout << "Position.x = " << position.x << " Position.y = " << position.y << endl;
					m.ClickButton(fposition);
					m.Update();


				}
				if (event.mouseButton.button == sf::Mouse::Right) {

					sf::Vector2i position = sf::Mouse::getPosition(window);
					sf::Vector2f fposition(position.x, position.y);
					
					//m.Update();
				}
				
			}
		}


	}

	TextureManager::Clear();
	return 0;

}

