/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

#ifndef GRIDSLIST_H
#define GRIDSLIST_H

#include "GridInfo.h"
#include "Grid.h"

class GridsList
{
public:
    GridsList(const char * fileName);
    ~GridsList();

    GridInfo * _gridInfo;
    int _gridsCount;
    Grid ** _grids;
};

#endif // GRIDSLIST_H
