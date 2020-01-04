#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

#include "cell.h"

class Display
{
public:

    Display(int WIDTH, int HEIGHT);
    virtual ~Display();

    int width;
    int height;

    std::vector<std::vector<Cell * > > *pixel_buffer;

    SDL_Renderer *renderer;
    SDL_Window *window;

    void load_pixels(std::vector <std::vector<Cell * > > *p);
    void clear_screen();
    void Draw();
    void Update();
    void drawBox(int x, int y, int width, int length, int flag);
    int generateGrid(int columns, int rows);

protected:

private:

};
