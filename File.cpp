#include "File.h"
File :: File() {
	index = 0;
	max = 3;
	for (int i = 0; i < 3; i++) {
		names[i] = "";
		scores[i] = 0;
	}
	readFile();
}
void File :: readFile() {
	std::ifstream file("scores.txt", ios :: app);
	if (file.peek() == EOF)
		return;
	string name;
	int score;
	index = 0;
	while (file >> name >> score && index < 5){
		names[index] = name;
		scores[index] = score;
		index++;
	}

	file.close();
}
void  File :: writeFile(int score, string name) {
	ofstream file("scores.txt");
	if (scores[2] < score) {
		names[2] = name;
		scores[2] = score;
	}
	sortFile();
	for (int i = 0; i < 3; ++i) {
		file << names[i] << " " << scores[i] << std::endl;
	}

	file.close();
}
void File::sortFile() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3 - i - 1; j++) {
			if (scores[j] < scores[j + 1]) {
				string tempName = names[j];
				names[j] = names[j + 1];
				names[j + 1] = tempName;
				int tempScore = scores[j];
				scores[j] = scores[j + 1];
				scores[j + 1] = tempScore;
			}
		}
	}
}
int File::returnLowestScore() {
	return scores[2];
}
