/*  Задача 3. Напишете макрос с един параметър, който печата съобщение, 
    само при дефиниран макрос DEBUG. Ако DEBUG не е дефиниран, не печата нищо. */

#include <stdio.h>
#ifdef DEBUG
    #define DEBUGMSG(msg) {\
        printf("DEBUG: %s\n", msg); }
#else
    #define DEBUGMSG(notdef)
#endif

int main() {
    DEBUGMSG("test");

    return 0;
}
