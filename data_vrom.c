//
// Created by JPDSP on 29/08/2017.
//

#include "data_vrom.h"
#include "appitem.h"
#include <stdio.h>
#include <string.h>

void vROM_init(BASE_APP_ITEM* _vROM) {
    int i;
    for (i = 0; i < VROM_ARRAY_ITEMMAX; ++i) {
        _vROM[i] = Appitem_create_invalid();
    }
}

int vROM_return_count(BASE_APP_ITEM* _vROM) {
    int count = 0;

    int i;
    for (i = 0; i < VROM_ARRAY_ITEMMAX; ++i) {
        if (_vROM[i].appUID != APPITEM_NULL_UID) {
            count++;
        }
    }

    return count;
}

int vROM_install (BASE_APP_ITEM* _vROM, BASE_APP_ITEM* _newItem) {
    // Creates an auxiliar AppItem.
    BASE_APP_ITEM _auxItem;
    _auxItem.appUID = _newItem->appUID;
    _auxItem.appSize = _newItem->appSize;
    strcpy(_auxItem.appName, _newItem->appName);

    // Try to Install
    // Check if there are any apps on the vROM
    int appCount = vROM_return_count(_vROM);
    // If there isn't, install on the first slot.
    if (appCount == 0) {
        _vROM[0] = _auxItem;
        return 0;

    }

    // If there is, do an ordered insertion.
    if (appCount > 0) {
        // Check if there is any space on vROM Array.
        if (appCount == VROM_ARRAY_ITEMMAX) {
            // If there isn't, return 1.
            return 1;

        } else {
            // If there is, continue the ordered insertion.
            int i, j;
            for (i = 0; i < appCount; ++i) {
                if (_auxItem.appSize > _vROM->appSize) {
                    for (j = appCount; j > i; --j) {
                        _vROM[j] = _vROM[j-1];
                    }
                    _vROM[i] = _auxItem;
                    return 0;

                }
            }
            // Insert at the end of vROM Array.
            _vROM[appCount] = _auxItem;
            return 0;

        }
    }
}

int vROM_remove (BASE_APP_ITEM* _vROM, int UID) {
    int appCount = vROM_return_count(_vROM);

    // Check if there is any app on vROM Array.
    if (appCount == 0) {
        return 2; // ERROR 2: There isn't any app on the array.
    }
    // If there is, try to remove it.
    int i, j;
    for (i = 0; i < appCount; ++i) {
        if (_vROM->appUID == UID) {
            for (j = i; j < appCount; ++j) {
                _vROM[j+1] = _vROM[j];
            }
            // The last element should be an null element. But...
            if (_vROM[appCount].appUID != APPITEM_NULL_UID) {
                _vROM[appCount].appUID = APPITEM_NULL_UID;
                _vROM[appCount].appSize = 0;
                strcpy(_vROM[appCount].appName, "");
            }
            return 0; // Element sucessfully removed.
        }
    }
    return 1; // Element not found.
}


int vROM_find_byUID (BASE_APP_ITEM* _vROM, int UID) {
    // Returns the index on the vROM Array, finding the element by UID.
    // -1: NOT FOUND
    // OTHER: THE INDEX OF ELEMENT

    int appCount = vROM_return_count(_vROM);

    // Check if there is any app on vROM Array.
    if (appCount == 0) {
        return -1; // Element not found. Also, there isn't any element on the array, so why bother looking?
    }
    // If there is, try to find it.
    int i;
    for (i = 0; i < appCount; ++i) {
        if (_vROM->appUID == UID) {
            // Returns the index of the element.
            return i;
        }
    }
    return -1; // Element not found.

}

int vROM_find_byName (BASE_APP_ITEM* _vROM, const char* _AppName) {
    // Returns the index on the vROM Array, finding the element by UID.
    // -1: NOT FOUND
    // OTHER: THE INDEX OF ELEMENT

    int appCount = vROM_return_count(_vROM);

    // Check if there is any app on vROM Array.
    if (appCount == 0) {
        return -1; // Element not found. Also, there isn't any element on the array, so why bother looking?
    }
    // If there is, try to find it.
    int i;
    for (i = 0; i < appCount; ++i) {
        if (strcmp(_vROM[i].appName, _AppName) == 0) {
            // Returns the index of the element.
            return i;
        }
    }
    return -1; // Element not found.
    
}


BASE_APP_ITEM vROM_return_byIndex (BASE_APP_ITEM* _vROM, int index) {
    return _vROM[index];
}


int vROM_close_app (BASE_APP_ITEM* _vROM, int UID) {
    int index = vROM_find_byUID(_vROM, UID);
    if (index == -1) {
        int ec = vROM_remove(_vROM, UID);
        if (ec == 0) {
            return 0;
        } else {
            return ec;
            /*
             * 1: The App isn't running.
             * 2: There aren't any apps on the vROM.
             */
        }
    }
}