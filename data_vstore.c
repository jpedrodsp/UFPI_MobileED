//
// Created by JPDSP on 29/08/2017.
//

#include "data_vstore.h"
#include "appitem.h"

int data_vstore_insert(){
    /*
     * RETURN CODES:
     * 0x0: Inserted sucessfully.
     * 0x1: Error code 1 - there wasn't any space available on the array.
     */

    // Inserted sort
        // If the array is empty, insert into the first slot.
        // If the array is full, don't insert and return '1'.
        // If the array isn't empty, insert sorting by size (ascending).

    int i, j;
//    for (i = 0; i <)
}

int data_vstore_delete(){

}
BASE_APP_ITEM data_vstore_get(BASE_APP_ITEM* _vStore, int index){
    return _vStore[index];
}

int data_vstore_update(BASE_APP_ITEM* _AppToUpdate, BASE_APP_ITEM _UpdatedApp){
    *_AppToUpdate = _UpdatedApp;
}

int data_vstore_count(BASE_APP_ITEM* _vStore) {
    // The condition for an Item being valid is that it's UID should be above 0.

    int count = 0, i;
    for (i = 0; i < VSTORE_ARRAY_ITEMMAX; ++i) {
        if (_vStore[i].appUID > 0) {
            count++;
        }
    }

    return count;
}

BASE_APP_ITEM data_vstore_return_byUID(BASE_APP_ITEM* _vStore, int UID){
    int i;
    for (i = 0; i < VSTORE_ARRAY_ITEMMAX; ++i) {
        if (UID == _vStore[i].appUID) {
            return _vStore[i];
        }
    }

    return Appitem_create_dummy();
}
