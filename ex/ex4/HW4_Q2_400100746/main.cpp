#include <iostream>
//#include <iostream>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "EE_SDL_Linux/lib.h"
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <string>
#include <math.h>

// by Dr Arasteh
// by Dr Vosoghi Vahdat
// by MohammadAmin Alamalhoda  ma.alamalhoda@gmail.com 
// On linux by mohammad hossein besharti

using namespace std;

int main( int argc, char * argv[] )
{
    //Initialization of SDL windows
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN; //| SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    //Texture for loading image

    int img_w, img_h;
    SDL_Rect img_rect;

    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( 1200, 800, WND_flags, &m_window, &m_renderer );
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen resolution
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    int W = 1200;
    int H = 800;
    // Clear the window with a black background
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );

    // Show the window
    SDL_RenderPresent( m_renderer );
    //Wait for a key to be pressed
    //set some logic
    int room_speed = 60;
    int delay = 1000 / room_speed;
    // on app start
    int x0 = W;
    int wsp = 10;
    int vsp = 10;
    int hsp = 10;
    int r = 25;
    int x = 25;
    int y = 25;
    // step event
    SDL_Event *e = new SDL_Event();
    while(e->type != SDL_KEYDOWN){
        filledCircleRGBA(m_renderer, x, y, r, 255, 125, 186, 255);
        boxRGBA(m_renderer, x0 - 25, 0,x0 + 25, H, 255, 255, 255, 255);
        cout<<hsp<<endl;
        if((x0 - 25) <= x + r){
            //x = x - 25;
            if(wsp * hsp < 0)   hsp = (abs(wsp) + abs(hsp)) * (-1);
            else                hsp = abs(wsp - hsp) * (-1);
        }
        if(y + r + vsp >= H || y - r + vsp <= 0)   vsp = -vsp;
        if(x + r + hsp >= W || x - r + hsp <= 0)   hsp = -hsp;
        y += vsp;
        x += hsp;
        x0 += wsp;
        if(x0 + wsp >= W || x0 <= W / 2)   wsp = -wsp;

        SDL_RenderPresent(m_renderer);
        SDL_Delay(delay);
        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
        SDL_RenderClear(m_renderer);
        SDL_PollEvent(e);
    }


    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
	SDL_Quit();
    return 0;

}


