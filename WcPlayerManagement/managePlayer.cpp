#include "managePlayer.h"

ManagePlayer::ManagePlayer() {}
ManagePlayer::~ManagePlayer() {}

void ManagePlayer::manage() {
	menu();
}

void ManagePlayer::readFile() {//csv 파일에 있는 데이터를 한줄씩 읽는 함수
	ifstream fin("World_cup2022.csv");
	string line;
	vector<string> parsedLine;

	if (!fin) {
		cerr << "파일을 열 수 없습니다." << endl;
	}

	if (fin.is_open()) {
		while (true) {
			if (fin.eof()) break;

			getline(fin, line);
			if (line == "") break;
			parsedLine = split(line, ',');

			Player temp(parsedLine[0], parsedLine[1], parsedLine[2], parsedLine[3]);
			players.push_back(temp);

			parsedLine.clear();
		}
	}
}

vector<string> ManagePlayer::split(string input, char delimiter) {
	vector<string> result;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter)) {
		result.push_back(temp);
	}

	return result;
}

void ManagePlayer::menu() {
	int input = 0;

	cout << "--------------------------------------Menu--------------------------------------" << endl;
	cout << "1. Print Menu" << endl;
	cout << "2. Sort Menu" << endl;
	cout << "3. Add Player" << endl;
	cout << "4. Exit" << endl;

	cin >> input;

	switch (input) {
	case 1: print();
		break;
	case 2: sort_();
		break;
	case 3: addPlayer();
	case 4: 
		cout << "Exit" << endl;
		break;
	default: cout << "Please enter 1 or 2 or 3" << endl;
		menu();
	}
}

void ManagePlayer::print() {
	int input = 0;

	cout << "1. Print the oldest player." << endl;
	cout << "2. Print only DF player." << endl;
	cout << "3. Print only MF player." << endl;
	cout << "4. Print only FW player." << endl;
	cout << "5. Print only GK player." << endl;

	cin >> input;

	switch (input) {
	case 1: 
		printOldest();
		menu();
		break;
	case 2:
		printByPos("DF");
		menu();
		break;
	case 3:
		printByPos("MF");
		menu();
		break;
	case 4:
		printByPos("FW");
		menu();
		break;
	case 5:
		printByPos("GK");
		menu();
		break;
	}
}

void ManagePlayer::sort_() {
	int input;
	cout << "1. Sort by name" << endl;
	cout << "2. Sort by age" << endl;
	cout << "3. Sort by pos" << endl;

	cin >> input;

	switch (input) {
	case 1: 
		sortByName();
		menu();
		break;
	case 2: 
		sortByAge();
		menu();
		break;
	case 3:
		sortByPos();
		menu();
		break;
	default:
		cout << "Please enter 1 or 2 or 3" << endl;
		menu();
	}
}

Player ManagePlayer::getPlayer(int i) {
	return players[i];
}

void ManagePlayer::printOldest() {
	string max_age = getPlayer(0).getAge();
	int index = 0;
	for (int i = 0; i < players.size(); i++) {
		if (max_age < players[i].getAge()) {
			max_age = players[i].getAge();
			index = i;
		}
	}
	cout.width(15);
	cout << players[index].getName() << "," << players[index].getAge() << "," << players[index].getPos() << endl;
}

void ManagePlayer::printByPos(string pos) {
	for (int i = 0; i < players.size(); i++) {
		if (players[i].getPos() == pos) {
			cout.width(20);
			cout << players[i].getName() << "," << players[i].getAge() << "," << players[i].getPos() << endl;
		}
	}
}


void ManagePlayer::sortByName() {
	sort(players.begin(), players.end(), compareName);
	for (int i = 0; i < players.size(); i++) {
		cout.width(20);
		cout << players[i].getName() << "," << players[i].getSquad() << "," << players[i].getAge() << "," << players[i].getPos() << endl;
	}
	reWrite();
}

void ManagePlayer::sortByAge() {
	sort(players.begin(), players.end(), compareAge);
	for (int i = 0; i < players.size(); i++) {
		cout.width(20);
		cout << players[i].getName() << "," << players[i].getSquad() << "," << players[i].getAge() << "," << players[i].getPos() << endl;
	}
	reWrite();
}

void ManagePlayer::sortByPos() {
	sort(players.begin(), players.end(), comparePos);
	for (int i = 0; i < players.size(); i++) {
		cout.width(20);
		cout << players[i].getName() << "," << players[i].getSquad() << "," << players[i].getAge() << "," << players[i].getPos() << endl;
	}
	reWrite();
}

bool compareName(Player a, Player b) {
	return a.getName() < b.getName();
}

bool compareAge(Player a, Player b) {
	return a.getAge() < b.getAge();
}

bool comparePos(Player a, Player b) {
	return a.getPos() < b.getPos();
}

void ManagePlayer::reWrite() {
	remove("World_cup2022.csv");

	ofstream file("World_cup2022.csv", ios_base::out | ios_base::app);

	if (!file) {
		cerr << "파일을 열 수 없습니다." << endl;
	}

	for (int i = 0; i < players.size(); i++) {
		file << players[i].getSquad() << "," << players[i].getName() << "," << players[i].getAge() << "," << players[i].getPos() << endl;
	}

	file.close();
}

void ManagePlayer::addPlayer() {
	string s, name, age, pos;
	cin.ignore(100, '\n');
	cout << "Player name? :";
	getline(cin, name);

	cout << "Player age? :";
	cin >> age;

	cout << "Player pos? :";
	cin >> pos;

	Player temp("2022 Korea Republic", name, age, pos);
	players.push_back(temp);
	reWrite();

	cout << "Success!" << endl;

	menu();
}