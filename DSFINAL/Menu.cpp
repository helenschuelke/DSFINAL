#include "Menu.h"
Menu::Menu(sf::RenderWindow* win)
{
	window = win;
	
	{
		SimpleTimer timer("AVL Insertion: ");
		//read in the file
		//insert all the nodes
		//Node is going to have an index, pair<string,string> song, artist
		LoadAVLFile(avl);
	}

	{
		SimpleTimer timer("Graph Insertion: ");
		//read in the file
		//insert all the nodes
		//Node is going to have an index, pair<string,string> song, artist
		graph.ReadFiles();
	}
};

//Initializes menu
void Menu::Initialize() {
	display = avl.randomPlaylist();
	songmas = true;
	artist = false;
	song = false;
	data.TestWords();
	Background();
	GetButtons();
	SongmasOn();
	PrintSongs(display);
	window->display();
	
	
};

//Initializes background
void Menu::Background() {
	sf::Sprite red(TextureManager::GetTexture("checkers"));
	sf::Sprite jj(TextureManager::GetTexture("jinglejunkies"));
	sf::Sprite jb(TextureManager::GetTexture("back2"));
	sf::Sprite song(TextureManager::GetTexture("back25"));
	
	
	
	jj.setPosition(377, 40);
	jb.setPosition(380, 42);
	song.setPosition(60, 240);
	
	
	
	
	window->draw(red);
	window->draw(jb);
	window->draw(jj);
	window->draw(song);	

}

//Change buttons green when clicked
void Menu::LightUpGreen() {
	
	if (artist) {
		sf::Sprite artistb(TextureManager::GetTexture("searchbyartistb"));
		sf::Sprite artistg(TextureManager::GetTexture("searchbyartistg"));

		artistg.setPosition(899, 319);
		artistb.setPosition(901, 321);

		window->draw(artistb);
		window->draw(artistg);
	}
	if (song) {
		sf::Sprite songb(TextureManager::GetTexture("searchbysong"));
		sf::Sprite songg(TextureManager::GetTexture("searchbysongg"));

		songg.setPosition(900, 249);
		songb.setPosition(902, 251);

		window->draw(songb);
		window->draw(songg);
	}
}

//Update displayed menu
void Menu::Update() {
	Background();
	GetButtons();
	if (songmas) {
		SongmasOn();
		PrintSongs(avl.randomPlaylist());
	}
	if (artist) {
		ArtistOn();
		GetText();
		PrintList(songs);
	}
	if (song) {
		SongOn();
		GetText();
		PrintList(artists);
	}
	void LightUpGreen();
	window->display();

};

//Prints songs (numbered up to 25)
void Menu::PrintSongs(vector<string>songs) {
	sf::Text text;
	sf::Font font;
	if (!font.loadFromFile("Arial.ttf"))
	{
		cout << "error loading font" << endl;
	}
	//vector<string> songs= data.ReturnSongs();
	double height = 325;
	int count = 1;
	for (int i = 0; i < 25; i++) {
		string toAdd;
		if (count < 10) {
			toAdd = " ";
			toAdd.append(to_string(count));
			toAdd.append(".  ");
		}
		else {
			toAdd = to_string(count);
			toAdd.append(". ");
		}

		toAdd.append(songs[i]);
		text.setString(toAdd);
		text.setFont(font);
		text.setCharacterSize(20);
		text.setFillColor(sf::Color::Black);
		text.setPosition(105, height);
		height += 16.5;
		window->draw(text);
		count++;
	}
}

//Used with mouse click event
void Menu::ClickButton(sf::Vector2f mouseClick) {
	auto iter = buttons.begin();
	for (; iter != buttons.end(); ++iter) {
		auto rectangle = iter->second.getGlobalBounds();
		if (rectangle.contains(mouseClick)) {
				
			if (iter->first == "searchbysong") {//Search by Song is pressed
				display.clear();
				display = avl.randomPlaylist();
				songmas = false;
				artist = false;
				song = true;
				currentText.clear();
				artists.clear();

			}
			else if (iter->first == "searchbyartist") {//Search by artist is pressed
				songmas = false;
				artist = true;
				song = false;
				currentText.clear();
				songs.clear();
			}
			else if (iter->first == "newsongs") {//New Songs! is pressed
				songmas = true;
				artist = false;
				song = false;
				currentText.clear();
			}
			
			if (iter->first == "avl") {//Search AVL tree
				
				if (song) {//AVL search for artists along with time

					{
						SimpleTimer timer("AVL Search for Artists: ");
						artists = avl.searchSong(currentText);
					}
					if (artists.size() == 0) {
						artists.push_back("No Matches");
					}
					PrintList(artists);
				}
				if (artist) {//AVL search for songs along with time

					{
						SimpleTimer timer("AVL Search for Songs: ");
						songs = avl.searchArtist(currentText);
					}
					if (songs.size() == 0) {
						songs.push_back("No Matches");
					}
					PrintList(songs);
				}
				
			}
			else if (iter->first == "graph") {//Search Graph
				if (song) {//Graph search along with time
					{
						SimpleTimer timer("Graph Search for Artists: ");
						artists = graph.BySong(currentText);
					}
					if (artists.size() == 0) {
						artists.push_back("No Matches");
					}
					PrintList(artists);
				}
				if (artist) {//Artist search along with time
					{
						SimpleTimer timer("Graph Search for Songs: ");
						songs = graph.ByArtist(currentText);
					}
					if (songs.size() == 0) {
						songs.push_back("No Matches");
					}
					PrintList(songs);
				}
			}
		}
	}
}

//Updates text input by user
void Menu::AddText(string add) {
	
	currentText += add;
}

//Prints text from user
void Menu::GetText() {
	sf::Text input;
	sf::Font font;
	if (!font.loadFromFile("Arial.ttf"))
	{
		cout << "error loading font" << endl;
	}

	input.setString(currentText);
	input.setPosition(850, 530);
	input.setFont(font);
	input.setCharacterSize(20);
	input.setFillColor(sf::Color::Black);

	window->draw(input);
}

//Prints button options and stores them for later use
void Menu::GetButtons() {
	sf::Sprite songb(TextureManager::GetTexture("searchbysong"));
	sf::Sprite songr(TextureManager::GetTexture("searchbysongr"));
	sf::Sprite artistb(TextureManager::GetTexture("searchbyartistb"));
	sf::Sprite artistr(TextureManager::GetTexture("searchbyartistr"));
	sf::Sprite button(TextureManager::GetTexture("button"));
	sf::Sprite button2(TextureManager::GetTexture("button2"));
	sf::Sprite button3(TextureManager::GetTexture("button3"));
	sf::Sprite newsongsb(TextureManager::GetTexture("newsongsb"));
	sf::Sprite newsongsr(TextureManager::GetTexture("newsongsr"));

	

	button.setPosition(870, 240);
	songr.setPosition(900, 249);
	songb.setPosition(902, 251);
	artistr.setPosition(899, 319);
	artistb.setPosition(901, 321);
	newsongsr.setPosition(927, 389);
	newsongsb.setPosition(929, 391);

	window->draw(button);
	button2.setPosition(870, 310);
	window->draw(button2);
	button3.setPosition(870, 380);
	window->draw(button3);

	window->draw(songb);
	window->draw(songr);
	window->draw(artistb);
	window->draw(artistr);
	window->draw(newsongsb);
	window->draw(newsongsr);

	buttons.emplace("searchbysong", button);
	buttons.emplace("searchbyartist", button2);
	buttons.emplace("newsongs", button3);
}

//Event when New Songs! is pressed
void Menu::SongmasOn() {
	sf::Sprite allb(TextureManager::GetTexture("songmasb"));
	sf::Sprite allf(TextureManager::GetTexture("songmas"));

	allf.setPosition(245, 280);
	allb.setPosition(247, 281);

	window->draw(allb);
	window->draw(allf);

	//vector<string>random = avl.randomPlaylist();
	//PrintSongs(random);

}

//displays text box when Search by Song or Search by Artist is pressed
void Menu::TextBox() {
	sf::Sprite smallbox(TextureManager::GetTexture("small_square"));
	sf::Sprite avlr(TextureManager::GetTexture("avl"));
	sf::Sprite avlb(TextureManager::GetTexture("avlb"));
	sf::Sprite graphr(TextureManager::GetTexture("graphr"));
	sf::Sprite graphb(TextureManager::GetTexture("graphb"));
	sf::Sprite search(TextureManager::GetTexture("search"));
	sf::Sprite search2(TextureManager::GetTexture("search2"));

	smallbox.setPosition(800, 490);

	search.setPosition(860, 680);

	search2.setPosition(1040, 680);

	avlr.setPosition(875, 695);
	avlb.setPosition(876, 696);

	graphr.setPosition(1047, 695);
	graphb.setPosition(1048, 696);
	window->draw(smallbox);
	
	window->draw(search);
	window->draw(search2);

	window->draw(avlb);
	window->draw(avlr);

	window->draw(graphb);
	window->draw(graphr);

	buttons.emplace("avl", search);
	buttons.emplace("graph", search2);

}

//Prints a list (used to print songs and artists when searched)
void Menu::PrintList(vector<string>list) {
	sf::Text text;
	sf::Font font;
	if (!font.loadFromFile("Arial.ttf"))
	{
		cout << "error loading font" << endl;
	}
	double height = 325;
	for (int i = 0; i < list.size(); i++) {
		string toAdd;
		
		toAdd = list[i];
		text.setString(toAdd);
		text.setFont(font);
		text.setCharacterSize(20);
		text.setFillColor(sf::Color::Black);
		text.setPosition(105, height);
		height += 16.5;
		window->draw(text);
	}

	
}

//Used when Search by Artist is pressed
void Menu::ArtistOn() {
	TextBox();
	sf::Sprite sr(TextureManager::GetTexture("songsbyartistr"));
	sf::Sprite sb(TextureManager::GetTexture("songsbyartistb"));

	sr.setPosition(125, 280);
	sb.setPosition(127, 281);

	window->draw(sb);
	window->draw(sr);
	
	
}

//Used when Search by Song is pressed
void Menu::SongOn() {
	TextBox();
	sf::Sprite ar(TextureManager::GetTexture("artiststhatsingthissongr"));
	sf::Sprite ab(TextureManager::GetTexture("artiststhatsingthissongb"));

	ar.setPosition(120, 280);
	ab.setPosition(122, 281);

	window->draw(ab);
	window->draw(ar);

	
}

bool Menu::CheckSongmas() {
	return songmas;
}

bool Menu::CheckArtist() {
	return artist;
}

bool Menu::CheckSong() {
	return song;
}

//Loads AVL file
void Menu::LoadAVLFile(AVL& avl) {
	ifstream inFile;
	inFile.open("avldata.csv");

	string lineFromFile;
	//header
	getline(inFile, lineFromFile);
	int count = 0;
	while (getline(inFile, lineFromFile)) {
		count++;
		istringstream line(lineFromFile);
		string index;
		string title;
		string artist;

		getline(line, index, ',');
		getline(line, title, ',');
		getline(line, artist, ',');

		avl.insert(index, title, artist);
	}
	
}
