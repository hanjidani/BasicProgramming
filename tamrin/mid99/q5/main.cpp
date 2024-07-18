#include <iostream>
//#include <iostream>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "EE_SDL_Linux/lib.h"
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <string>


// by Dr Arasteh
// by Dr Vosoghi Vahdat
// by MohammadAmin Alamalhoda  ma.alamalhoda@gmail.com 
// On linux by mohammad hossein besharti

using namespace std;




int main( int argc, char * argv[] )
{
    int n, d;
    cin>>n>>d;
    //Initialization of SDL windows
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN ;//| SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    //Texture for loading image

    int img_w, img_h;
    SDL_Rect img_rect;


    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( 1200, 900, WND_flags, &m_window, &m_renderer );
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen resolution
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    int W = 1200;
    int H = 900;
    // Clear the window with a black background
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );

    // Show the window
    SDL_RenderPresent( m_renderer );
    // start
    int room_speed = 60;
    int delay = 1000 / room_speed;
    int dx = d, dy = d;
    int lx = W / 2, ly = H / 2;
    // end start
    // step
    for(int i = 1; i <= n; i ++){
        if(i % 4 ==  1){
            aalineRGBA(m_renderer, lx, ly, lx, ly + dy, 255, 255, 255, 255);
            ly += dy;
            dy += d;
        } else if(i % 4 == 2){
            aalineRGBA(m_renderer, lx, ly, lx + dx, ly, 255, 255, 255, 255);
            lx += dx;
            dx += d;
        } else if(i % 4 == 3){
            aalineRGBA(m_renderer, lx, ly, lx, ly - dy, 255, 255, 255, 255);
            ly -= dy;
            dy += d;
        } else if(i % 4 == 0){
            aalineRGBA(m_renderer, lx, ly, lx - dx, ly, 255, 255, 255, 255);
            lx -= dx;
            dx += d;
        }
        SDL_RenderPresent(m_renderer);
        SDL_Delay(1000);
    }
    // end step
    //Wait for a key to be pressed
    SDL_Event *e = new SDL_Event();
    e->type = 0;
    while(e->type != SDL_KEYDOWN)
        SDL_PollEvent(e);

    //Finalize and free resources
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
	SDL_Quit();
    return 0;

}


