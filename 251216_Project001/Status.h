// Copyright (c) 2025 by ood11611doo. All rights reserved.

#pragma once
#include <iostream>
#include <string>

using namespace std; // NOLINT

class Status {
  // 0: HP, 1: MP, 2: Attack, 3: Defence
  // 4: Strength, 5: Agility, 6: Intelligence
  int stats[7];
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

  // statIndex: 4-6 (only for 3 attributes)
  bool addOneStat(int statIndex, int* statPoint);

  void levelUp(int* potionHP, int* potionMP, int* statPoint);

  // From down here is all display functions for debugging
  // (that returns string for main use)
  string displayLevel();
  string displayHP();
  string displayMP();
  string displayAttack();
  string displayDefence();
  string displayStrength();
  string displayAgility();
  string displayIntelligence();
};
