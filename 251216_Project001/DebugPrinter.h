#pragma once
#include <iostream>
#include <string>
#include "Status.h"

using namespace std;

class DebugPrinter
{
public:
	static void printErrorCode(int code);
	static void printInputHPMP();
	static void printInputAttackDefence();
	static void printInputAttributes();
	static void printPotionGiveaway(int potionAmount);
	static void printMain();
	static void printSelection();
	static void printLevelUp(string newLevel);
	static void printHPMPUp(bool isSuccess, bool isHP, int potionTarget, Status stats);
	static void printAttackDefenceDouble(bool isAttack, Status stats);
	static void printAttributeIncrease(bool isSuccess, int attributeIndex, int attributePoint, Status stats);
	static void printOverallState(Status stats, int potionHP, int potionMP, int attributePoint);
	static void printProgramEnd();
};
