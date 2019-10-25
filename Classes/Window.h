#ifndef UNTITLED_WINDOW_H
#define UNTITLED_WINDOW_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <string>
#include <iostream>

class Window {

public:
    bool gameLoop = false;

    Window();
    ~Window();
    bool initWindow();
    bool createWindow();
    void updateWindow();
    void destroyWindow();
    void renderWindow();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Surface *surface;
    SDL_Surface *twoSurface;
    SDL_Event event;
    const char *appName = "Untitled App";
    int width = 800;
    int height = 600;

    bool loadSprite(std::string sprite);
};


#endif //UNTITLED_WINDOW_H
