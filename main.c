#include <stdio.h>
#include <string.h>
#include <locale.h>
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

    int cleanExit = 0;
    do {
        cleanExit = interface_main_show(vStore, vApps, vROM, desktop);
    } while (cleanExit != 1);

    return 0;
}