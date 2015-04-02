#include "SDL.h"

int main(int argc, char *argv [])
{
    int returnValue = 0;
    SDL_DisplayMode displayMode;
    SDL_Window *window;
    SDL_GLContext context;

    returnValue = SDL_Init(SDL_INIT_VIDEO);

    if (returnValue < 0)
    {
        SDL_Log("Unable to initialize SDL");
        return 1;
    }

    
    returnValue = SDL_GetDesktopDisplayMode(0, &displayMode);

    if (returnValue < 0)
    {
        SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
        return 1;
    }


    window = SDL_CreateWindow("OpenGL ES 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        SDL_Log("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    context = SDL_GL_CreateContext(window);

    if (context == NULL) 
    {
        SDL_Log("Couldn't create context: %s\n", SDL_GetError());
        return 1;
    }


    return returnValue;
}