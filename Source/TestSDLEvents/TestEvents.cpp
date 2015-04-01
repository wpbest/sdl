#include <SDL.h>

int main(int argc, char *argv[])
{
    SDL_Window * window = NULL;
    SDL_GLContext glContext = NULL;
    SDL_Surface *screenSurface = NULL;
    SDL_bool running = SDL_TRUE;
    SDL_Rect rect = { 0, 0, 100, 100 };
    int w, h;
    SDL_Event event;
    Uint32 initFlags = 0;
    Uint32 windowFlags = 0;

    initFlags |= SDL_INIT_TIMER;          /* timer subsystem */
    initFlags |= SDL_INIT_AUDIO;          /* audio subsystem */
    initFlags |= SDL_INIT_VIDEO;          /* video subsystem */
    initFlags |= SDL_INIT_JOYSTICK;       /* joystick subsystem */
    initFlags |= SDL_INIT_HAPTIC;         /* haptic(force feedback) subsystem */
    initFlags |= SDL_INIT_GAMECONTROLLER; /* controller subsystem */
    initFlags |= SDL_INIT_EVENTS;         /* events subsystem */

   if (SDL_Init(initFlags) != 0) 
   {
      SDL_Log("Unable to initialize SDL video subsystem: %s\n", SDL_GetError());
      return 1;
   }

   windowFlags |= SDL_WINDOW_OPENGL;

#if __IPHONEOS__ || __ANDROID__ || __WINRT__
   windowFlags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
#endif

   window = SDL_CreateWindow("Events", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 300, 300, windowFlags);

   if (window == NULL) 
   {
      SDL_Log("Unable to create window: %s", SDL_GetError());
      return 1;
   }
   
   SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
   SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
   SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
   
   glContext = SDL_GL_CreateContext(window);

   if (glContext == NULL) 
   {
      SDL_Log("Unable to create GL context: %s", SDL_GetError());
      return 1;
   }
   
   screenSurface = SDL_GetWindowSurface(window);

   if (screenSurface == NULL)
   {
       SDL_Log("Unable to get Window surface: %s", SDL_GetError());
       return 1;
   }

   SDL_GetWindowSize(window, &w, &h);

   SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));

   while (running) 
   {
 
       while (SDL_PollEvent(&event)) 
       {
           switch (event.type)
           {
               case SDL_AUDIODEVICEADDED:
                 SDL_Log("SDL_AUDIODEVICEADDED\n");
                 break;

               case SDL_AUDIODEVICEREMOVED:
                 SDL_Log("SDL_AUDIODEVICEREMOVED\n: ");
                 break;

               case SDL_CONTROLLERBUTTONDOWN:
                   SDL_Log("SDL_CONTROLLERBUTTONDOWN\n: ");
                   break;

               case SDL_CONTROLLERBUTTONUP:
                   SDL_Log("SDL_CONTROLLERBUTTONUP\n: ");
                   break;

               case SDL_CONTROLLERDEVICEADDED:
                   SDL_Log("SDL_CONTROLLERDEVICEADDED\n: ");
                   break;

               case SDL_CONTROLLERDEVICEREMOVED:
                   SDL_Log("SDL_CONTROLLERDEVICEREMOVED\n: ");
                   break;

               case SDL_CONTROLLERDEVICEREMAPPED:
                   SDL_Log("SDL_CONTROLLERDEVICEREMAPPED\n: ");
                   break;

               case SDL_DOLLARGESTURE:
                   SDL_Log("Gesture performed, id %i, error: %f\n", event.dgesture.gestureId, event.dgesture.error);
                   break;

               case SDL_DOLLARRECORD:
                   SDL_Log("Recorded gesture: id %i\n", event.dgesture.gestureId);
                   break;

               case SDL_DROPFILE:
                   SDL_Log("SDL_DROPFILE\n");
                   break;

               case SDL_FINGERMOTION:
                   SDL_Log("Finger Motion: %i, x: %f, y: %f\n", event.tfinger.fingerId, event.tfinger.x, event.tfinger.y);
                   break;

               case SDL_FINGERDOWN:
                   SDL_Log("Finger down: %i, x: %f y: %f\n", event.tfinger.fingerId, event.tfinger.x, event.tfinger.y);
                   break;

               case SDL_FINGERUP:
                   SDL_Log("Finger up: %i, x: %f, y: %f\n", event.tfinger.fingerId, event.tfinger.x, event.tfinger.y);
                   break;

               case SDL_KEYDOWN:
               {
                   SDL_Log("Key Down: ");
                   switch (event.key.keysym.sym) 
                   {
                   case SDLK_LEFT:
                       SDL_Log("SDLK_LEFT\n");
                       break;
                   case SDLK_RIGHT:
                       SDL_Log("SDLK_RIGHT\n");
                       break;
                   case SDLK_UP:
                       SDL_Log("SDLK_UP\n");
                       break;
                   case SDLK_DOWN:
                       SDL_Log("SDLK_DOWN\n");
                       break;
                   }
                   break;
               }
               case SDL_KEYUP:
               {
                   SDL_Log("Key Up: ");
                   switch (event.key.keysym.sym)
                   {
                   case SDLK_LEFT:
                       SDL_Log("SDLK_LEFT\n");
                       break;
                   case SDLK_RIGHT:
                       SDL_Log("SDLK_RIGHT\n");
                       break;
                   case SDLK_UP:
                       SDL_Log("SDLK_UP\n");
                       break;
                   case SDLK_DOWN:
                       SDL_Log("SDLK_DOWN\n");
                       break;
                   }
                   break;
               }

               case SDL_JOYAXISMOTION:
                   SDL_Log("SDL_JOYAXISMOTION\n");
                   break;

               case SDL_JOYBALLMOTION:
                   SDL_Log("SDL_JOYBALLMOTION\n");
                   break;

               case SDL_JOYHATMOTION:
                   SDL_Log("SDL_JOYHATMOTION\n");
                   break;

               case SDL_JOYBUTTONDOWN:
                   SDL_Log("SDL_JOYBUTTONDOWN\n");
                   break;

               case SDL_JOYDEVICEADDED:
                   SDL_Log("SDL_JOYDEVICEADDED\n");
                   break;

               case SDL_JOYDEVICEREMOVED:
                   SDL_Log("SDL_JOYDEVICEREMOVED\n");
                   break;

               case SDL_JOYBUTTONUP:
                   SDL_Log("SDL_JOYBUTTONUP\n");
                   break;

               case SDL_MOUSEMOTION:
                   SDL_Log("SDL_MOUSEMOTION\n");
                   break;

               case SDL_MOUSEBUTTONDOWN:
                   SDL_Log("SDL_MOUSEBUTTONDOWN\n");
                   break;

               case SDL_MOUSEBUTTONUP:
                   SDL_Log("SDL_MOUSEBUTTONUP\n");
                   break;

               case SDL_MOUSEWHEEL:
                   SDL_Log("SDL_MOUSEWHEEL\n");
                   break;

               case SDL_MULTIGESTURE:
                   SDL_Log("Multi Gesture: x = %f, y = %f, dAng = %f, dR = %f\n", event.mgesture.x, event.mgesture.y, event.mgesture.dTheta, event.mgesture.dDist);
                   SDL_Log("MG: numDownTouch = %i\n", event.mgesture.numFingers);
                   break;

               case SDL_QUIT:
                   SDL_Log("Quit\n");
                   running = SDL_FALSE;
                   break;

               case SDL_TEXTEDITING:
                   SDL_Log("SDL_TEXTEDITING\n");
                   break;

               case SDL_TEXTINPUT:
                   SDL_Log("SDL_TEXTINPUT\n");
                   break;

               case SDL_USEREVENT:
                   SDL_Log("DL_USEREVENT\n");
                   break;

               case SDL_SYSWMEVENT:
                   SDL_Log("SDL_SYSWMEVENT\n");
                   break;

               case SDL_WINDOWEVENT:
               {
                   switch (event.window.event)
                   {
                       case SDL_WINDOWEVENT_SIZE_CHANGED:
                           SDL_Log("SDL_WINDOWEVENT_SIZE_CHANGED\n");
                           break;
                   }
                   break;
               }
           }


       }
   }

   return 0;
}
