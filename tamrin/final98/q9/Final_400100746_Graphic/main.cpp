#include <iostream>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <string>
#include <fstream>
#include <vector>
// by Dr Arasteh
// by Dr Vosoghi Vahdat
// by MohammadAmin Alamalhoda  ma.alamalhoda@gmail.com


using namespace std;
// struct to save data
struct Point{
int x, y;
};
void triangleRGBA(SDL_Renderer* m_renderer, Point A, Point B, Point C, short Red, short Green, short Blue, short Alpha)
{
    aalineRGBA(m_renderer,A.x,A.y,B.x,B.y,Red,Green,Blue,Alpha);
    aalineRGBA(m_renderer,A.x,A.y,C.x,C.y,Red,Green,Blue,Alpha);
    aalineRGBA(m_renderer,C.x,C.y,B.x,B.y,Red,Green,Blue,Alpha);
}

Point midPoint(Point A,Point B)
{
    Point R;
    R.x=(A.x+B.x)/2;
    R.y=(A.y+B.y)/2;
    return R;
}

void draw(SDL_Renderer *ren, int n, Point p1, Point p2, Point p3)
{
    if(n==0)
    {
        // when you got zero you can start back drawing
        triangleRGBA(ren,p1,p2,p3,255,255,255,255);
        SDL_RenderPresent(ren);
    }
    else if(n>0)
    {
        Point M,N,P;
        //finding middle point to draw inner trangles
        M = midPoint(p1,p2);
        N = midPoint(p2,p3);
        P = midPoint(p1,p3);
        draw(ren,n-1,p1,M,P);
        draw(ren,n-1,M,p2,N);
        draw(ren,n-1,P,N,p3);
    }
}

int main( int argc, char * argv[] )
{
    string s;
    cin>>s;
    ifstream in;
	in.open(s.c_str());
	struct Point p1, p2, p3;
	in>>p1.x;
	in>>p1.y;
	in>>p2.x;
	in>>p2.y;
	in>>p3.x;
	in>>p3.y;
    int n;
    in>>n;
    //Initialization of SDL windows
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN ;//| SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    //Texture for loading image

    int img_w, img_h;
    SDL_Rect img_rect;


    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( 1280, 720, WND_flags, &m_window, &m_renderer );
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen resolution
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    int W = 1280;
    int H = 720;
    // Clear the window with a black background
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );
    draw(m_renderer, n, p1, p2, p3);


    //Show the window

    SDL_RenderPresent( m_renderer );
    SDL_Event *e = new SDL_Event();
    while(e->type != SDL_KEYDOWN)
        SDL_PollEvent(e);

    //Finalize and free resources
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
    IMG_Quit();
    SDL_Quit();
    return 0;

}
