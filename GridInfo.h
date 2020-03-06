#ifndef GRIDINFO_H
#define GRIDINFO_H

enum Difficulty { EASY, HARD };

class GridInfo
{
public:
    GridInfo(const char * fileName);
    int size;
    Difficulty difficulty;
};

#endif // GRIDINFO_H
