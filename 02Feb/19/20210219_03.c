/* Задача 3. Указатели към структура, предаване на структура на функция по стойност и по референция */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* id, title, author, subject */
struct tagPaper {
    unsigned int m_bookID;
    char m_strTitle[64];
    char m_strAuthor[64];
    char m_strSubject[256];
};

void presentPaper(struct tagPaper paper) {
    printf("\n'%s'\n\tby %s\n\tID: %d\nABSTRACT: %s\n", 
    paper.m_strTitle, paper.m_strAuthor, paper.m_bookID, paper.m_strSubject);
}

void presentPaperByPointer(struct tagPaper *paper) {
    printf("\n'%s'\n\tby %s\n\tID: %d\nABSTRACT: %s\n", 
    paper->m_strTitle, paper->m_strAuthor, paper->m_bookID, paper->m_strSubject);
}

int main() {
    struct tagPaper paper0 = { rand(), "The Troubles of a Troubled Troublemaker", "Terrance Trudeau",
    "This paper aims to analyse what juvenile delinquents usually\n"
    "go through in their childhood, and what kind of problems\n"
    "typically lead to deviant behaviour." };

    struct tagPaper paper1 = { .m_strAuthor = "Aleen Albany", .m_strTitle = "All Alien Alliances Are Actionable"};
    paper1.m_bookID = rand();
    strcpy(paper1.m_strSubject, "All these darn Mexicans better get off my lawn! I can sue you!");

    presentPaper(paper0);
    /* Waits for any input before printing the second paper */
    scanf(".");
    presentPaperByPointer(&paper1);

    return 0;
}
