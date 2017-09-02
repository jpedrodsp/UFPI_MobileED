//
// Created by JPDSP on 29/08/2017.
//

#include "appitem.h"

#ifndef REWRITE_MOBILEED_DATA_VROM_H
#define REWRITE_MOBILEED_DATA_VROM_H

#define VROM_NAME "ROM"
#define VROM_ARRAY_ITEMMAX 20

void vROM_init(BASE_APP_ITEM* _vROM);
int vROM_return_count(BASE_APP_ITEM* _vROM);

int vROM_install (BASE_APP_ITEM* _vROM, BASE_APP_ITEM* _newItem);
int vROM_remove (BASE_APP_ITEM* _vROM, int UID);

int vROM_find_byUID (BASE_APP_ITEM* _vROM, int UID);
int vROM_find_byName (BASE_APP_ITEM* _vROM, const char* _AppName);

BASE_APP_ITEM vROM_return_byIndex (BASE_APP_ITEM* _vROM, int index);

int vROM_close_app (BASE_APP_ITEM* _vROM, int UID);

#endif //REWRITE_MOBILEED_DATA_VROM_H
