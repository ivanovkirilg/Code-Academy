/*  Задача 1. За да направи една етажерка, дърводелец се нуждае от следните компоненти: 
    4 дълги дъски, 6 къси дъски, 12 малки скоби, 2 големи скоби и 14 винта. 
    Дърводелецът има на склад А дълги дъски, В къси дъски, С малки скоби, D големи скоби и E винта. 
    Колко етажерки може да направи дърводелецът?    
    Изход: С наличните на склад материали 
    (33 дълги дъски, 55 къси дъски, 88 малки скоби, 22 големи скоби и 99 винта) 
    дърводелецът може да направи 7 етажерки.  */

#include <stdio.h>

typedef struct tagComponents {
    int boardsLong;
    int boardsShort;
    int bracesSmall;
    int bracesLarge;
    int screws;
} t_comp;

int itemsFromParts(const t_comp *itemParts, t_comp *availableParts);

int main() {
    const t_comp shelfParts = { 4, 6, 12, 2, 14 };
    t_comp inventory = { 33, 55, 88, 22, 99 };
    
    printf("Starting inventory:\n"
        "%d long boards, %d short boards, %d small braces, %d large braces, %d screws.\n",
        inventory.boardsLong, inventory.boardsShort, inventory.bracesSmall, inventory.bracesLarge, inventory.screws);
    
    printf("That is enough for %d shelves.\n", itemsFromParts(&shelfParts, &inventory));

    printf("Remaining inventory:\n"
        "%d long boards, %d short boards, %d small braces, %d large braces, %d screws.\n",
        inventory.boardsLong, inventory.boardsShort, inventory.bracesSmall, inventory.bracesLarge, inventory.screws);

    return 0;
}

int itemsFromParts(const t_comp *itemParts, t_comp *availableParts) {
    int maxItems = 0;
    maxItems = availableParts->boardsLong / itemParts->boardsLong;
    if (availableParts->boardsShort / itemParts->boardsShort < maxItems)
        maxItems = availableParts->boardsShort / itemParts->boardsShort;
    if (availableParts->bracesSmall / itemParts->bracesSmall < maxItems)
        maxItems = availableParts->bracesSmall / itemParts->bracesSmall;
    if (availableParts->bracesLarge / itemParts->bracesLarge < maxItems)
        maxItems = availableParts->bracesLarge / itemParts->bracesLarge;
    if (availableParts->screws / itemParts->screws < maxItems)
        maxItems = availableParts->screws / itemParts->screws;
    
    availableParts->boardsLong -= maxItems * itemParts->boardsLong;
    availableParts->boardsShort -= maxItems * itemParts->boardsShort;
    availableParts->bracesSmall -= maxItems * itemParts->bracesSmall;
    availableParts->bracesLarge -= maxItems * itemParts->bracesLarge;
    availableParts->screws -= maxItems * itemParts->screws;
    
    return maxItems;
}