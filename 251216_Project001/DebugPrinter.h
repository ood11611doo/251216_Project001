// Copyright (c) 2025 by ood11611doo. All rights reserved.

#pragma once
#include <iostream>
#include <string>
#include "Status.h"

using namespace std; // NOLINT

enum class EErrorCode {
  defaultError = 0,
  hpmpError = 1,
  attackDefenceError = 2,
  attributesError = 3,
  potionCountError = 4,
  attributePointError = 5
};
enum class EInputCode {
  defaultCode = 0,
  hpmpInput = 1,
  attackDefenceInput = 2,
  attributesInput = 3,
  potionInput = 4
};
enum class EMessages {
  defaultCode = 0,
  selectionView = 1,
  selectNumber = 2,
  levelUp = 3,
  programEnd = 4
};
enum class EStatEdits {
  defaultCode = 0,
  hpUpSuccess = 1,
  mpUpSuccess = 2,
  hpmpUpFailed = 3,
  attackDouble = 4,
  defenceDouble = 5,
  strengthUpSuccess = 6,
  agilityUpSuccess = 7,
  intelligenceUpSuccess = 8,
  attributeUpFailed = 9,
  justDisplayStats = 10
};

class DebugPrinter {
 public:
  /**
   * @brief Logs a specific error code for debugging purposes.
   * @param code = Enum for what errors to print out.
   * @return void
   */
  static void printErrorCode(EErrorCode code);

  /**
   * @brief Logs a starting stat input related messages.
   * @param code = Enum for what input types to print out.
   * @param additionalArgs = Additional argument for input message (if needed).
   * @return void
   */
  static void printInputCode(EInputCode code, int additionalArgs = -1);

  /**
   * @brief Logs various messages during the program execution.
   * @param code = Enum for what messages to print out.
   * @param additionalArgs = Additional argument for message (if needed).
   * @return void
   */
  static void printMessages(EMessages code, string additionalArgs = "");

  /**
   * @brief Logs the result of stat edits and current status.
   * @param code = Enum for what stat edit result to print out.
   * @param stats = Pointer to Status object to get current stats.
   * @param potionHP = Pointer to current HP potion count.
   * @param potionMP = Pointer to current MP potion count.
   * @param attributePoint = Pointer to current attribute points.
   * @return void
   */
  static void printStatEdit(EStatEdits code,
    Status* stats, int* potionHP, int* potionMP, int* attributePoint);
};
