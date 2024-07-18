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

int color(int a, int w, int h){
    a = a * a;
    w = w * h;
    double t = double(w) / a;
    int ret = t * 255;
    return 255 - ret;
}   

void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, bool fill_boolean){
    SDL_Rect rectangle ;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;
    SDL_SetRenderDrawColor(Renderer, R, G, B, 255);
    if (fill_boolean)
        SDL_RenderFillRect(Renderer, &rectangle);
    SDL_RenderDrawRect(Renderer, &rectangle);
}

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
    SDL_CreateWindowAndRenderer( 1200, 600, WND_flags, &m_window, &m_renderer );
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen resolution
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    int W = 1200;
    int H = 600;
    // Clear the window with a black background
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );

    // Show the window
    SDL_RenderPresent( m_renderer );
    //Wait for a key to be pressed
    //set some logic
    int room_speed = 50;
    int delay = 1000 / room_speed;
    // on app start
    int a = 250;
    int vsp1 = 5;
    int vsp2 = 8;
    int hsp1 = 5;
    int hsp2 = -8;
    int r1x1 = 0, r1y1 = 0, r2x1 = W - a - 200, r2y1 = 0; 
    int tw, th, tx, ty;
    int col;
    // step event
    SDL_Event *e = new SDL_Event();
    while(e->type != SDL_KEYDOWN){
        rect(m_renderer, r1x1, r1y1, a, a, 0, 255, 0, true);
        rect(m_renderer, r2x1, r2y1, a, a, 0, 0, 255, true);
        if(r1x1 + hsp1 < 0 || r1x1 + a + hsp1 > W)  hsp1 = -hsp1;
        if(r2x1 + hsp2 < 0 || r2x1 + a + hsp2 > W)  hsp2 = -hsp2;
        if(r1y1 + vsp1 < 0 || r1y1 + a + vsp1> H)  vsp1 = -vsp1;
        if(r2y1 + vsp2 < 0 || r2y1 + a + vsp2 > H)  vsp2 = -vsp2;
        if(abs(r1x1 - r2x1) <= a && abs(r1y1 - r2y1) <= a){
            /*tx = max(r1x1, r2x1);
            ty = min(r2y1, r1y1);
            tw =*/
            if((r2x1 >= r1x1) && (r2x1 <= r1x1 + a)){
                if((r2y1 >= r1y1) && (r2y1 <= r1y1 + a)){
                    tw = r1x1 + a - r2x1;
                    th =  r1y1 - r2y1 + a;
                    col = color(a, tw, th);
                    rect(m_renderer, r2x1, r2y1, tw, th, 255, col, col, true);        
                } else if((r2y1 + a >= r1y1) && (r2y1 + a <= r1y1 + a)){
                    tw = r1x1 + a - r2x1;
                    th =  r2y1 + a - r1y1;
                    col = color(a, tw, th);
                    rect(m_renderer, r2x1, r1y1, tw, th, 255, col, col, true);
                }
            }else if((r1x1 >= r2x1) && (r1x1 <= r2x1 + a)){          
                if((r1y1 >= r2y1) && (r1y1 <= r2y1 + a)){
                    tw = r2x1 + a - r1x1;
                    th =  r2y1 - r1y1 + a;
                    col = color(a, tw, th);
                    rect(m_renderer, r1x1, r1y1, tw, th, 255, col, col, true);        
                } else if((r1y1 + a >= r2y1) && (r1y1 + a <= r2y1 + a)){
                    tw = r2x1 + a - r1x1;
                    th =  r1y1 + a - r2y1;
                    col = color(a, tw, th);
                    rect(m_renderer, r1x1, r2y1, tw, th, 255, col, col, true);
                }
            }
        }
        r1x1 += hsp1;
        r2x1 += hsp2;
        r1y1 += vsp1;
        r2y1 += vsp2;
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


