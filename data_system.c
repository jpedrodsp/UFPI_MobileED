//
// Created by jpedro on 02/09/2017.
//

#include "data_system.h"
#include "appitem.h"
#include "data_vstore.h"
#include "data_vapps.h"
#include "data_vrom.h"
#include "file_handler.h"
#include <string.h>
#include <stdio.h>

/*
 * O arquivo "data_system.c" contém funções que se utilizam das especificações do Trabalho Prático 01.
 */


// Implementar uma função que leia um arquivo texto e carregue as informações para um vetor de estrutura do tipo App.
int MobileED_fill_vStore(FILE* file, BASE_APP_ITEM* _vStore){
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
BASE_APP_ITEM MobileED_vStore_getElements(BASE_APP_ITEM* _vStore, int index){
    return vStore_getApp(_vStore, index);
}

// Implementar uma função que copie um elemento de um vetor para outro;
int MobileED_install_copy_from_vStore(BASE_APP_ITEM* _vStore, BASE_APP_ITEM* _vApps, int index){
    BASE_APP_ITEM _tempApp = Appitem_create_invalid();
    _tempApp = vStore_getApp(_vStore, index);

}

// Implementar uma função que atualize elementos de uma matriz;
int MobileED_install_update_element(BASE_APP_ITEM* _vApps, BASE_APP_ITEM* _Element){
    return 0;
}

// Implementar uma função que copie um elemento de uma matriz para um vetor;
int MobileED_execute_app(BASE_APP_ITEM* _vApps, BASE_APP_ITEM* _vROM, int UID){
    return 0;
}

// Implementar uma função que liste os elementos de um vetor;
int MobileED_print_ROM(BASE_APP_ITEM* _vROM){
    return 0;
}

// Implementar uma função que permita consultar os elementos de um vetor;
int MobileED_vROM_getElement(BASE_APP_ITEM* _vROM, int UID){
    return 0;
}

// Implementar uma função que permita excluir elementos de um vetor;
int MobileED_vROM_stop(BASE_APP_ITEM* _vROM, int UID){
    return 0;
}

// Implementar uma função que permita consultar os elementos de um vetor;
int MobileED_vApps_getElement(BASE_APP_ITEM* _vApps, int UID){
    return 0;
}

// Implementar uma função que permita excluir elementos de um vetor;
int MobileED_vApps_removeApp(BASE_APP_ITEM* _vApps, int UID){
    return 0;
}

// Implementar uma função que atualize elementos de uma matriz;
int MobileED_vApps_updateApp(BASE_APP_ITEM* _vApps, BASE_APP_ITEM* _updatedApp){
    return 0;
}