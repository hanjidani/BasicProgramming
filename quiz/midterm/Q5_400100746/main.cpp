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
    //Initialization of SDL windows
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;// | SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
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

    int x0 = W / 2, y0 = H / 2, d = 300;
    double f = 0.03;
    int x1 = 0,y1 = y0 - d*sin((-x0) * f), x2,y2, y;
    bool draw = true, flag = true;
    //Wait for a key to be pressed
    SDL_Event *e = new SDL_Event();
    while(flag){
        e->type = 0;
        SDL_PollEvent(e);
        if(e->type==SDL_KEYDOWN){
            if(e->key.keysym.sym == SDLK_ESCAPE) 
                flag=false;
        }
        if(draw){
            SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
            SDL_RenderClear( m_renderer );
            aalineRGBA(m_renderer, 0, y0, W, y0, 255, 255, 255, 255);
            aalineRGBA(m_renderer, x0, 0, x0, H, 255, 255, 255, 255);
            for(int x = 1; x < W; x++){
                y = y0 - d*sin((x - x0)*f);
                aalineRGBA(m_renderer, x1, y1, x, y, 255, 255, 255, 255);
                x1 = x;
                y1 = y;
            }
            x1 = 0;
            y1 = y0 - d*sin((-x0) * f);
            draw = false;
        }
        if(e->type==SDL_MOUSEBUTTONDOWN){
             if(e -> button.button == SDL_BUTTON_LEFT && e -> button.clicks == 2){
                    x0 = e-> motion.x;
                    y0 = e-> motion.y;
                    y1 = y0 - d*sin((-x0) * f);
                    draw = true;
                    //c = 0;
               
             }
        }
        SDL_RenderPresent(m_renderer);

    }
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
	SDL_Quit();
    return 0;

}


