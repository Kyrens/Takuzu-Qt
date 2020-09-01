/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

#include "GridsList.h"
#include <fstream>
#include <stdio.h>
#include <string.h>

GridsList::GridsList(const char * fileName) {

    _gridInfo = new GridInfo(fileName);

    std::string fname = "grids/";
    fname.append(fileName);
    std::ifstream file(fname);

    file >> _gridsCount;
    _grids = new Grid*[_gridsCount];
    char buffer[_gridInfo->_size * _gridInfo->_size];
    for (int i = 0; i < _gridsCount; ++i) {
        file >> buffer;
        _grids[i] = new Grid(_gridInfo->_size, buffer);
    }
}

GridsList::~GridsList() {
    delete _gridInfo;
    for (int i = 0; i < _gridsCount; ++i) {
        delete _grids[i];
    }
    delete[] _grids;
}
