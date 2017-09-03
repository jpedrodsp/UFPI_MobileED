//
// Created by JPDSP on 29/08/2017.
//

#include "appitem.h"
#include <string.h>
#include "data_vapps.h"
#include "data_vrom.h"

void vApps_init(BASE_APP_ITEM *_vApps) {
    int i;
    for (i = 0; i < VAPPS_ARRAY_ITEMMAX; ++i) {
        _vApps[i].appUID = APPITEM_NULL_UID;
        _vApps[i].appSize = 0;
        strcpy(_vApps[i].appName, "");
    }
}

int vApps_return_count(BASE_APP_ITEM* _vApps) {
    int count = 0;

    int i;
    for (i = 0; i < VAPPS_ARRAY_ITEMMAX; ++i) {
        if (_vApps[i].appUID != APPITEM_NULL_UID) {
            count++;
        }
    }

    return count;
}

int vApps_install (BASE_APP_ITEM* _vApps, BASE_APP_ITEM* _newItem) {
    // Creates an auxiliar AppItem.
    BASE_APP_ITEM _auxItem;
    _auxItem.appUID = _newItem->appUID;
    _auxItem.appSize = _newItem->appSize;
    strcpy(_auxItem.appName, _newItem->appName);

    // Try to Install
        // Check if there are any apps on the vApps
        int appCount = vApps_return_count(_vApps);
            // If there isn't, install on the first slot.
            if (appCount == 0) {
                _vApps[0] = _auxItem;
                return 0;

            }

            // If there is, do an ordered insertion.
            if (appCount > 0) {
                // Check if there is any space on vApps Array.
                if (appCount == VAPPS_ARRAY_ITEMMAX) {
                    // If there isn't, return 1.
                    return 1;

                } else {
                    // If there is, continue the ordered insertion.
                    int i, j;
                    for (i = 0; i < appCount; ++i) {
                        if (_auxItem.appSize > _vApps->appSize) {
                            for (j = appCount; j > i; --j) {
                                _vApps[j] = _vApps[j-1];
                            }
                            _vApps[i] = _auxItem;
                            return 0;

                        }
                    }
                    // Insert at the end of vApps Array.
                    _vApps[appCount] = _auxItem;
                    return 0;

                }
            }
}

int vApps_remove (BASE_APP_ITEM* _vApps, int UID) {
    int appCount = vApps_return_count(_vApps);

    // Check if there is any app on vApps Array.
    if (appCount == 0) {
        return 2; // ERROR 2: There isn't any app on the array.
    }
    // If there is, try to remove it.
    int i, j;
    for (i = 0; i < appCount; ++i) {
        if (_vApps->appUID == UID) {
            for (j = i; j < appCount; ++j) {
                _vApps[j+1] = _vApps[j];
            }
            // The last element should be an null element. But...
            if (_vApps[appCount].appUID != APPITEM_NULL_UID) {
                _vApps[appCount].appUID = APPITEM_NULL_UID;
                _vApps[appCount].appSize = 0;
                strcpy(_vApps[appCount].appName, "");
            }
            return 0; // Element sucessfully removed.
        }
    }
    return 1; // Element not found.
}

int vApps_find_byUID (BASE_APP_ITEM* _vApps, int UID) {
    // Returns the index on the vApps Array, finding the element by UID.
    // -1: NOT FOUND
    // OTHER: THE INDEX OF ELEMENT

    int appCount = vApps_return_count(_vApps);

    // Check if there is any app on vApps Array.
    if (appCount == 0) {
        return -1; // Element not found. Also, there isn't any element on the array, so why bother looking?
    }
    // If there is, try to find it.
    int i;
    for (i = 0; i < appCount; ++i) {
        if (_vApps->appUID == UID) {
            // Returns the index of the element.
            return i;
        }
    }
    return -1; // Element not found.

}

int vApps_find_byName (BASE_APP_ITEM* _vApps, const char* _AppName) {
    // Returns the index on the vApps Array, finding the element by UID.
    // -1: NOT FOUND
    // OTHER: THE INDEX OF ELEMENT

    int appCount = vApps_return_count(_vApps);

    // Check if there is any app on vApps Array.
    if (appCount == 0) {
        return -1; // Element not found. Also, there isn't any element on the array, so why bother looking?
    }
    // If there is, try to find it.
    int i;
    for (i = 0; i < appCount; ++i) {
        if (strcmp(_vApps[i].appName, _AppName) == 0) {
            // Returns the index of the element.
            return i;
        }
    }
    return -1; // Element not found.

}

BASE_APP_ITEM vApps_return_byIndex (BASE_APP_ITEM* _vApps, int index) {
    return _vApps[index];
}


int vApps_uninstall_app (BASE_APP_ITEM* _vApps, BASE_APP_ITEM* _vROM, int UID) {
    int ec = 0;
    int index = vROM_find_byUID(_vROM, UID);
    if (index == -1) {
        index = vApps_find_byUID(_vApps, UID);
        if (index == -1) {
            ec = vApps_remove(_vApps, UID);
            if (ec != 0) {
                return (ec + 1);
                /*
                 * EC 2 : The App isn't installed.
                 * EC 3 : There aren't any apps installed.
                 */
            }
        } else {
            return 2; // The App isn't installed.
        }
    } else {
        return 1; // The App is executing in vROM. Can't uninstall.
    }
}