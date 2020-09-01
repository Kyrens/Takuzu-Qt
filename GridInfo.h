/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

#ifndef GRIDINFO_H
#define GRIDINFO_H

enum Difficulty { EASY, HARD };

class GridInfo
{
public:
    GridInfo(const char * fileName);
    ~GridInfo();
    int _size;
    Difficulty _difficulty;
    char * _fileName = nullptr;
};

#endif // GRIDINFO_H
