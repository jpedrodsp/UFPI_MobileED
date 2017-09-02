//
// Created by jpedro on 29/08/2017.
//

#include <stdio.h>
#include <string.h>
#include "file_handler.h"
#include "appitem.h"

int fileh_file_init(FILE* file, const char* filename){
    // Garante a existência do arquivo.
    char newName[256];
    strcpy(newName, filename);
    strcat(newName, ".mED");

    file = fopen(newName, "r");
    if (file == NULL) {
        file = fopen(newName, "w+");
        fclose(file);
    } else {
        fclose(file);
    }
}

int fileh_vstore_insertApp(FILE* file, BASE_APP_ITEM _newApp) {
    fprintf(file, "%d %d %s\n", _newApp.appUID, _newApp.appSize, _newApp.appName);
}

int fileh_vstore_getAppCount(FILE* file) {
    int appCount = 0;
    do {
        char buffer[256 + 4 + 4];
        fgets(NULL, 264, file);
        if (feof(file)){
            break;
        } else {
            appCount++;
        }
    } while (1);
    return appCount;
}