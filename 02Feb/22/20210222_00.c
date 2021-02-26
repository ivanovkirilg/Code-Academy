/* #include <stdio.h>

int main() {
    struct tagTest {
        char a;
        short b;
        int c;
        double x;
    } __attribute__((packed));

    struct tagTest testst = { 0xAA, 0xBBBB, 0xCCCCCCCC, 6 };
    
    printf("%d\n", sizeof(testst));
    
    unsigned char *pr = (unsigned char *) &testst;

    for (int i = 0; i < sizeof(testst); pr++, i++) {
        printf("%d\t", *pr);
        switch (i) {
            case 0: case 2: case 7: case 11: putchar('\n');
        }
    }

    return 0;
} */

/* #include <stdio.h>

int main() {
    union tagUniTest {
        int m_iNum;
        float m_fRate;
        union tagUniTest *puniNext;
    };

    union tagUniTest uniVar = { 0 };
    union tagUniTest *puniVal = &uniVar;

    uniVar.m_iNum = 13;
    puniVal->m_fRate = 6.5;

    printf("%x", puniVal->m_iNum);
    
    return 0;
} */

/* #include <stdio.h>

int main() {
    enum state {READY, WORKING, ERROR};
    
    enum even {ZERO = 0, TWO = 2, FOUR = 4, SIX = 6, EIGHT = 8};
    enum even n = TWO;

    printf("%d\n", n);
    n++;
    printf("%d\n", n);

    
    return 0;
} */

/* #include <stdio.h>

union tagData {
    int m_iValue;
    float m_fValue;
    char m_szText[25];
}__attribute__((packed));

int main() {
    union tagData myData = { 65 };
    printf("Memory used: %d\n", sizeof(myData));
    printf("iValue: %d, fValue: %.45f, Text: %s\n", myData.m_iValue, myData.m_fValue, myData.m_szText);

    return 0;
} */

#include <stdio.h>

enum tagType { INT, STR };
union tagValueHolder {
    int number;
    char string[64];
};

struct tagVariable {
    enum tagType type;
    union tagValueHolder value;
};

int printValue(struct tagVariable *pVar) {
    if (pVar->type == INT) {
        printf("Integer: %d\n", pVar->value.number);
    } else {
        printf("String: %s\n", pVar->value.string);
    }
    return pVar->type;
}

int main() {
    struct tagVariable var0 = { INT, .value.number = 555 };
    struct tagVariable var1 = { STR, .value.string = "555!" };

    printValue(&var0);
    printValue(&var1);

    var0.type = STR;
    printValue(&var0);
    
    return 0;
}
