//
// Created by jpedro on 29/08/2017.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

int fileh_vstore_createExamples() {
    // Função criada para garantir a demonstração do programa. Caso não seja possível ler o arquivo de texto, será fornecido esta opção.
    int i, j, tempUID;
    FILE* file;
    fileh_file_init(file, "vStore");
    file = fopen("vStore.mED", "w+");
    if (file != NULL) {
        BASE_APP_ITEM _demoApps[5];
        const char *_nameList[5] = {
                "Camera",
                "Downloads",
                "Agenda",
                "Navegador",
                "Telefone"
        };
        srand(0);
        for (i = 0; i < 5; ++i) {
            do {
                tempUID = (rand() % 10000);
                _demoApps[i].appUID = tempUID;
            } while ((fileh_vstore_checkConflictApp(file, &_demoApps[i])) != 1);
            strcpy(_demoApps[i].appName, _nameList[i]);
            _demoApps[i].appSize = 10;
            fileh_vstore_insertApp(file, _demoApps[i]);
        }

        fclose(file);
        return;
    }
}

int fileh_vstore_insertApp(FILE* file, BASE_APP_ITEM _newApp) {
    fprintf(file, "%d %d %s\n", _newApp.appUID, _newApp.appSize, _newApp.appName);
    return 0;
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

int fileh_vstore_checkConflictApp(FILE* file, BASE_APP_ITEM* _App) {
    int appCount = fileh_vstore_getAppCount(file);
    int i;
    BASE_APP_ITEM _tempApp = Appitem_create_invalid();
    for (i = 0; i < appCount; ++i) {
        if (feof(file)) {
            return 0; // There isn't any conflict.
        }
        fscanf(file, "%d %d %s", &_tempApp.appUID, &_tempApp.appSize, &_tempApp.appName);
        if (_App->appUID == _tempApp.appUID) {
            return 1; // There is a conflict.
        }
    }
    return 0; // There isn't any conflict.
}