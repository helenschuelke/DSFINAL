#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <string>
#include <vector>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include<algorithm> 

using namespace std;


//Cite: Yelaine Linares Project 1 AVL Code
class Node {

public:
	string index;
	pair<string, string> song;
	Node* left;
	Node* right;
	//default constructor
	Node() : index(""), song("", ""), left(nullptr), right(nullptr) {}
	//constructor to initialize both name and ID
	Node(string x, string title, string artist) : index(x), song(title, artist), left(nullptr), right(nullptr) {}
};

class AVL {
	//initialize root
	Node* root = nullptr;
	int numNodes = 0;

public:
	//INSERT Functions
	void insert(string number, string name, string artist);
	Node* insertNode(Node* node, string number, string name, string artist);

	//Height and Balance check
	int heightAtNode(Node* node);
	int getBalanceFactor(Node* node);
	Node* balance(Node* node);

	//ROTATIONS
	Node* rotateLeft(Node* node);
	Node* rotateRight(Node* node);
	Node* rotateLeftRight(Node* node);
	Node* rotateRightLeft(Node* node);

	//SEARCH Functions
	vector<string> searchSong(string name);
	vector<string> searchArtist(string artist);
	void preOrderSong(string name, Node* node, vector<string>& singers);
	void preOrderArtist(string artist, Node* node, vector<string>& songs);

	//25 days of christmas song generator
	vector<string> randomPlaylist();
	string findIndex(Node* node, string index);

};

