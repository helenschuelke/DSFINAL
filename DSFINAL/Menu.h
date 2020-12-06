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
#include "AVL.h"
#include "Graph.h"
#include<time.h>


using namespace std;
using highResClock = std::chrono::high_resolution_clock;
using timePoint = highResClock::time_point;

//Cite: Reusing Simple Timer class from my COP3502 project
class SimpleTimer {
	string message;
	timePoint start;
	timePoint stop;
	std::chrono::duration<double> elapsed;

public:
	SimpleTimer(const char* msg) {
		message = msg;
		start = highResClock::now();
	}
	~SimpleTimer() {
		stop = highResClock::now();
		elapsed = stop - start;
		cout << message << elapsed.count() << endl;
	}
};

class Menu {

private:
	sf::RenderWindow* window;
	Data data;
	AVL avl;
	Graph graph;
	map<string, sf::Sprite> buttons;
	bool songmas;
	bool artist;
	bool song;
	string currentText;
	vector<string> artists;
	vector<string>songs;
	vector<string>display;
	

public:
	Menu(sf::RenderWindow* win);
	void Initialize();
	void Update();
	void Background();
	void PrintSongs(vector<string> songs);
	void ClickButton(sf::Vector2f mouseClick);
	void AddText(string add);
	void GetText();
	void TextBox();
	void PrintList(vector<string> artist);
	void GetButtons();
	void SongmasOn();
	void ArtistOn();
	void SongOn();
	bool CheckSongmas();
	bool CheckArtist();
	bool CheckSong();

	void LightUpGreen();

	void LoadAVLFile(AVL& avl);

};
