#include "cell.h"

Cell::Cell(int _alive)
{
    alive = _alive;
    neighbours = 0;
    state_change = true;
}

int Cell::get_alive()
{
    return alive;
}

void Cell::set_alive(int _alive)
{
    alive = _alive;
    state_change = true;
}

void Cell::set_state_change(bool b)
{
    state_change = b;
}

void Cell::set_neighbours(int n)
{
    neighbours = n;
}

int Cell::get_neighbours(void)
{
    return neighbours;
}

bool Cell::get_state_change(void)
{
    return state_change;
}

Cell::~Cell()
{
    //dtor
}
