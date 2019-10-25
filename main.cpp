#include <iostream>
#include "Classes/Window.h"

int main(int argc, char* args[]) {
    Window *window = new Window;

    if(window->initWindow()){
        if(window->createWindow()){

            while(window->gameLoop){
                window->updateWindow();
            }
        }
    }

    window->destroyWindow();

    return 0;
}