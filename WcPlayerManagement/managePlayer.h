#include "player.h"
#include <fstream>
#include <sstream>
#include <algorithm>

class ManagePlayer {
private:
	vector<Player> players;
public:
	ManagePlayer();
	~ManagePlayer();
	void manage();
	void readFile();
	vector<string> split(string, char);
	void menu();
	void print();
	void sort_();
	void printOldest();
	void printByPos(string);
	void sortByName();
	void sortByAge();
	void sortByPos();
	Player getPlayer(int);
	void reWrite();
	void addPlayer();
};

bool compareName(Player, Player);
bool compareAge(Player, Player);
bool comparePos(Player, Player);