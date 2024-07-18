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

int mx(int a[]){
    int m = -1;
    for(int i = 0; i < 10; i ++){
        if(a[i] > m)    m = a[i];
    }
    return m;
}

void addvalue(int a[]){
    int num = rand() % 10;
    a[num]++;
}

int color(int n){
	if(n <= 10)  return 255;
    else if (n > 20)    return 0;
    else    return 255 - (25.5 * n);
}
int main( int argc, char * argv[] )
{
	srand(time(NULL));
    //Initialization of SDL windows
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN; //| SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
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
    //Wait for a key to be pressed
    //set some logic
    int room_speed = 5;
    int delay = 1000 / room_speed;
    // on app start
    int data[10];
    int max1;
    int x0 = 100, y0 = 700;
    for(int i = 0; i < 10; i++){
        data[i] = 1;
    }
    int h = 600;
    bool first = true;
    // step event
    SDL_Event *e = new SDL_Event();
    while(e->type != SDL_KEYDOWN){
        if(!first){
            max1 = mx(data);
            int row = max(1, h / max1);
            for(int i = 0; i < 10; i ++){
                
                    int fx = 100 * i;
                    int col = color(data[i]);
                    boxRGBA(m_renderer, x0 + fx, y0, x0 + fx + 100, y0 - data[i] * row, 255, col, col, 255);
                
            }
        } else  aalineRGBA(m_renderer, 100, y0, 1100, y0, 255, 255, 255, 255);
        addvalue(data);
        
        SDL_RenderPresent(m_renderer);
        if(first)   SDL_Delay(2000);
        else        SDL_Delay(delay);
        first = false;
        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
        SDL_RenderClear(m_renderer);
        SDL_PollEvent(e);
    }


    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
	SDL_Quit();
    return 0;

}


