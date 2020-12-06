#include "Graph.h"
void Graph::Trial() {
	//cout << totalVertices << endl;
}

void Graph::AddEdge(int to, int from, GraphNode* toNode, GraphNode* fromNode) {
	GraphNode* addV = fromNode;
	addV->AddOut(to);

	addV = toNode;
	addV->AddIn(from);
}

vector<int> Graph::GenerateEdges(GraphNode* from, int total) {
	vector<int> edges;
	int randomNumber;
	bool found;
	for (int i = 0; i < 25; i++) {
		do {
			randomNumber = rand() % total + 1;
			found = from->CheckEdgeOut(randomNumber);
			vector<int> out = from->GetOut();
			/*
			for (int i = 1; i <= out.size(); i++) {
				if (out[i] == randomNumber) {
					found = true;
				}
			}
			*/
		} while (found);
		//edges.push_back(randomNumber);
	}

	return edges;
}

vector<string> Graph::BySong(string song) {
	vector<string> artists;
	//cout << "by song" << endl;
	auto it = keyMap.begin();

	while (it != keyMap.end()) {
		if (it->second.first == song) {
			string foundIt = it->second.second;
			//cout << foundIt << endl;
			artists.push_back(foundIt);
		}
		it++;
	}

	return artists;
}

vector<string> Graph::ByArtist(string artist) {
	vector<string> songs;

	auto it = keyMap.begin();

	while (it != keyMap.end()) {
		if (it->second.second == artist) {
			string foundIt = it->second.first;
			//cout << foundIt << endl;
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
		//cout << "open" << endl;
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
			//count % 2 == 0 &&
			if (count > 1) {
				AddEdge((count - 1), count, adj[count - 1], tempNode);
			}

		}

		//Random edges:
		//Total is 10772
		/*
		for (int i = 0; i < totalVertices; i++) {
			vector<int> rEdges;
			rEdges = GenerateEdges(adj[i], totalVertices);
			/*
			for (int j = 0; j < rEdges.size(); j++) {
				AddEdge(rEdges[j], i, adj[rEdges[j]], adj[j]);
			}



		}
*/




	}

}