#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <fstream>
#include "TextureManager.h"
#include "Data.h"


using namespace std;


class Menu {

private:
	sf::RenderWindow* window;
	Data data;
	map<string, sf::Sprite> buttons;
	bool songmas;
	bool artist;
	bool song;

public:
	Menu(sf::RenderWindow* win);
	void Initialize();
	void Update();
	void Background();
	void PrintSongs();
	void ClickButton(sf::Vector2f mouseClick);
	void GetButtons();
	void SongmasOn();
	void ArtistOn();
	void SongOn();

};
