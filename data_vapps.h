//
// Created by JPDSP on 29/08/2017.
//

#include "data_system.h"

#ifndef REWRITE_MOBILEED_DATA_VAPPS_H
#define REWRITE_MOBILEED_DATA_VAPPS_H

#define VAPPS_ARRAY_ITEMMAX SYSTEM_APPMAX

void vROM_init(BASE_APP_ITEM *_vApps);
int vApps_return_count(BASE_APP_ITEM* _vApps);
int vApps_install (BASE_APP_ITEM* _vApps, BASE_APP_ITEM* _newItem);
int vApps_remove (BASE_APP_ITEM* _vApps, int UID);
int vApps_find_byUID (BASE_APP_ITEM* _vApps, int UID);
int vApps_find_byName (BASE_APP_ITEM* _vApps, const char* _AppName);
BASE_APP_ITEM vApps_return_byIndex (BASE_APP_ITEM* _vStore, int index);

int vApps_uninstall_app (BASE_APP_ITEM* _vApps, BASE_APP_ITEM* _vROM, int UID);

#endif //REWRITE_MOBILEED_DATA_VAPPS_H
