#include <iostream>
//#include <iostream>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "EE_SDL_Linux/lib.h"
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <string>
#include <cmath>


// by Dr Arasteh
// by Dr Vosoghi Vahdat
// by MohammadAmin Alamalhoda  ma.alamalhoda@gmail.com 
// On linux by mohammad hossein besharti

using namespace std;

int sign(int x){
    return (x >= 0)? 1 : -1;
}

double sin(int x0, int y0, int x1, int y1){
    return double(y1) - y0 / sqrt((double(x1 - x0) * double(x1 - x0)) + (double(y1 - y0) * double(y1 - y0))); 
}

double cos(int x0, int y0, int x1, int y1){
    return double(x1) - x0 / sqrt((double(x1 - x0) * double(x1 - x0)) + (double(y1 - y0) * double(y1 - y0))); 
}

void ee(int &hsp, int &vsp, int x, int y, int mx, int my){
    float tv = sqrt((hsp * hsp) + (vsp * vsp));
    float theta;
    if(hsp != 0)    theta = atan(double(vsp) / double(hsp));
    else            theta = 3.14;
    if(x - mx != 0){ 
            if(x - mx < 0){
                float phi = atan((double(y) - my) / (double(x) - mx));
                float angle = theta - phi;
                hsp = -((tv * cos(angle) * cos(phi)) + tv * sin(angle) * sin(phi));
                vsp = -((tv * cos(angle) * sin(phi)) + tv * sin(angle) * cos(phi));
            } else {
                float phi = atan((double(y) - my) / (double(x) - mx));
                float angle = theta - phi;
                hsp = ((tv * cos(angle) * cos(phi)) + tv * sin(angle) * sin(phi));
                vsp = ((tv * cos(angle) * sin(phi)) + tv * sin(angle) * cos(phi));
            }
    } else {
        hsp = -hsp;
        vsp = -vsp;
    }
}

int dis(int x0, int y0, int x1, int y1){
    return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

int main( int argc, char * argv[] )
{
    //Initialization of SDL windows
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;// | SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    int W = 1200;
    int H = 900;
    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( W, H, WND_flags, &m_window, &m_renderer );
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen resolution
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);

    // Clear the window with a black background
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );

    // Show the window
    SDL_RenderPresent( m_renderer );
    // set some logic
    int room_speed = 200;
    int delay = 1000 / room_speed;
    // on start
    bool clicked = false;
    bool rclicked = false;
    bool rfirst = false;
    int r = 50;
    int x0 = 100, y0 = 100, vsp = 10, hsp = 10;
    double a = 0.01;
    int ax = 0;
    int ay = 0;
    double tan;
    int mx, my;
    bool flag = true;
    //Wait for a key to be pressed
    SDL_Event *e = new SDL_Event();
    while(flag){
        if(e->type == SDL_KEYDOWN){
            if(e->key.keysym.sym == SDLK_ESCAPE) 
                flag=false;
            else if(e->key.keysym.sym == SDLK_SPACE){
                hsp -= sign(hsp);
                vsp -= sign(vsp);
            }
        }
        x0 += hsp;
        y0 += vsp;
        if(e->type == SDL_MOUSEBUTTONDOWN && e -> button.button == SDL_BUTTON_LEFT )    clicked = true;
        if(e->type == SDL_MOUSEBUTTONDOWN && e -> button.button == SDL_BUTTON_RIGHT )    rclicked = true;
        else if(e->type == SDL_MOUSEBUTTONUP){
            clicked = false;
            rclicked = false;
            rfirst = false;
            vsp = sign(vsp) * 10;
            hsp = sign(hsp) * 10;
        }
        if(rclicked){
            if(!rfirst){
                rfirst = true;
                vsp = 0;
                hsp = 0;
                ax = 0;
                ay = 0; 
            }
            //boxRGBA(m_renderer, 0, 0, 100, 100, 255, 255, 255, 255);
            mx = e->motion.x;            
            my = e->motion.y;
            ax = cos(x0, y0, mx, my) * a;
            ay = sin(x0, y0, mx, my) * a;
            vsp += ay;
            hsp += ax;
        }
        if((x0 + r + hsp >= W) || (x0 - r + hsp <= 0))  hsp = -hsp;
        if((y0 + r + vsp >= H) || (y0 - r + vsp <= 0))  vsp = -vsp;
        if(clicked){
            mx = e->motion.x;
            my = e->motion.y;
            filledEllipseRGBA(m_renderer, mx, my, 20, 20, 255,255, 255, 255);
            if(dis(x0, y0, mx, my) < 20 + r){
                ee(hsp, vsp, x0, y0, e->motion.x, e->motion.y);
            }
        }

        filledEllipseRGBA(m_renderer, x0, y0, r, r, 255, 255, 0, 255);
        e->type = 0;
        SDL_RenderPresent(m_renderer);
        SDL_Delay(delay);
        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
        SDL_RenderClear(m_renderer);
        SDL_PollEvent(e);
    }
    

    //Finalize and free resources
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
	SDL_Quit();
    return 0;

}


