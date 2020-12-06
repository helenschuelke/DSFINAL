#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <fstream>
#include "TextureManager.h"


using namespace std;
class Data
{
private:
	vector<string> songs;
	
public:
	Data();
	void TestWords();
	vector<string>ReturnSongs();

};

