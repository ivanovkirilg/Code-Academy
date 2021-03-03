/*  Задача 5. Дефинирайте потребителски тип към масив. 
    Инициализирайте масива, изведете наконзолата. */

#include <stdio.h>

typedef char t_hText[64];
typedef char t_lText[2048];

int main() {
    t_hText title = "The Life and Grievances of a Dead Man";
    t_lText synopsis = "In present-day Salem, a serial killer known as the Bell Killer begins murdering\n"
    "seemingly unconnected victims. Police Detective Ronan O'Connor is able to track down\n" 
    "the Bell Killer, but is thrown out of a window and shot to death during a fight.\n"
    "He returns in the form of a ghost, and learns that in order to reach the afterlife\n"
    "and meet his wife Julia, he must first discover the identity of his killer.\n"
    "With the help of Abigail, the ghost of a Puritan child, Ronan is able to use\n"
    "his ghostly abilities to return to the fight scene, and discovers that a medium\n"
    "named Joy witnessed the fight, and is now hiding in a church.";

    printf("Book: %s\nPlot: %s", title, synopsis);

    return 0;
}