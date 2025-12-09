#pragma once
#include <iostream>
#include <string>

using namespace std;

class Status
{
	int stats[7]; // 0: HP, 1: MP, 2: Attack, 3: Defence, 4: Strength, 5: Agility, 6: Intelligence
	int level;

public:
	Status();
	bool setFirstStat(int _hp, int _mp);
	bool setSecondStat(int _attack, int _defence);
	bool setThirdStat(int _strength, int _agility, int _intelligence);

	bool useHPPotion(int* potionHP);
	bool useMPPotion(int* potionMP);

	void doubleAttack();
	void doubleDefence();

	bool addOneStat(int statIndex, int* statPoint); // statIndex: 4-6 (only for 3 attributes)

	void levelUp(int* potionHP, int* potionMP, int* statPoint);

	// From down here is all display functions for debugging (that returns string for main use)
	string displayLevel();
	string displayHP();
	string displayMP();
	string displayAttack();
	string displayDefence();
	string displayStrength();
	string displayAgility();
	string displayIntelligence();
};