//
// Created by JPDSP on 29/08/2017.
//

#include "data_vstore.h"
#include "appitem.h"
#include "file_handler.h"
#include <string.h>

void vStore_init(BASE_APP_ITEM* _vStore) {
    int i;
    for (i = 0; i < VSTORE_ARRAY_ITEMMAX; ++i) {
        _vStore[i] = Appitem_create_invalid();
    }
}

int vStore_insert_on_file (FILE *_vStoreData, BASE_APP_ITEM *_NewItem) {
    int _ec = fileh_vstore_checkConflictApp(_vStoreData, _NewItem);
    if (_ec == 1) {
        return 1; // Conflicting apps return code
    } else {
        _ec = fileh_vstore_insertApp(_NewItem);
        if (_ec == 1) {
            return 2; // Couldn't insert return code.
        }
    }
    return 0;
}

/*int vStore_delete (int UID){

    return 0;
}*/

BASE_APP_ITEM vStore_getApp (BASE_APP_ITEM* _vStore, int index) {
    return _vStore[index];
}

int vStore_updateApp (BASE_APP_ITEM* _vStore, int index, BASE_APP_ITEM _UpdatedApp) {
    _vStore[index] = _UpdatedApp;
}

int vStore_return_count (BASE_APP_ITEM* _vStore) {
    // The condition for an Item being valid is that it's UID should be above 0, or different from '-1'.
    int count = 0, i;

    for (i = 0; i < VSTORE_ARRAY_ITEMMAX; ++i) {
        if (_vStore[i].appUID != APPITEM_NULL_UID) {
            count++;
        }
    }

    return count;
}

int vStore_find_byUID (BASE_APP_ITEM* _vStore, int UID) {
    int i;
    for (i = 0; i < VSTORE_ARRAY_ITEMMAX; ++i) {
        if (UID == _vStore[i].appUID) {
            return i;
        }
    }

    return -1;
}

int vStore_find_byName (BASE_APP_ITEM* _vStore, const char* _AppName) {
    // Returns the index on the vApps Array, finding the element by UID.
    // -1: NOT FOUND
    // OTHER: THE INDEX OF ELEMENT

    int appCount = vStore_return_count(_vStore);

    // Check if there is any app on vApps Array.
    if (appCount == 0) {
        return -1; // Element not found. Also, there isn't any element on the array, so why bother looking?
    }
    // If there is, try to find it.
    int i;
    for (i = 0; i < appCount; ++i) {
        if (strcmp(_vStore[i].appName, _AppName) == 0) {
            // Returns the index of the element.
            return i;
        }
    }
    return -1; // Element not found.

}

BASE_APP_ITEM vApps_return_byIndex (BASE_APP_ITEM* _vStore, int index) {
    return _vStore[index];
}