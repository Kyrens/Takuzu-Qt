/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin 
 * F-14050 Caen Cedex 
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

#ifndef GRID_H
#define GRID_H


class Grid
{
public:
    Grid(int size, const char * buffer);
    Grid(Grid * grid);
    ~Grid();
    char getCell(int i, int j);
    int getSize();
    char ** getCells();
    void setCell(int i, int j, char c);

private:
    int _size;
    char ** _cells;
    bool _editable = false;
};

#endif // GRID_H
