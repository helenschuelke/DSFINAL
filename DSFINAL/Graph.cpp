#include "Graph.h"

//Adds an edge to the graph
void Graph::AddEdge(int to, int from, GraphNode* toNode, GraphNode* fromNode) {
	GraphNode* addV = fromNode;
	addV->AddOut(to);

	addV = toNode;
	addV->AddIn(from);
}

//Used to randomly make edges
vector<int> Graph::GenerateEdges(GraphNode* from, int total) {
	vector<int> edges;
	int randomNumber;
	bool found;
	for (int i = 0; i < 25; i++) {
		do {
			randomNumber = rand() % total + 1;
			vector<int> out = from->GetOut();
			
		} while (found);
		
	}

	return edges;
}

//Enter song and returns vector of all artists who sang it
vector<string> Graph::BySong(string song) {
	vector<string> artists;
	auto it = keyMap.begin();

	while (it != keyMap.end()) {
		if (it->second.first == song) {
			string foundIt = it->second.second;
			artists.push_back(foundIt);
		}
		it++;
	}

	return artists;
}
//Enter artists and returns vector of all songs they have sang
vector<string> Graph::ByArtist(string artist) {
	vector<string> songs;

	auto it = keyMap.begin();

	while (it != keyMap.end()) {
		if (it->second.second == artist) {
			string foundIt = it->second.first;
			songs.push_back(foundIt);
		}
		it++;
	}

	return songs;
}

void Graph::ReadFiles() {
	int no_of_lines = 10772;
	string title, artist;
	int count = 0;

	ifstream inFile;
	inFile.open("graphdata.csv");//open data
	if (inFile.is_open())
	{
		string ignore;
		string lineFromFile;
		getline(inFile, ignore);
		while (getline(inFile, lineFromFile)) {

			count++;
			istringstream line(lineFromFile);

			string title;
			string artist;

			getline(line, title, ',');
			getline(line, artist, ',');

			//create new nodes for the input pairs
			pair<string, string> temp = make_pair(title, artist);
			keyMap[count] = temp;
			backup[temp] = count;
			GraphNode* tempNode = new GraphNode(count);
			adj[count] = tempNode;
			totalVertices++;

			//link the node with the last node
			if (count > 1) {
				AddEdge((count - 1), count, adj[count - 1], tempNode);
			}

		}


	}

}
