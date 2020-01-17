#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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
    SDL_Texture* menuTexture;

    void load_pixels(std::vector <std::vector<Cell * > > *p);
    void clear_screen();
    void Draw();
    void Update();
    void drawBox(int x, int y, int width, int length, int flag);
    int generateGrid(int columns, int rows);

    void load_menu();
    void destroy_menu();

protected:

private:

};
