#include "Data.h"
void Data::TestWords() {
	for (int i = 0; i < 25; i++) {
		songs.push_back("test");
	}
}
vector<string> Data::ReturnSongs() {
	return songs;
}

Data::Data(){

}
