//
// Created by JPDSP on 29/08/2017.
//

#ifndef REWRITE_MOBILEED_APPITEM_H
#define REWRITE_MOBILEED_APPITEM_H

#define APPITEM_NAMEMAX 64+1
#define APPITEM_NULL_UID -1

typedef struct {
    int appUID;
    int appSize;
    char appName[APPITEM_NAMEMAX];
} BASE_APP_ITEM;

void Appitem_debug_print_info(BASE_APP_ITEM _appitem);
BASE_APP_ITEM Appitem_create_newapp(int UID, int Size, const char* Name);
BASE_APP_ITEM Appitem_create_dummy();
BASE_APP_ITEM Appitem_create_invalid();

#endif //REWRITE_MOBILEED_APPITEM_H
