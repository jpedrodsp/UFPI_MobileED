//
// Created by JPDSP on 29/08/2017.
//

#include <stdio.h>
#include <string.h>
#include "appitem.h"

#define APPITEM_DUMMY_NAME "DUMMY APP"
#define APPITEM_DUMMY_UID 555
#define APPITEM_DUMMY_SIZE 10

void Appitem_debug_print_info(BASE_APP_ITEM _appitem){
    printf("\n%03d | %3d : %s\n", _appitem.appUID, _appitem.appSize, _appitem.appName);
}

BASE_APP_ITEM Appitem_create_newapp(int UID, int Size, const char* Name){
    BASE_APP_ITEM _newApp;
    _newApp.appUID = UID;
    _newApp.appSize = Size;
    strcpy(_newApp.appName, Name);

    return _newApp;

}
BASE_APP_ITEM Appitem_create_dummy(){
    BASE_APP_ITEM _newApp;
    _newApp.appUID = APPITEM_DUMMY_UID;
    _newApp.appSize = APPITEM_DUMMY_SIZE;
    strcpy(_newApp.appName, APPITEM_DUMMY_NAME);

    return _newApp;
}

BASE_APP_ITEM Appitem_create_invalid(){
    BASE_APP_ITEM _newApp;
    _newApp.appUID = -1;
    _newApp.appSize = 0;
    strcpy(_newApp.appName, "");

    return _newApp;
}

const char* Appitem_vStore_return_name_byUID(BASE_APP_ITEM* _List, int UID){
    int i;
    for (i = 0; i < )
    return _Item.appName;
}