#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include "appitem.h"
#include "file_handler.h"
#include "desktop.h"
#include "data_vrom.h"
#include "data_vapps.h"
#include "data_vstore.h"
#include "interface.h"

int main() {

    setlocale(LC_ALL, "portuguese");
    interface_configure_cmd();

    // Splash Screen
    interface_jump_to_vcenter(2,0);
    interface_print_centralized_bar(INTERFACE_HSIZE, SYSTEM_NAME, 6);
    interface_print_centralized(INTERFACE_HSIZE, SYSTEM_VERSION);
    interface_print_centralized_nojump(INTERFACE_HSIZE, "");
    scanf("*%c");

    // Instantiation
    BASE_APP_ITEM vStore[VSTORE_ARRAY_ITEMMAX];
    BASE_APP_ITEM vApps[VAPPS_ARRAY_ITEMMAX];
    BASE_APP_ITEM vROM[VROM_ARRAY_ITEMMAX];
    int desktop[DESKTOP_GRID_WIDTH][DESKTOP_GRID_HEIGHT];

    // Initiation
    vStore_init(vStore);
    vApps_init(vApps);
    vROM_init(vROM);
    desktop_init(desktop);

    // Load vStore files, create one if doesn't exists.
    int i, tempUID, vStoreCount = 0;
    FILE* vStoreFile;
    int vStoreLoaded = 0;
    vStoreFile = fopen("vStore.mED", "r");
    if (vStoreFile == NULL) {
        fclose(vStoreFile);
        interface_print_bar(INTERFACE_HSIZE, 6);
        interface_print_centralized_bar(INTERFACE_HSIZE, "ERRO DE INICIALIZAÇÃO", 6);
        interface_print_bar(INTERFACE_HSIZE, 6);
        printf("\n");
        interface_print_centralized(INTERFACE_HSIZE, "O arquivo \"vStore.mED\" não foi carregado");
        interface_print_centralized(INTERFACE_HSIZE, "corretamente. A loja será preenchida com exemplos");
        interface_print_centralized(INTERFACE_HSIZE, "pré-definidos.");
        printf("\n");
        interface_print_centralized_nojump(INTERFACE_HSIZE, "Aperte qualquer tecla para continuar...");
        fflush(stdin);
        scanf("*%c");
        vStoreFile = fopen("vStore.mED", "w+");
        fileh_vstore_createExamples(vStoreFile);
        fclose(vStoreFile);
        vStoreLoaded = 1;
    } else {
        fclose(vStoreFile);
        vStoreLoaded = 1;
    }
    vStoreFile = fopen("vStore.mED", "r");
    vStoreCount = fileh_vstore_getAppCount(vStoreFile);
    fclose(vStoreFile);
    vStoreFile = fopen("vStore.mED", "r");
    for (i = 0; i < vStoreCount; ++i) {
        fscanf(vStoreFile, "%d %d %s", &vStore[i].appUID, &vStore[i].appSize, vStore[i].appName);
    }

    int cleanExit = 0;
    do {
        cleanExit = interface_main_show(vStore, vApps, vROM, desktop);
    } while (cleanExit != 1);

    return 0;
}