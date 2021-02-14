/* Задача 5. Разширяване на заделена памет с realloc */

/*  Програмата дефакто копира ред по ред текстов файл.
    Предназначена е за изобразяване на ASCII art.
    Приложеният файл 20210212_05.txt е логото на VSCode. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *imageFile = NULL;
    char *image = NULL;
    const size_t buffSize = 36;
    char buffer[buffSize];

    imageFile = fopen("20210212_05.txt", "r");
    if (imageFile == NULL) {
        printf("File open err");
        exit(1);
    }

    image = (char*) malloc(buffSize);
    if (image == NULL) {
        printf("Alloc err");
        exit(1);
    }
    /* beware garbage values; we only need one '\0' because we use strcat() */
    /* OR we could use calloc() instead of malloc() */
    *image = '\0';

    /* Copy line from file into buffer. fgets() returns NULL when it reaches EOF */
    while (fgets(buffer, buffSize, imageFile) != NULL) {
        /* increase the dynamic string size, leaving one for '\0' */
        image = realloc(image, strlen(image) + strlen(buffer) + 1u);
        if (image == NULL) {
            printf("Realloc err");
            exit(1);
        }
        /* add buffer contents to dynamic string */
        strcat(image, buffer);
    }
    fclose(imageFile);

    printf("%s", image);

    free(image);
    
    return 0;
}
