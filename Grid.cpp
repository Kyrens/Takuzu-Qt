#include "Grid.h"

Grid::Grid(int size, const char * buffer) {

    _cells = new char*[size];
    for(int i = 0; i < size; ++i) {
       _cells[i] = new char[size];
    }
    for (int i = 0; i < size * size; ++i) {
        _cells[i / size][i % size] = buffer[i];
    }
    _size = size;
}

Grid::~Grid() {
    for (int i = 0; i < _size * _size; ++i) {
        delete _cells[i];
    }
    delete[] _cells;
}

char Grid::getCell(int i, int j) {

    if (i < 0 || i >= _size || j < 0 || j >= _size) {
        throw "Grid out of bound";
    }
    return _cells[i][j];
}

int Grid::getSize() {
    return _size;
}

char** Grid::getCells() {
    return _cells;
}
