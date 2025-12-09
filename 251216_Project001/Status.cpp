#include <iostream>
#include <string>
#include "Status.h"

using namespace std;

Status::Status() : level(1)
{
	stats[0] = 0; // HP
	stats[1] = 0;  // MP
	stats[2] = 0;  // Attack
	stats[3] = 0;   // Defence
	stats[4] = 0;   // Strength
	stats[5] = 0;   // Agility
	stats[6] = 0;   // Intelligence
}

// Setting stats with input int values <- input excuted by main function
bool Status::setFirstStat(int _hp, int _mp)
{
	if (_hp <= 50 || _mp <= 50)
		return false;
	stats[0] = _hp;
	stats[1] = _mp;
	return true;
}
bool Status::setSecondStat(int _attack, int _defence)
{
	if (_attack <= 0 || _defence <= 0)
		return false;
	stats[2] = _attack;
	stats[3] = _defence;
	return true;
}
bool Status::setThirdStat(int _strength, int _agility, int _intelligence)
{
	if (_strength <= 0 || _agility <= 0 || _intelligence <= 0)
		return false;

	if (_strength + _agility + _intelligence > 10)
		return false;

	stats[4] = _strength;
	stats[5] = _agility;
	stats[6] = _intelligence;
	return true;
}

// HP/MP increase functions with potion count validation
bool Status::useHPPotion(int* potionHP)
{
	if (*potionHP <= 0)
		return false;
	stats[0] += 20;
	*potionHP -= 1;
	return true;
}
bool Status::useMPPotion(int* potionMP)
{
	if (*potionMP <= 0)
		return false;
	stats[1] += 20;
	*potionMP -= 1;
	return true;
}

// Attack/Defence double functions. No validation needed
void Status::doubleAttack()
{
	stats[2] *= 2;
}
void Status::doubleDefence()
{
	stats[3] *= 2;
}

// Add one stat function for 3 attributes only
bool Status::addOneStat(int statIndex, int* statPoint)
{
	if (statIndex < 4 || statIndex > 6)
		return false;
	if (*statPoint <= 0)
		return false;
	stats[statIndex]++;
	*statPoint -= 1;
	return true;
}

// Level up function. increase level by 1 and add hp and mp potions by one
void Status::levelUp(int* potionHP, int* potionMP, int* statPoint)
{
	level++;
	(*potionHP)++;
	(*potionMP)++;
	*statPoint += 2;
}



// From down here is all display functions for debugging (that returns string for main use)
string Status::displayLevel()
{
	return to_string(level);
}
string Status::displayHP()
{
	return to_string(stats[0]);
}
string Status::displayMP()
{
	return to_string(stats[1]);
}
string Status::displayAttack()
{
	return to_string(stats[2]);
}
string Status::displayDefence()
{
	return to_string(stats[3]);
}
string Status::displayStrength()
{
	return to_string(stats[4]);
}
string Status::displayAgility()
{
	return to_string(stats[5]);
}
string Status::displayIntelligence()
{
	return to_string(stats[6]);
}