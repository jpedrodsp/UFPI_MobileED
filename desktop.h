//
// Created by JPDSP on 01/09/2017.
//

#ifndef REWRITE_MOBILEED_DESKTOP_H
#define REWRITE_MOBILEED_DESKTOP_H

#define DESKTOP_GRID_WIDTH 3
#define DESKTOP_GRID_HEIGHT 3

//typedef (int desktop[DESKTOP_GRID_WIDTH][DESKTOP_GRID_HEIGHT]) DESKTOP;
void desktop_init(int desktop[DESKTOP_GRID_WIDTH][DESKTOP_GRID_HEIGHT]);
void desktop_print(int desktop[DESKTOP_GRID_WIDTH][DESKTOP_GRID_HEIGHT]);
int desktop_add_item(int desktop[DESKTOP_GRID_WIDTH][DESKTOP_GRID_HEIGHT], int UID);
int desktop_remove_item(int desktop[DESKTOP_GRID_WIDTH][DESKTOP_GRID_HEIGHT], int UID);

#endif //REWRITE_MOBILEED_DESKTOP_H
