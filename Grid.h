#ifndef GRID_H
#define GRID_H


class Grid
{
public:
    Grid(int size, const char * buffer);
    ~Grid();
    char getCell(int i, int j);
    int getSize();
    char ** getCells();

private:
    int _size;
    char ** _cells;
};

#endif // GRID_H
