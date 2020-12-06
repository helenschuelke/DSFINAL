#include "Menu.h"
Menu::Menu(sf::RenderWindow* win)
{
	window = win;
};

void Menu::Initialize() {
	songmas = true;
	artist = false;
	song = false;
	data.TestWords();
	Background();
	GetButtons();
	SongmasOn();
	PrintSongs();
	window->display();
	
	
};

void Menu::Background() {
	sf::Sprite red(TextureManager::GetTexture("checkers"));
	sf::Sprite jj(TextureManager::GetTexture("jinglejunkies"));
	sf::Sprite jb(TextureManager::GetTexture("back2"));
	sf::Sprite song(TextureManager::GetTexture("back25"));
	
	
	
	jj.setPosition(207, 20);
	jb.setPosition(210, 22);
	song.setPosition(40, 200);
	
	
	
	
	window->draw(red);
	window->draw(jb);
	window->draw(jj);
	window->draw(song);
	
	//window->draw(smallbox);
	
	
	
	
	
	
	

}

void Menu::Update() {
	Background();
	GetButtons();
	if (songmas) {
		SongmasOn();
		PrintSongs();
	}
	if (artist) {
		ArtistOn();
	}
	if (song) {
		SongOn();
	}
	window->display();

};

void Menu::PrintSongs() {
	sf::Text text;
	sf::Font font;
	if (!font.loadFromFile("Arial.ttf"))
	{
		cout << "error loading font" << endl;
	}
	vector<string> songs= data.ReturnSongs();
	double height = 285;
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
		text.setPosition(75, height);
		height += 16.5;
		window->draw(text);
		count++;
	}
}

void Menu::ClickButton(sf::Vector2f mouseClick) {
	auto iter = buttons.begin();
	for (; iter != buttons.end(); ++iter) {
		auto rectangle = iter->second.getGlobalBounds();
		if (rectangle.contains(mouseClick)) {
				cout << "found it" << endl;
			if (iter->first == "searchbysong") {
				songmas = false;
				artist = false;
				song = true;

			}
			else if (iter->first == "searchbyartist") {
				songmas = false;
				artist = true;
				song = false;
			}
			else if (iter->first == "newsongs") {
				songmas = true;
				artist = false;
				song = false;
			}
		}
	}
}

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

	

	button.setPosition(610, 200);
	songr.setPosition(642, 209);
	songb.setPosition(644, 211);
	artistr.setPosition(639, 279);
	artistb.setPosition(641, 281);
	newsongsr.setPosition(667, 349);
	newsongsb.setPosition(669, 351);

	window->draw(button);
	button2.setPosition(610, 270);
	window->draw(button2);
	button3.setPosition(610, 340);
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

void Menu::SongmasOn() {
	sf::Sprite allb(TextureManager::GetTexture("songmasb"));
	sf::Sprite allf(TextureManager::GetTexture("songmas"));

	allf.setPosition(125, 240);
	allb.setPosition(127, 241);

	window->draw(allb);
	window->draw(allf);
}

void Menu::ArtistOn() {
	sf::Sprite smallbox(TextureManager::GetTexture("small_square"));
	smallbox.setPosition(540, 180);
	smallbox.setPosition(540, 450);
	window->draw(smallbox);
}

void Menu::SongOn() {
	sf::Sprite smallbox(TextureManager::GetTexture("small_square"));
	smallbox.setPosition(540, 180);
	smallbox.setPosition(540, 450);
	window->draw(smallbox);
}