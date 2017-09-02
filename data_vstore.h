//
// Created by JPDSP on 29/08/2017.
//

#include <stdio.h>
#include "appitem.h"

#ifndef REWRITE_MOBILEED_DATA_VSTORE_H
#define REWRITE_MOBILEED_DATA_VSTORE_H

#define VSTORE_NAME "LojaED"
#define VSTORE_ARRAY_ITEMMAX 20

void vStore_init(BASE_APP_ITEM* _vStore);
int vStore_insert_on_file (FILE *_vStoreData, BASE_APP_ITEM *_NewItem);
BASE_APP_ITEM vStore_getApp (BASE_APP_ITEM* _vStore, int index);
int vStore_updateApp (BASE_APP_ITEM* _vStore, int index, BASE_APP_ITEM _UpdatedApp);
int vStore_return_count (BASE_APP_ITEM* _vStore);
int vStore_find_byUID (BASE_APP_ITEM* _vStore, int UID);
int vStore_find_byName (BASE_APP_ITEM* _vStore, const char* _AppName);
BASE_APP_ITEM vStore_return_byIndex (BASE_APP_ITEM* _vStore, int index);

#endif //REWRITE_MOBILEED_DATA_VSTORE_H
