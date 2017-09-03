//
// Created by jpedro on 02/09/2017.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "interface.h"
#include "data_system.h"
#include "appitem.h"
#include "desktop.h"
#include "data_vstore.h"
#include "data_vapps.h"
#include "data_vrom.h"

// Interface Chart

// Main Menu
    // Desktop
    // vStore
        // Show vStore Apps
        // Install an App
    // vApps
        // Show Installed Apps
        // Uninstall an App
    // vROM
        // Show Apps
        // Stop an App

void interface_configure_cmd() {
    // Define o tamanho do prompt de comando para 60x30

    /*char text[32];
    strcpy(text, "mode CON: COLS=");
    strcat(text, INTERFACE_HSIZE);
    system(text);*/
    system("mode CON: COLS=60 LINES=40");


}

void interface_print_bar (int h_size, int barChar) {
    int i;
    for (i = 0; i < h_size; ++i) {
        printf("%c", barChar);
    }
    printf("\n");
}

void interface_print_centralized (int h_size, const char* text) {
    int i;
    int size = strlen(text);
    int blocks = (h_size - 2 - size) / 2;
    for (i = 0; i < blocks; ++i) {
        printf(" ");
    }
    printf(" ");
    printf("%s", text);
    /*printf(" ");
    for (i = 0; i < blocks; ++i) {
        printf(" ");
    }*/
    printf("\n");
}

void interface_print_centralized_bar (int h_size, const char* text, int barChar) {
    int i;
    int size = strlen(text);
    int blocks = (h_size - 2 - size) / 2;
    for (i = 0; i < blocks; ++i) {
        printf("%c", barChar);
    }
    printf(" ");
    printf("%s", text);
    printf(" ");
    for (i = 0; i < blocks; ++i) {
        printf("%c", barChar);
    }
    if (size % 2 == 1) {
        printf("%c", barChar);
    }
    printf("\n");
}


int interface_main_show(BASE_APP_ITEM* vStore, BASE_APP_ITEM* vApps, BASE_APP_ITEM* vROM, int desktop[DESKTOP_GRID_WIDTH][DESKTOP_GRID_HEIGHT]){
    int option;
    do {
        int i;
        system("cls");
        interface_print_bar(INTERFACE_HSIZE, 6);
        printf("%s | %s %s\n", SYSTEM_TIME, SYSTEM_NAME, SYSTEM_VERSION);
        printf("Bem-vindo, %s!\n", SYSTEM_USER_NAME);
        interface_print_bar(INTERFACE_HSIZE, 6);
        printf("\n");
        desktop_print(desktop, vApps);
        printf("\n### Escolha uma opção abaixo: \n");
        printf("1. %s\n", VSTORE_NAME);
        printf("2. %s\n", VAPPS_NAME);
        printf("3. %s\n", VROM_NAME);
        printf("\n0. Sair do aplicativo\n");
        printf("\nDigite uma opção: \n");

        fflush(stdin);
        scanf("%d", &option);

        switch (option) {
            case 0:
                return interface_main_to_exit();
                break;
            case 1:
                break;
        }
    } while (option != 0 && option != 1 && option != 2 && option != 3);
}

int interface_main_to_exit() {
    int option, i;
    do {
        system("cls");
        interface_print_bar(INTERFACE_HSIZE, 6);
        interface_print_centralized_bar(INTERFACE_HSIZE, "SAIR DO PROGRAMA?", 6);
        interface_print_bar(INTERFACE_HSIZE, 6);
        printf("\n");
        interface_print_centralized(INTERFACE_HSIZE, "Deseja sair do programa?");
        interface_print_centralized(INTERFACE_HSIZE, "Digite 1 para sair.");
        system("pause");

    } while (option != 1 && option != 0);
}

