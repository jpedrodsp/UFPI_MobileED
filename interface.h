//
// Created by jpedro on 02/09/2017.
//

#ifndef REWRITE_MOBILEED_INTERFACE_H
#define REWRITE_MOBILEED_INTERFACE_H

#define INTERFACE_HSIZE 60
#define INTERFACE_VSIZE 40

#include "desktop.h"
#include "appitem.h"

void interface_configure_cmd();

void interface_print_bar (int h_size, int barChar);
void interface_print_centralized (int h_size, const char* text);
void interface_print_centralized_bar (int h_size, const char* text, int barChar);

int interface_main_show(BASE_APP_ITEM* vStore, BASE_APP_ITEM* vApps, BASE_APP_ITEM* vROM, int desktop[DESKTOP_GRID_WIDTH][DESKTOP_GRID_HEIGHT]);
int interface_main_to_exit();

#endif //REWRITE_MOBILEED_INTERFACE_H
