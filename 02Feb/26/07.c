/*  Задача 7. Напишете масив от структури наречен kaytab[ ], като използвате тази, 
    дефинирана в горното упражнение - потребителски тип key_t, която съдържа 
    символен низ и число. Инициализирайте масива с всички ключови думи на С. */

#include <stdio.h>
#include <string.h>

typedef struct {
    char holder[31];
    unsigned char len;
} key_t;

int main() {
    key_t keytab[] = { "auto", strlen("auto"), "break", strlen("break"), "case", strlen("case"), "char", strlen("char"),
        "const", strlen("const"), "continue", strlen("continue"), "default", strlen("default"), "do", strlen("do"), 
        "int", strlen("int"), "long", strlen("long"), "register", strlen("register"), "return", strlen("return"), 
        "short", strlen("short"), "signed", strlen("signed"), "sizeof", strlen("sizeof"), "static", strlen("static"),
        "struct", strlen("struct"), "switch", strlen("switch"), "typedef", strlen("typedef"), "union", strlen("union"), 
        "unsigned", strlen("unsigned"), "void", strlen("void"), "volatile", strlen("volatile"), "while", strlen("while"), 
        "double", strlen("double"), "else", strlen("else"), "enum", strlen("enum"), "extern", strlen("extern"), 
        "float", strlen("float"), "for", strlen("for"), "goto", strlen("goto"), "if", strlen("if") };

    for (int i = 0; i < sizeof(keytab)/sizeof(keytab[0]); i++) {
        printf("%2d: %-3s,\tlength: %d\n", i+1, keytab[i].holder, keytab[i].len);
    }

    return 0;
}