// Copyright (c) 2025 by ood11611doo. All rights reserved.

#include <iostream>
#include <string>
#include <cstdlib>
#include "DebugPrinter.h"

using namespace std; // NOLINT

void DebugPrinter::printErrorCode(EErrorCode code) {
  switch (code) {
    case EErrorCode::hpmpError:
      cout << "HP와 MP는 50보다 큰 값을 정해야 합니다."
           << "다시 입력해 주세요." << endl;
    break;
    case EErrorCode::attackDefenceError:
      cout << "공격력과 방어력은 0을 초과하는 값이 입력되어야 합니다."
           << "다시 입력해 주세요." << endl;
    break;
    case EErrorCode::attributesError:
      cout << "힘, 민첩, 지능은 0을 초과하고 총 합이 10을 넘어가지 않아야 합니다."
           << "다시 입력해 주세요." << endl;
    break;
    case EErrorCode::potionCountError:
      cout << "* 포션이 부족합니다." << endl;
      break;
    case EErrorCode::attributePointError:
      cout << "* 남은 능력치 포인트가 없습니다." << endl;
      break;
    default:
      cout << "Unknown error code." << endl;
      break;
  }
}
void DebugPrinter::printInputCode(EInputCode code, int additionalArgs) {
  switch (code) {
    case EInputCode::hpmpInput:
      cout << "HP와 MP를 입력해주세요: ";
    break;
    case EInputCode::attackDefenceInput:
      cout << "공격력과 방어력을 입력해주세요: ";
    break;
    case EInputCode::attributesInput:
      cout << "힘, 민첩, 지능을 입력해주세요: ";
    break;
    case EInputCode::potionInput:
      cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 "
           << to_string(additionalArgs) << "개)" << endl;
    break;
    default:
      cout << "Unknown input code." << endl;
      break;
  }
}
void DebugPrinter::printMessages(EMessages code, string additionalArgs) {
  switch (code) {
    case EMessages::selectionView:
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
      break;
    case EMessages::selectNumber:
      cout << "번호를 선택해주세요: ";
    break;
    case EMessages::levelUp:
      cout << "* 레벨업! 현재 레벨: " << additionalArgs << endl;
      cout << "* HP/MP 포션이 지급됩니다." << endl;
    break;
    case EMessages::programEnd:
      cout << "프로그램을 종료합니다." << endl;
    break;
    default:
      cout << "Unknown message code." << endl;
      break;
  }
}
void DebugPrinter::printStatEdit(EStatEdits code,
  Status* stats, int* potionHP, int* potionMP, int* attributePoint) {
  switch (code) {
    case EStatEdits::hpUpSuccess:
      cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
      cout << "* 남은 포션 수: " << to_string(*potionHP) << endl;
      break;
    case EStatEdits::mpUpSuccess:
      cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
      cout << "* 남은 포션 수: " << to_string(*potionMP) << endl;
      break;
    case EStatEdits::hpmpUpFailed:
      cout << "* 포션이 부족합니다." << endl;
      break;
    case EStatEdits::attackDouble:
      cout << "* 공격력이 2배로 증가되었습니다." << endl;
      cout << "* 현재 공격력: " << (*stats).displayAttack() << endl;
      break;
    case EStatEdits::defenceDouble:
      cout << "* 방어력이 2배로 증가되었습니다." << endl;
      cout << "* 현재 방어력: " << (*stats).displayDefence() << endl;
      break;
    case EStatEdits::strengthUpSuccess:
      cout << "* 힘이 1 증가되었습니다." << endl;
      cout << "* 현재 힘: " << (*stats).displayStrength() << endl;
      cout << "* 남은 능력치 포인트: " << to_string(*attributePoint) << endl;
      break;
    case EStatEdits::agilityUpSuccess:
      cout << "* 민첩이 1 증가되었습니다." << endl;
      cout << "* 현재 민첩: " << (*stats).displayAgility() << endl;
      cout << "* 남은 능력치 포인트: " << to_string(*attributePoint) << endl;
      break;
    case EStatEdits::intelligenceUpSuccess:
      cout << "* 지능이 1 증가되었습니다." << endl;
      cout << "* 현재 지능: " << (*stats).displayIntelligence() << endl;
      cout << "* 남은 능력치 포인트: " << to_string(*attributePoint) << endl;
      break;
    case EStatEdits::attributeUpFailed:
      cout << "* 남은 능력치 포인트가 없습니다." << endl;
      break;
    case EStatEdits::justDisplayStats:
      cout << "* 레벨 : " << (*stats).displayLevel() << endl;
      cout << "* HP : " << (*stats).displayHP()
           << ", MP : " << (*stats).displayMP()
           << ", 공격력 : " << (*stats).displayAttack()
           << ", 방어력 : " << (*stats).displayDefence()
           << ", 힘 : " << (*stats).displayStrength()
           << ", 민첩 : " << (*stats).displayAgility()
           << ", 지능 : " << (*stats).displayIntelligence()
           << endl;
      cout << "* 남은 HP 포션 : " << to_string(*potionHP)
           << ", 남은 MP 포션 : " << to_string(*potionMP)
           << ", 남은 능력치 포인트 : " << to_string(*attributePoint)
           << endl;
      break;
    default:
      cout << "Unknown edit code." << endl;
      break;
  }
}
