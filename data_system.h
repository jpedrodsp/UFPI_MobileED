//
// Created by jpedro on 02/09/2017.
//

#ifndef REWRITE_MOBILEED_DATA_SYSTEM_H
#define REWRITE_MOBILEED_DATA_SYSTEM_H

#include <stdio.h>
#include "appitem.h"
#include "desktop.h"

#define SYSTEM_NAME "MobileED"
#define SYSTEM_VERSION "v0.1a"
#define SYSTEM_APPMAX 25
#define SYSTEM_TIME "09:00"

#define SYSTEM_USER_NAME "João Pedro"

int MobileED_fill_vStore(FILE* file, BASE_APP_ITEM* _vStore);
BASE_APP_ITEM MobileED_vStore_getElements(BASE_APP_ITEM* _vStore, int index);
int MobileED_install_copy_from_vStore(BASE_APP_ITEM* _vStore, BASE_APP_ITEM* _vApps, int desktop[DESKTOP_GRID_WIDTH][DESKTOP_GRID_HEIGHT], int index);
int MobileED_install_update_element(BASE_APP_ITEM* _vApps, BASE_APP_ITEM* _Element);
int MobileED_execute_app(BASE_APP_ITEM* _vApps, BASE_APP_ITEM* _vROM, int UID);
int MobileED_print_ROM(BASE_APP_ITEM* _vROM);
int MobileED_vROM_getElement(BASE_APP_ITEM* _vROM, int UID);
int MobileED_vROM_stop(BASE_APP_ITEM* _vROM, int UID);
int MobileED_vApps_getElement(BASE_APP_ITEM* _vApps, int UID);
int MobileED_vApps_removeApp(BASE_APP_ITEM* _vApps, int UID);
int MobileED_vApps_updateApp(BASE_APP_ITEM* _vApps, BASE_APP_ITEM* _updatedApp);

#endif //REWRITE_MOBILEED_DATA_SYSTEM_H
