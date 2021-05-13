#include "FleetGeneration.h"
#include "BattleField.h"
#include "Ships.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Reads input from stdin and generates both fleets from it */
void generateFleets(BattleField *battleField) {
  const int lineEnd = 2; /* For '\n' + '\0' */
  const int buffSize = 50 + lineEnd;
  char terranFleet[buffSize];
  char protossFleet[buffSize];

  /* Terran fleet */
  fgets(terranFleet, buffSize, stdin);
  
  /* Check input for valid number of ships */
  if (terranFleet[strlen(terranFleet) - 1] != '\n') {
    fprintf(stderr, "%s: Maximum number of Terran ships is %d per fleet.\n", __func__, buffSize - lineEnd);
    exit(EXIT_FAILURE);
  }
  if (terranFleet[0] == '\0' || terranFleet[0] == '\n') {
    fprintf(stderr, "%s: Terran fleet should have at least one ship\n", __func__);
    exit(EXIT_FAILURE);
  }

  terranFleet[strlen(terranFleet) - 1] = '\0';
  generateTerranFleet(battleField, terranFleet);


  /* Protoss fleet */
  fgets(protossFleet, buffSize, stdin);
  
  /* Check input for valid number of ships */
  if (protossFleet[strlen(protossFleet) - 1] != '\n') {
    fprintf(stderr, "%s: Maximum number of Protoss ships is %d per fleet.\n", __func__, buffSize - lineEnd);
    exit(EXIT_FAILURE);
  }
  if (protossFleet[0] == '\0' || protossFleet[0] == '\n') {
    fprintf(stderr, "%s: Protoss fleet should have at least one ship\n", __func__);
    exit(EXIT_FAILURE);
  }

  protossFleet[strlen(protossFleet) - 1] = '\0';
  generateProtossFleet(battleField, protossFleet);
}

/* Allocates memory for each terran ship and initializes it from 'terranFleetStr' */
/* Initializes the terranFleet vector and pushes each ship */
void generateTerranFleet(BattleField *battleField, const char *terranFleetStr) {
  vectorInit(&(battleField->terranFleet), strlen(terranFleetStr));

  for (int i = 0; terranFleetStr[i] != '\0'; i++) {
    Ship *newShip = (Ship *) malloc(sizeof(Ship));

    if (newShip == NULL) {
      fprintf(stderr, "%s: memory allocation failed.\n", __func__);
      exit(EXIT_FAILURE);
    }

    if (terranFleetStr[i] == 'v') {
      initializeViking(newShip, i);
    } else if (terranFleetStr[i] == 'b') {
      initializeBattleCruiser(newShip, i);
    } else {
      fprintf(stderr, "%s: Unexpected ship symbol %c\n", __func__, terranFleetStr[i]);
      exit(EXIT_FAILURE);
    }

    if ( vectorPush(&(battleField->terranFleet), newShip) ) {
      fprintf(stderr, "%s: Failed to add new ship.\n", __func__);
      exit(EXIT_FAILURE);
    }
  }
}

/* Allocates memory for each protoss ship and initializes it from 'protossFleetStr' */
/* Initializes the protossFleet vector and pushes each ship */
void generateProtossFleet(BattleField *battleField, const char *protossFleetStr) {
  vectorInit(&(battleField->protossFleet), strlen(protossFleetStr));

  for (int i = 0; protossFleetStr[i] != '\0'; i++) {
    Ship *newShip = (Ship *) malloc(sizeof(Ship));
    
    if (newShip == NULL) {
      fprintf(stderr, "%s: memory allocation failed.\n", __func__);
      exit(EXIT_FAILURE);
    }
    
    if (protossFleetStr[i] == 'p') {
      initializePhoenix(newShip, i);
    } else if (protossFleetStr[i] == 'c') {
      initializeCarrier(newShip, i);
    } else {
      fprintf(stderr, "%s: Unexpected ship symbol %c\n", __func__, protossFleetStr[i]);
      exit(EXIT_FAILURE);
    }

    if ( vectorPush(&(battleField->protossFleet), newShip) ) {
      fprintf(stderr, "%s: Failed to add new ship.\n", __func__);
      exit(EXIT_FAILURE);
    }
  }
}
