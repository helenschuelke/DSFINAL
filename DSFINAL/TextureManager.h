#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
using std::string;
using std::map;
//Source: COP3503 Provided by Professor for Minesweeper Project to manage textures
class TextureManager
{
	static map<string, sf::Texture> textures;
public:
	static void LoadTexture(string textureName);
	static sf::Texture& GetTexture(string textureName);
	static void Clear() { textures.clear(); }
};
