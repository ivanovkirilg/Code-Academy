#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BattleField.h"
#include "FleetGeneration.h"

int main() {
  BattleField battleField;
  generateFleets(&battleField);
  startBattle(&battleField);
  deinit(&battleField);

  return EXIT_SUCCESS;
}
