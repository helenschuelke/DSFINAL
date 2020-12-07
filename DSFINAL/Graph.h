#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <stdlib.h> 
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//Parts of Graph come from Helen Schuelke COP3530 Project 2
class GraphNode {
private:
	vector<int> inAdj;
	vector<int> outAdj;
	int key;
public:
	GraphNode(int val) {
		key = val;
	}
	void AddIn(int val) {
		inAdj.push_back(val);
	}
	void AddOut(int val) {
		outAdj.push_back(val);
	}
	vector<int> GetOut() {
		return outAdj;
	}
	vector<int> GetIn() {
		return inAdj;
	}
	int NumOut() {
		int out = outAdj.size();
		return out;
	}
	int NumIn() {
		int in = inAdj.size();
		return in;
	}
};

class Graph {
private:
	map <int, pair<string, string>> keyMap; //get string pair from int key
	map <pair<string, string>, int> backup; //get int key from string pair
	vector<int> vertices; //record vertices

	map<int, GraphNode*> adj;//record pointers to Adjacnecy List

	map<int, double> PI;//Result from power iterations where int is the key and double is the result

	int totalVertices = 0; //keep track of total vertices
	int nextKey = 1; //keep track of individual keys
public:
	void AddEdge(int to, int from, GraphNode* toNode, GraphNode* fromNode);
	vector<int> GenerateEdges(GraphNode* from, int total);
	vector<string> BySong(string song);
	vector<string> ByArtist(string artist);
	void ReadFiles();
};
