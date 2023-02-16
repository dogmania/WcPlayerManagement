#include "player.h"

Player::Player(string squad, string name, string age, string pos): name(name), squad(squad), pos(pos), age(age) {}

string Player::getAge() {
	return age;
}

string Player::getName() {
	return name;
}

string Player::getPos() {
	return pos;
}

string Player::getSquad() {
	return squad;
}