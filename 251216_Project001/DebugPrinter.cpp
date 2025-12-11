// Copyright (c) 2025 by ood11611doo. All rights reserved.

#include <iostream>
#include <string>
#include <cstdlib>
#include "DebugPrinter.h"

using namespace std; // NOLINT

// 1: HP/MP error, 2: Attack/Defence error, 3: Attributes error
void DebugPrinter::printErrorCode(int code) {
  switch (code) {
  case 1:
    cout << "HP와 MP는 50보다 큰 값을 정해야 합니다. 다시 입력해 주세요." << endl;
    break;
  case 2:
    cout << "공격력과 방어력은 0을 초과하는 값이 입력되어야 합니다." <<
    "다시 입력해 주세요." << endl;
    break;
  case 3:
    cout << "힘, 민첩, 지능은 0을 초과하고 총 합이 10을 넘어가지 않아야 합니다." <<
    "다시 입력해 주세요." << endl;
    break;
  default:
    cout << "Unknown error code." << endl;
    break;
  }
}
void DebugPrinter::printInputHPMP() {
  cout << "HP와 MP를 입력해주세요: ";
}
void DebugPrinter::printInputAttackDefence() {
  cout << "공격력과 방어력을 입력해주세요: ";
}
void DebugPrinter::printInputAttributes() {
  cout << "힘, 민첩, 지능을 입력해주세요: ";
}
void DebugPrinter::printPotionGiveaway(int potionAmount) {
  cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 "
    << to_string(potionAmount) << "개)" << endl;
}
void DebugPrinter::printMain() {
  system("cls");
  cout << "<스탯 관리 시스템>" << endl;
  cout << "1. HP UP" << endl;
  cout << "2. MP UP" << endl;
  cout << "3. 공격력 UP" << endl;
  cout << "4. 방어력 UP" << endl;
  cout << "5. 능력치[힘] UP" << endl;
  cout << "6. 능력치[민첩] UP" << endl;
  cout << "7. 능력치[지능] UP" << endl;
  cout << "8. 현재 능력치" << endl;
  cout << "9. Level UP" << endl;
  cout << "0. 나가기" << endl;
}
void DebugPrinter::printSelection() {
  cout << "번호를 선택해주세요: ";
}
void DebugPrinter::printLevelUp(string newLevel) {
  cout << "* 레벨업! 현재 레벨: " << newLevel << endl;
  cout << "* HP/MP 포션이 지급됩니다." << endl;
}
void DebugPrinter::printHPMPUp(
  bool isSuccess, bool isHP, int potionTarget, Status stats) {
  if (!isSuccess) {
    cout << "* 포션이 부족합니다." << endl;
  } else {
    cout << "* " << (isHP ? "HP" : "MP") <<
      "가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
    cout << "* 현재 " << (isHP ? "HP" : "MP") <<
      ": " << (isHP ? stats.displayHP() : stats.displayMP()) << endl;
    cout << "* 남은 포션 수: " << to_string(potionTarget) << endl;
  }
}
void DebugPrinter::printAttackDefenceDouble(bool isAttack, Status stats) {
  cout << "* " << (isAttack ? "공격력" : "방어력") <<
    "이 2배로 증가되었습니다." << endl;
  cout << "* 현재 " << (isAttack ? "공격력" : "방어력") <<
    ": " << (isAttack ? stats.displayAttack() : stats.displayDefence()) <<
    endl;
}
void DebugPrinter::printAttributeIncrease(
  bool isSuccess, int attributeIndex, int attributePoint, Status stats) {
  if (!isSuccess) {
    cout << "* 남은 능력치 포인트가 없습니다." << endl;
  } else {
    string attributeName;
    string attributeGet;
    switch (attributeIndex) {
    case 4:
      attributeName = "힘";
      attributeGet = stats.displayStrength();
      break;
    case 5:
      attributeName = "민첩";
      attributeGet = stats.displayAgility();
      break;
    case 6:
      attributeName = "지능";
      attributeGet = stats.displayIntelligence();
      break;
    default:
      attributeName = "Unknown";
      break;
    }
    cout << "* " << attributeName << "이 1 증가되었습니다." << endl;
    cout << "* 현재 " << attributeName << ": " << attributeGet << endl;
    cout << "* 남은 능력치 포인트: " << to_string(attributePoint) << endl;
  }
}
void DebugPrinter::printOverallState(
  Status stats, int potionHP, int potionMP, int attributePoint) {
  string printStr = "* ";
  printStr += "레벨 : " + stats.displayLevel();
  cout << printStr << endl;
  printStr = "* ";
  printStr += "HP : " + stats.displayHP();
  printStr += ", MP : " + stats.displayMP();
  printStr += ", 공격력 : " + stats.displayAttack();
  printStr += ", 방어력 : " + stats.displayDefence();
  printStr += ", 힘 : " + stats.displayStrength();
  printStr += ", 민첩 : " + stats.displayAgility();
  printStr += ", 지능 : " + stats.displayIntelligence();
  cout << printStr << endl;
  printStr = "* ";
  printStr += "남은 HP 포션 : " + to_string(potionHP);
  printStr += ", 남은 MP 포션 : " + to_string(potionMP);
  printStr += ", 남은 능력치 포인트 : " + to_string(attributePoint);
  cout << printStr << endl;
}
void DebugPrinter::printProgramEnd() {
  cout << "프로그램을 종료합니다." << endl;
}
