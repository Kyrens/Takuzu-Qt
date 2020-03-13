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


Grid::Grid(Grid * grid) {

    _size = grid->_size;
    _cells = new char*[_size];
    for(int i = 0; i < _size; ++i) {
       _cells[i] = new char[_size];
       for (int j = 0; j < _size; ++j) {
           _cells[i][j] = grid->_cells[i][j];
       }
    }
    _editable = true;
}

void Grid::setCell(int i, int j, char c) {

    if (!_editable) {
        throw "This grid is not editable";
    }
    if (i < 0 || i >= _size || j < 0 || j >= _size) {
        throw "Grid out of bound";
    }
    _cells[i][j] = c;
}
