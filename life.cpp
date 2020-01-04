#include "life.h"

Life::Life(int rows_, int columns_, int random_flag)
{
    rows = rows_;
    columns = columns_;

    srand(time(NULL));

    //create 2d Vector to hold the cell data
    std::vector<Cell *> subVector;

    for (int row = 0; row < rows_; row++)
    {
        cells.push_back(subVector);
        for (int column = 0; column < columns_; column++)
        {
            //randomly generate data or set to nothing
            if (random_flag)
            {
                cells[row].push_back(new Cell((rand() % 2 + 1) - 1));
            }
            else
            {
                cells[row].push_back(new Cell(0));
            }
        }
    }
}

Cell *Life::get_cell(int row_, int column_)
{
    return cells[row_][column_];
}

std::vector<std::vector<Cell *>> *Life::get_vector(void)
{
    // Method to return memory address of vector
    std::vector<std::vector<Cell *>> *p = new std::vector<std::vector<Cell *>>;

    p = &cells;

    return p;
}

void Life::get_number_alive_neighbours(int row_, int column_)
{
    // Method returns the number of alive neighbours of a given cell

    // Making naive assumptions about columns and rows
    int top_row = row_ - 1;
    int bottom_row = row_ + 1;
    int left_column = column_ - 1;
    int right_column = column_ + 1;

    // Checking top and bottom boundaries
    if (row_ == 0)
    {
        top_row = rows - 1;
    }
    if (row_ == columns - 1)
    {
        bottom_row = 0;
    }
    // Checking left and right boundaries
    if (column_ == 0)
    {
        left_column = columns - 1;
    }
    if (column_ == columns - 1)
    {
        right_column = 0;
    }
    Cell *neighbours[8];

    neighbours[0] = get_cell(top_row, left_column);
    neighbours[1] = get_cell(top_row, column_);
    neighbours[2] = get_cell(bottom_row, column_);
    neighbours[3] = get_cell(row_, left_column);
    neighbours[4] = get_cell(top_row, right_column);
    neighbours[5] = get_cell(row_, right_column);
    neighbours[6] = get_cell(bottom_row, left_column);
    neighbours[7] = get_cell(bottom_row, right_column);

    int alive = 0;

    for (int i = 0; i < 8; i++)
    {
        if (neighbours[i]->get_alive() == 1)
            alive++;
    }

    // set value of cell based on number of alive cells found
    cells[row_][column_]->set_neighbours(alive);
}

void Life::update_neighbours()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            get_number_alive_neighbours(row, column);
        }
    }
}

void Life::cells_update()
{

    //update cell status
    int n_neighbours;

    int alive;

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            n_neighbours = cells[row][column]->get_neighbours();

            alive = cells[row][column]->get_alive();

            if (alive == 1)
            {
                if (n_neighbours < 2)
                {
                    cells[row][column]->set_alive(0);
                }
                if (n_neighbours > 3)
                {
                    cells[row][column]->set_alive(0);
                }
                else
                {
                    cells[row][column]->set_state_change(false);
                }
            }
            else
            {
                if (n_neighbours == 3)
                {
                    //std::cout << "revive" << std::endl;
                    cells[row][column]->set_alive(1);
                }
                else
                {
                    cells[row][column]->set_state_change(false);
                }
            }
        }
    }
}

Life::~Life()
{
}
