// Copyright (c) 2025 by ood11611doo. All rights reserved.

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include "DebugPrinter.h"
#include "Status.h"

using namespace std; // NOLINT

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
  *p_HPPotion = count;
  *p_MPPotion = count;
}

int main() {
  int potionHP;
  int potionMP;
  int attributePoint = 0;

  Status plStats;

  DebugPrinter::printInputCode(EInputCode::hpmpInput);
  int inputHP, inputMP;
  cin >> inputHP >> inputMP;
  while (!plStats.setFirstStat(inputHP, inputMP)) {
    DebugPrinter::printErrorCode(EErrorCode::hpmpError);
    DebugPrinter::printInputCode(EInputCode::hpmpInput);
    cin >> inputHP >> inputMP;
  }

  DebugPrinter::printInputCode(EInputCode::attackDefenceInput);
  int inputAttack, inputDefence;
  cin >> inputAttack >> inputDefence;
  while (!plStats.setSecondStat(inputAttack, inputDefence)) {
    DebugPrinter::printErrorCode(EErrorCode::attackDefenceError);
    DebugPrinter::printInputCode(EInputCode::attackDefenceInput);
    cin >> inputAttack >> inputDefence;
  }

  DebugPrinter::printInputCode(EInputCode::attributesInput);
  int inputStrength, inputAgility, inputIntelligence;
  cin >> inputStrength >> inputAgility >> inputIntelligence;
  while (!plStats.setThirdStat(
    inputStrength, inputAgility, inputIntelligence)) {
    DebugPrinter::printErrorCode(EErrorCode::attributesError);
    DebugPrinter::printInputCode(EInputCode::attributesInput);
    cin >> inputStrength >> inputAgility >> inputIntelligence;
  }

  setPotion(5, &potionHP, &potionMP);
  DebugPrinter::printInputCode(EInputCode::potionInput, 5);

  this_thread::sleep_for(chrono::seconds(3));

  DebugPrinter::printMessages(EMessages::selectionView);

  int inputSelection;
  DebugPrinter::printMessages(EMessages::selectNumber);
  cin >> inputSelection;
  while (inputSelection != 0) {
    bool resultGet;
    switch (inputSelection) {
    case 1:
      resultGet = plStats.useHPPotion(&potionHP);
      DebugPrinter::printStatEdit(
          resultGet ? EStatEdits::hpUpSuccess : EStatEdits::hpmpUpFailed,
          &plStats, &potionHP, &potionMP, &attributePoint);
      break;
    case 2:
      resultGet = plStats.useMPPotion(&potionMP);
      DebugPrinter::printStatEdit(
        resultGet ? EStatEdits::mpUpSuccess : EStatEdits::hpmpUpFailed,
        &plStats, &potionHP, &potionMP, &attributePoint);
      break;
    case 3:
      plStats.doubleAttack();
      DebugPrinter::printStatEdit(EStatEdits::attackDouble,
        &plStats, &potionHP, &potionMP, &attributePoint);
      break;
    case 4:
      plStats.doubleDefence();
      DebugPrinter::printStatEdit(EStatEdits::defenceDouble,
        &plStats, &potionHP, &potionMP, &attributePoint);
      break;
    case 5:
      resultGet = plStats.addOneStat(4, &attributePoint);
      DebugPrinter::printStatEdit(resultGet ?
        EStatEdits::strengthUpSuccess : EStatEdits::attributeUpFailed,
        &plStats, &potionHP, &potionMP, &attributePoint);
      break;
    case 6:
      resultGet = plStats.addOneStat(5, &attributePoint);
      DebugPrinter::printStatEdit(resultGet ?
        EStatEdits::agilityUpSuccess : EStatEdits::attributeUpFailed,
        &plStats, &potionHP, &potionMP, &attributePoint);
      break;
    case 7:
      resultGet = plStats.addOneStat(6, &attributePoint);
      DebugPrinter::printStatEdit(resultGet ?
        EStatEdits::intelligenceUpSuccess : EStatEdits::attributeUpFailed,
        &plStats, &potionHP, &potionMP, &attributePoint);
      break;
    case 8:
      DebugPrinter::printStatEdit(EStatEdits::justDisplayStats,
        &plStats, &potionHP, &potionMP, &attributePoint);
      break;
    case 9:
      plStats.levelUp(&potionHP, &potionMP, &attributePoint);
      DebugPrinter::printMessages(EMessages::levelUp, plStats.displayLevel());
      break;
    default:
      break;
    }
    DebugPrinter::printMessages(EMessages::selectNumber);
    cin >> inputSelection;
  }

  DebugPrinter::printMessages(EMessages::programEnd);

  return 0;
}
