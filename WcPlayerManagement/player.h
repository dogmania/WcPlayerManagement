#include "person.h"

using namespace std;

class Player : public Person {
private:
	string name;
	string squad;
	string pos;
	string age;
public:
	Player(string, string, string, string);

	string getPos();
	string getAge();
	string getSquad();
	string getName();
};