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
