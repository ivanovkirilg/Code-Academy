#ifndef FLEET_GENERATION_H_
#define FLEET_GENERATION_H_

#include "BattleField.h"

/* Reads input from stdin and generates both fleets from it */
void generateFleets(BattleField *battleField);

/* Allocates memory for each terran ship and initializes it from 'terranFleetStr' */
/* Initializes the terranFleet vector and pushes each ship */
void generateTerranFleet(BattleField *battleField, const char *terranFleetStr);

/* Allocates memory for each protoss ship and initializes it from 'protossFleetStr' */
/* Initializes the protossFleet vector and pushes each ship */
void generateProtossFleet(BattleField *battleField, const char *protossFleetStr);

#endif /* FLEET_GENERATION_H_ */