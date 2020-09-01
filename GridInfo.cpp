/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

#include "GridInfo.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

GridInfo::GridInfo(const char * fileName)
{
    int size;
    char difficulty[10];
    static const char * difficulties[] = { "easy", "hard" };

    if (2 == std::sscanf(fileName, "%d_%[^.].txt", &size, difficulty)) {
        bool ok = false;
        for (int i = 0; i < 2; ++i) {
            if (!strcmp(difficulties[i], difficulty)) {
                _difficulty = static_cast<Difficulty>(i);
                ok = true;
                break;
            }
        }
        if (!ok) {
            throw "Unknown difficulty";
        }
        _size = size;
        _fileName = new char[strlen(fileName) + 1];
        strcpy(_fileName, fileName);
        return;
    }
    throw "Wrong file name";
}

GridInfo::~GridInfo() {
    delete[] _fileName;
}
