#include "display_sdl.h"

Display::Display(int WIDTH, int HEIGHT)
{

    height = HEIGHT;
    width = WIDTH;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(width + 1, height + 1, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

void Display::load_menu(){
    menuTexture = NULL;
    SDL_Surface* menu = IMG_Load("GameOfLife.png");
    if (menu == NULL)
    {
        printf("Unable to load image %s", SDL_GetError());
    }
    else 
    {
        menuTexture = SDL_CreateTextureFromSurface(renderer, menu);
        if(menuTexture == NULL)
        {
            printf("unable to create texture %s", SDL_GetError());
        }
        SDL_FreeSurface(menu);
    }

    SDL_RenderCopy(renderer, menuTexture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void Display::destroy_menu(){
    SDL_DestroyTexture(menuTexture);
    menuTexture = NULL;
}

void Display::load_pixels(std::vector<std::vector<Cell *>> *p)
{
    pixel_buffer = p;
}

void Display::clear_screen()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void Display::Draw()
{
    for (int j = (width / 100) * 5; j < (width / 100) * 5 + width / 100; j++)
    {
        for (int i = (width / 100) * 5; i < (width / 100) * 5 + width / 100; i++)
        {
            SDL_RenderDrawPoint(renderer, j, i);
        }
    }

    for (int j = (width / 100) * 7; j < (width / 100) * 7 + width / 100; j++)
    {
        for (int i = (width / 100) * 5; i < (width / 100) * 5 + width / 100; i++)
        {
            SDL_RenderDrawPoint(renderer, j, i);
        }
    }
}

void Display::drawBox(int x, int y, int width, int length, int flag)
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = length;

    switch (flag)
    {
    case 0:

        SDL_SetRenderDrawColor(renderer, 180, 180, 180, 255);
        SDL_RenderFillRect(renderer, &rect);

        break;

    case 1:

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        for (int i = 0; i < width; i++)
        {
            SDL_RenderDrawPoint(renderer, x + i, y);
            SDL_RenderDrawPoint(renderer, x + i, y + length);
        }

        for (int i = 0; i < width; i++)
        {
            SDL_RenderDrawPoint(renderer, x, y + i);
            SDL_RenderDrawPoint(renderer, x + width, y + i);
        }

        SDL_RenderDrawRect(renderer, &rect);
    }
}

int Display::generateGrid(int columns, int rows)
{
    if (width % columns != 0)
    {
        return 1;
    }
    if (height % rows != 0)
    {
        return 1;
    }

    int columnWidth = width / columns;
    int rowHeight = height / rows;
    int x = 0;
    int y = 0;

    for (int i = 0; i < width; i = i + columnWidth)
    {

        for (int j = 0; j < height; j = j + rowHeight)
        {
            if (pixel_buffer->at(x).at(y)->get_state_change() || pixel_buffer->at(x).at(y)->get_alive())
                drawBox(i, j, columnWidth, rowHeight, 0);
            y++;
        }
        y = 0;
        x++;
    }
    return 0;
}

void Display::Update()
{
    SDL_RenderPresent(renderer);
}

Display::~Display()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
