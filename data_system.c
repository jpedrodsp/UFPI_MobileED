//
// Created by jpedro on 02/09/2017.
//

#include "data_system.h"
#include "appitem.h"
#include "data_vstore.h"
#include "data_vapps.h"
#include "data_vrom.h"
#include "file_handler.h"
#include "desktop.h"
#include <string.h>
#include <stdio.h>

/*
 * O arquivo "data_system.c" contém funções que se utilizam das especificações do Trabalho Prático 01.
 */


// Implementar uma função que leia um arquivo texto e carregue as informações para um vetor de estrutura do tipo App.
int MobileED_fill_vStore(FILE* file, BASE_APP_ITEM* _vStore) {
    int appCount = fileh_vstore_getAppCount(file);
    if (appCount == 0) {
        return 1;
    } else {
        int i;
        for (i = 0; i < appCount; ++i) {
            fscanf(file, "%d %d %s", &_vStore[i].appUID, &_vStore[i].appSize, &_vStore[i].appName);
        }
    }
    return 0;
}

// Implementar uma função que permita consultar elementos de um vetor;
BASE_APP_ITEM MobileED_vStore_getElements(BASE_APP_ITEM* _vStore, int index) {
    return vStore_getApp(_vStore, index);
}

// Implementar uma função que copie um elemento de um vetor para outro;
int MobileED_install_copy_from_vStore(BASE_APP_ITEM* _vStore, BASE_APP_ITEM* _vApps, int desktop[DESKTOP_GRID_WIDTH][DESKTOP_GRID_HEIGHT], int index) {
    int ec;
    BASE_APP_ITEM _tempApp = Appitem_create_invalid();
    _tempApp = vStore_getApp(_vStore, index);
    ec = vApps_install(_vApps, &_tempApp);
    if (ec == 0) {
        desktop_add_item(desktop, _tempApp.appUID);
        return 0; // App installed sucessfully and added to Desktop
    } else {
        return 1; // App not installed.
    }
}

// Implementar uma função que atualize elementos de uma matriz;
int MobileED_install_update_element(BASE_APP_ITEM* _vApps, BASE_APP_ITEM* _Element) {
    return 0;
}

// Implementar uma função que copie um elemento de uma matriz para um vetor;
/*int MobileED_execute_app(BASE_APP_ITEM* _vApps, BASE_APP_ITEM* _vROM, int UID) {
    // Já existe a função: vApps_execute_app();
    return 0;
}*/

// Implementar uma função que liste os elementos de um vetor;
/*int MobileED_print_ROM(BASE_APP_ITEM* _vROM) {
 *
 * Desnecessária. Já implementada diretamente.
    int i;
    int count = vROM_return_count(_vROM);
    for (i = 0; i < count; ++i) {
        printf("\t[UID %04d.: %s (TAM: %2d Mb)\n", _vROM[i].appUID, _vROM[i].appName, _vROM[i].appSize);
    }
    return 0;
}*/

// Implementar uma função que permita consultar os elementos de um vetor;
/*
    Desnecssária. Implementada diretamente a fim de evitar um stack overflow.

int MobileED_vROM_getElement(BASE_APP_ITEM* _vROM, int UID) {
    int index = vROM_find_byUID(_vROM, UID);
    if (index != -1) {
        return _vROM[index].appUID;
    } else {
        return -1;
    }
}
*/

// Implementar uma função que permita excluir elementos de um vetor;
int MobileED_vROM_stop(BASE_APP_ITEM* _vROM, int UID) {
    return 0;
}

// Implementar uma função que permita consultar os elementos de um vetor;
int MobileED_vApps_getElement(BASE_APP_ITEM* _vApps, int UID) {
    return 0;
}

// Implementar uma função que permita excluir elementos de um vetor;
int MobileED_vApps_removeApp(BASE_APP_ITEM* _vApps, int UID) {
    return 0;
}

// Implementar uma função que atualize elementos de uma matriz;
int MobileED_vApps_updateApp(BASE_APP_ITEM* _vApps, BASE_APP_ITEM* _updatedApp) {
    return 0;
}