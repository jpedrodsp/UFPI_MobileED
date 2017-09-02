//
// Created by jpedro on 29/08/2017.
//
#include <stdio.h>
#include "appitem.h"

#ifndef REWRITE_MOBILEED_FILE_HANDLER_H
#define REWRITE_MOBILEED_FILE_HANDLER_H

int fileh_file_init(FILE* file, const char* filename);
int fileh_vstore_insertApp(FILE* file, BASE_APP_ITEM _newApp);
int fileh_vstore_checkIfAppExists(FILE* file, BASE_APP_ITEM _newApp);
int fileh_vstore_getAppCount(FILE* file);


#endif //REWRITE_MOBILEED_FILE_HANDLER_H
