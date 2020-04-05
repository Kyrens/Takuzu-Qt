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
