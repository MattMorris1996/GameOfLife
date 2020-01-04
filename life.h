#ifndef LIFE_H
#define LIFE_H

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "cell.h"

enum modes
{
    DEFAULT,
    RANDOM
};

class Life
{
public:

    Life();

    int rows;
    int columns;

    std::vector<std::vector<Cell* > > cells;
    void update_neighbours();
    Life(int rows_, int columns_, int random_flag);
    Cell * get_cell(int row_, int column_);
    void cells_update();
    std::vector<std::vector<Cell* > > * get_vector(void);
    Cell **get_neighbours(int row_, int column_);
    void get_number_alive_neighbours(int row_, int column_);

    virtual ~Life();

protected:

private:
};

#endif // LIFE_H
