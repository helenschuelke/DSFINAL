#include "AVL.h"
void AVL::insert(string number, string name, string artist) {
	root = insertNode(root, number, name, artist);
}

Node* AVL::insertNode(Node* node, string number, string name, string artist) {

	if (node == nullptr) {
		//cout << "insert" << endl;
		numNodes++;
		return new Node(number, name, artist);
	}
	//rotate and balance nodes if necessary
	if (number < node->index) {
		node->left = insertNode(node->left, number, name, artist);
		node = balance(node);
	}
	else if (number > node->index) {
		node->right = insertNode(node->right, number, name, artist);
		node = balance(node);
	}
	else {
		//index already exists so cannot insert
		return node;
	}
	return node;
}

Node* AVL::balance(Node* node) {
	int BF = getBalanceFactor(node);

	//Right Right Case == Left Rotation
	if (BF == -2 && getBalanceFactor(node->right) == -1) {
		return rotateLeft(node);
	}
	//Left Left Case == Right Rotation
	if (BF == 2 && getBalanceFactor(node->left) == 1) {
		return rotateRight(node);
	}
	if (BF == -2 && getBalanceFactor(node->right) == 1) {
		return rotateRightLeft(node);
	}
	if (BF == 2 && getBalanceFactor(node->left) == -1) {
		return rotateLeftRight(node);
	}
	//does not need any rotation return back same node
	return node;
}

//Cite https://stepik.org/submissions/1590562/299504733?unit=400654
int AVL::getBalanceFactor(Node* node) {
	if (node == nullptr)
		return 0;
	//BF = height at left - height at right
	return heightAtNode(node->left) - heightAtNode(node->right);
}

//Cite https://stepik.org/submissions/1590562/299504733?unit=400654
int AVL::heightAtNode(Node* node) {
	//return height
	if (node == nullptr)
		return 0;

	return std::max(heightAtNode(node->left), heightAtNode(node->right)) + 1;
}

//ROTATIONS
//Cite: https://stepik.org/submissions/1480367/299020677?unit=379728
Node* AVL::rotateLeft(Node* node) {
	Node* grandchild = node->right->left;
	Node* newParent = node->right;

	newParent->left = node;
	node->right = grandchild;

	return newParent;
}

//Cite: https://stepik.org/submissions/1480367/299020677?unit=379728
Node* AVL::rotateRight(Node* node) {
	Node* grandchild = node->left->right;
	Node* newParent = node->left;
	newParent->right = node;
	node->left = grandchild;

	return newParent;
}

//Cite: https://stepik.org/submissions/1480367/299020677?unit=379728
Node* AVL::rotateLeftRight(Node* node) {
	//left rotation with left node then call right rotation
	node->left = rotateLeft(node->left);
	return rotateRight(node);
}

//Cite: https://stepik.org/submissions/1480369/299057982?unit=379728
Node* AVL::rotateRightLeft(Node* node) {
	node->right = rotateRight(node->right);
	return rotateLeft(node);
}

vector<string> AVL::searchSong(string name) {
	//create vector to store the artists with the same song title
	vector<string> singers;
	preOrderSong(name, root, singers);
	return singers;

	//no songs matched
//	if (s.size() == 0) {
//		cout << "No match found!" << endl;
//	}
//	else {
//		for (int i = 0; i < s.size(); i++) {
//			cout << "Here are all the artists that sing this song: " << endl;
//			cout << s.at(i) << endl;
//		}
//	}

}

//Cite: Module 4 Solutions PDF 4.1b
//incorporate vector
void AVL::preOrderSong(string name, Node* node, vector<string>& singers) {
	//cout << "in pre order" << endl;
	//traverse in preOrder and push_back artists that sing same song title
	if (node == nullptr) return;

	if (name.compare(node->song.first) == 0)
		singers.push_back(node->song.second); 
	if (node->left)
		preOrderSong(name, node->left, singers);
	if (node->right)
		preOrderSong(name, node->right, singers);

}

vector<string> AVL::searchArtist(string artist) {
	//create vector to store the songs from the same artist
	vector<string> songs;
	preOrderArtist(artist, root, songs);
	return songs;

	//no names matched
//	if (singers.size() == 0) {
//		cout << "No match found!" << endl;
//	}
//	else {
//		for (int i = 0; i < singers.size(); i++) {
//			cout << "This artist sings these holiday songs: " << endl;
//			cout << singers.at(i) << endl;
//		}
//	}

}

void AVL::preOrderArtist(string artist, Node* node, vector<string>& songs) {
	//traverse in preOrder and push_back same song titles
	if (node == nullptr) return;

	if (artist.compare(node->song.second) == 0)
		songs.push_back(node->song.first);
	if (node->left)
		preOrderArtist(artist, node->left, songs);
	if (node->right)
		preOrderArtist(artist, node->right, songs);

}

void AVL::traversal() {
	inorderTraversal(root);
}
void AVL::inorderTraversal(Node* node) {

	//	if (node == nullptr)
	//		cout << "";
	//
	//	else {
	//		if (node->left != nullptr) {
	//			printInorder(node->left);
	//		}
	//		cout << "Song: " << node->song.first << endl;
	//		cout << "Artist: " << node->song.second << endl;
	//
	//		if (node->right != nullptr) {
	//			printInorder(node->right);
	//		}
	//	}

	if (node == nullptr);
	else {
		if (node->left != nullptr) {
			inorderTraversal(node->left);
		}
		//numNodes++;
		if (node->right != nullptr) {
			inorderTraversal(node->right);
		}
	}
}

vector<string> AVL::randomPlaylist() {
	srand(time(0));
	set<int> mySet;
	int count = 0;
	vector<string> playlist;
	//cout << numNodes << endl;

	while (count < 25) {
		int randomNum = rand() % 10772 + 1;
		if (mySet.find(randomNum) == mySet.end()) {
			mySet.insert(randomNum);
			count++;
			playlist.push_back(findIndex(root, to_string(randomNum)));
		}
	}

	return playlist;
}
string AVL::findIndex(Node* node, string key) {
	Node* curr = node;
	string s;
	string title, artist;

	if (curr == nullptr)
		s = "";
	else if (key.compare(curr->index) == 0) {
		title = curr->song.first;
		artist = curr->song.second;
		s = title + " by " + artist;
	}
	else if (key.compare(curr->index) < 0)
		s = findIndex(curr->left, key);
	else if (key.compare(curr->index) > 0)
		s = findIndex(curr->right, key);

	return s;
}