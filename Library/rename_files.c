#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char path[256];
    getcwd(path, 256);
    DIR *dir = opendir(path);
    struct dirent *entity;

    if (argc != 3) {
        printf("%s [add/del] [prefix]", argv[0]);
        exit(1);
    }

    char newname[48] = { '\0' };
    char prefix[32];
    strcpy(prefix, argv[2]);
    
    entity = readdir(dir);
    entity = readdir(dir);
    
    if (strcmp(argv[1], "add") == 0) {
        printf("Adding prefix %s\n", prefix);
        while (entity = readdir(dir)) {
            strcpy(newname, prefix);
            strcat(newname, entity->d_name);
            rename(entity->d_name, newname);
        }
    } else if (strcmp(argv[1], "del") == 0) {
        printf("Deleting prefix %s\n", prefix);
        while (entity = readdir(dir)) {
            for (int i = 0; i < strlen(prefix); i++) {
                if (prefix[i] != entity->d_name[i])
                    goto skip;
            }
            strcpy(newname, entity->d_name + strlen(prefix));
            rename(entity->d_name, newname);
            skip: ;
        }
    } else {
        printf("%s [add/del] [prefix]", argv[0]);
    }

    printf("Done");
    
    return 0;
}
