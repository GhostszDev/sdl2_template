#include "Window.h"

Window::Window() {

}

Window::~Window() {

}

bool Window::initWindow(){

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("Error: Failed to load SDL! %s\n", SDL_GetError());
    } else {
        int imgFlags = IMG_INIT_PNG;

        if(!(IMG_Init(imgFlags) & imgFlags )){
            printf("SDL_Image didn't initalize! SDL_Image Error: %s\n ", IMG_GetError());
            return false;
        }else{

            return true;
        }

        return true;
    }

    return false;
}

bool Window::createWindow() {

    window = SDL_CreateWindow(appName,
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            width, height, SDL_WINDOW_FULLSCREEN_DESKTOP);

    if(window == NULL){
        printf("Error: Failed to create window!\n");
    } else {
        renderer = SDL_CreateRenderer(window, -1, 0);

        if(renderer == NULL){
            printf("Error: Failed to create renderer! \n");
        } else{
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            gameLoop = true;

            return true;
        }
    }

    return false;

}

void Window::renderWindow(){
    SDL_RenderClear(renderer);

    //add stuff to render
    SDL_RenderCopy(renderer, texture, NULL, NULL);


    SDL_RenderPresent(renderer);
}

bool Window::loadSprite(std::string sprite) {

    return false;
}

void Window::updateWindow(){

    //events handler
    while(SDL_PollEvent(&event) != 0){

        if(event.type == SDL_KEYDOWN){

            switch(event.key.keysym.sym){

                case SDLK_ESCAPE:

                    printf("Pressed: %s\n", SDL_GetKeyName(event.key.keysym.sym));
                    gameLoop = false;
                    break;

            }
        }

        if(event.type == SDL_KEYUP){

            switch(event.key.keysym.sym) {

                case SDLK_LEFT:
                case SDLK_RIGHT:

                    printf("Button: %s\n", SDL_GetKeyName(event.key.keysym.sym));
                    break;

            }
        }
    }

    //render window
    Window::renderWindow();

}

void Window::destroyWindow(){

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("SDL has closed everything!");

}
