#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Status.h"
#include "DebugPrinter.h"

using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion = count;
	*p_MPPotion = count;
}

int main()
{
	int potionHP;
	int potionMP;
	int attributePoint = 0;

	Status plStats;

	DebugPrinter::printInputHPMP();
	int inputHP, inputMP;
	cin >> inputHP >> inputMP;
	while (!plStats.setFirstStat(inputHP, inputMP))
	{
		DebugPrinter::printErrorCode(1);
		DebugPrinter::printInputHPMP();
		cin >> inputHP >> inputMP;
	}

	DebugPrinter::printInputAttackDefence();
	int inputAttack, inputDefence;
	cin >> inputAttack >> inputDefence;
	while (!plStats.setSecondStat(inputAttack, inputDefence))
	{
		DebugPrinter::printErrorCode(2);
		DebugPrinter::printInputAttackDefence();
		cin >> inputAttack >> inputDefence;
	}

	DebugPrinter::printInputAttributes();
	int inputStrength, inputAgility, inputIntelligence;
	cin >> inputStrength >> inputAgility >> inputIntelligence;
	while (!plStats.setThirdStat(inputStrength, inputAgility, inputIntelligence))
	{
		DebugPrinter::printErrorCode(3);
		DebugPrinter::printInputAttributes();
		cin >> inputStrength >> inputAgility >> inputIntelligence;
	}

	setPotion(5, &potionHP, &potionMP);
	DebugPrinter::printPotionGiveaway(5);

	this_thread::sleep_for(chrono::seconds(3));

	DebugPrinter::printMain();

	int inputSelection;
	DebugPrinter::printSelection();
	cin >> inputSelection;
	while (inputSelection != 0)
	{
		bool resultGet;
		switch (inputSelection)
		{
		case 1:
			resultGet = plStats.useHPPotion(&potionHP);
			DebugPrinter::printHPMPUp(resultGet, true, potionHP, plStats);
			break;
		case 2:
			resultGet = plStats.useMPPotion(&potionMP);
			DebugPrinter::printHPMPUp(resultGet, false, potionMP, plStats);
			break;
		case 3:
			plStats.doubleAttack();
			DebugPrinter::printAttackDefenceDouble(true, plStats);
			break;
		case 4:
			plStats.doubleDefence();
			DebugPrinter::printAttackDefenceDouble(false, plStats);
			break;
		case 5:
			resultGet = plStats.addOneStat(4, &attributePoint);
			DebugPrinter::printAttributeIncrease(resultGet, 4, attributePoint, plStats);
			break;
		case 6:
			resultGet = plStats.addOneStat(5, &attributePoint);
			DebugPrinter::printAttributeIncrease(resultGet, 5, attributePoint, plStats);
			break;
		case 7:
			resultGet = plStats.addOneStat(6, &attributePoint);
			DebugPrinter::printAttributeIncrease(resultGet, 6, attributePoint, plStats);
			break;
		case 8:
			DebugPrinter::printOverallState(plStats, potionHP, potionMP, attributePoint);
			break;
		case 9:
			plStats.levelUp(&potionHP, &potionMP, &attributePoint);
			DebugPrinter::printLevelUp(plStats.displayLevel());
			break;
		default:
			break;
		}
		DebugPrinter::printSelection();
		cin >> inputSelection;
	}

	DebugPrinter::printProgramEnd();

	return 0;
}