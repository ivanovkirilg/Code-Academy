/* Задача 2. Инициализиране на структура, вложени структури */

#include <stdio.h>

struct tagDetail {
    unsigned m_uAcadID;
    char m_strAcadName[BUFSIZ];
    char m_strAcadUrl[BUFSIZ];
};

struct tagCadet {
    unsigned m_uCadetId;
    char m_strName[BUFSIZ];
    float m_fAverageRating;
    struct tagDetail m_detail;
};

int main() {
    struct tagCadet someCadet = { 553, "Toshko", .m_fAverageRating = 3.3, 
        .m_detail.m_uAcadID = 1053, .m_detail.m_strAcadName = "Cade Ocademy", "https://codeacademy.bg/" };
    
    printf("Cadet ID: %d\n", someCadet.m_uCadetId);
    printf("Name: %s\n", someCadet.m_strName);
    printf("Average rating: %.2f\n", someCadet.m_fAverageRating);
    printf("Academy ID: %d\n", someCadet.m_detail.m_uAcadID);
    printf("Academy name: %s\n", someCadet.m_detail.m_strAcadName);
    printf("URL: %s\n", someCadet.m_detail.m_strAcadUrl);
    
    return 0;
}
