//
// Created by JPDSP on 01/09/2017.
//

#include <stdio.h>
#include <string.h>
#include "appitem.h"
#include "desktop.h"
#include "data_vapps.h"

void desktop_init(int desktop[DESKTOP_GRID_WIDTH][DESKTOP_GRID_HEIGHT]){
    // Preenche a área de trabalho com UIDs nulos.
    int i, j;
    for (i = 0; i < DESKTOP_GRID_HEIGHT; ++i) {
        for (j = 0; j < DESKTOP_GRID_WIDTH; ++j) {
            desktop[i][j] = APPITEM_NULL_UID;
        }
    }
}

void desktop_print(int desktop[DESKTOP_GRID_WIDTH][DESKTOP_GRID_HEIGHT], BASE_APP_ITEM* _vAppsArray){
    // Preenche a área de trabalho com UIDs nulos.
    int i, j;
    char desktopName[128];
    for (i = 0; i < DESKTOP_GRID_HEIGHT; ++i) {
        for (j = 0; j < DESKTOP_GRID_WIDTH; ++j) {
            if (desktop[i][j] != APPITEM_NULL_UID) {
                int index = vApps_find_byUID(_vAppsArray, desktop[i][j]);
                BASE_APP_ITEM _tempItem = vApps_return_byIndex(_vAppsArray, index);
                strcpy(desktopName, _tempItem.appName);
                printf("(ID.: %04d) %s\n", _tempItem, desktopName);
            }
        }
    }
}


int desktop_add_item(int desktop[DESKTOP_GRID_WIDTH][DESKTOP_GRID_HEIGHT], int UID) {
    // Adiciona o aplicativo para a área de trabalho.
    // Se adicionar corretamente, retorna 0. Caso contrário, como por exemplo se não houver mais espaço, retorna 1.
    int i, j;
    for (i = 0; i < DESKTOP_GRID_HEIGHT; ++i) {
        for (j = 0; j < DESKTOP_GRID_WIDTH; ++j) {
            if (desktop[i][j] == APPITEM_NULL_UID) {
                desktop[i][j] = UID;
                return 0;
            }
        }
    }
    return 1;
}

int desktop_remove_item(int desktop[DESKTOP_GRID_WIDTH][DESKTOP_GRID_HEIGHT], int UID) {
    // Remove o aplicativo da área de trabalho.
    // Se remover, retorna 0. Caso contrário, retorna 1.
    int i, j;
    for (i = 0; i < DESKTOP_GRID_HEIGHT; ++i) {
        for (j = 0; j < DESKTOP_GRID_WIDTH; ++j) {
            if (desktop[i][j] == UID) {
                desktop[i][j] = APPITEM_NULL_UID;
                return 0;
            }
        }
    }
    return 1;
}