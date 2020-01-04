#ifndef CELL_H
#define CELL_H

class Cell
{
public:
    Cell(int _alive);
    int alive;
    bool state_change;
    int neighbours;
    int get_alive();
    int get_neighbours(void);
    void set_neighbours(int n);
    void set_alive(int _alive);
    void set_state_change(bool b);
    bool get_state_change(void);
    virtual ~Cell();

protected:
private:
};

#endif // CELL_H
