#include <iostream>
#include <stdlib.h>
#include <vector>

#include "life.h"
#include "display_sdl.h"

using namespace std;

int main(void)
{
    const int COLUMNS = 500;
    const int ROWS = 500;

    const int WINDOW_WIDTH = 1000;
    const int WINDOW_HEIGHT = 1000;

    Display display(WINDOW_WIDTH, WINDOW_HEIGHT);

    Life board(COLUMNS, ROWS, RANDOM);

    display.load_menu();
    //tell the display where the pixels are
    display.load_pixels(board.get_vector());

    //randomly generate board
    if (display.generateGrid(COLUMNS, ROWS))
    {
        cout << "Error" << endl;
    }

    SDL_Event event;
    int start = 0;

    while (1)
    {
        SDL_PumpEvents();

        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
        {
            std::cout << "Quiting.." << std::endl;
            return EXIT_SUCCESS;
        }

        if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            std::cout << "Mouse Button 1 (left) is pressed." << std::endl;
            display.destroy_menu();
            start = 1;
        }

        if (start)
        {
            board.update_neighbours();
            board.cells_update();
            display.clear_screen();
            display.generateGrid(COLUMNS, ROWS);
            display.Update();
        }
    }
}
