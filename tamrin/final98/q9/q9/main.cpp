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

void draw(int n, SDL_Renderer *ren, int x, int y, int r)
{
    if(n >= 0 && r > 0)
    {
        ellipseRGBA(ren, x, y, r, r, rand() % 256, rand() % 256, rand() % 256, 255);
        draw(n - 1, ren, x, y - r / 2, r /2);
        draw(n - 1, ren, x, y + r / 2, r /2);
        draw(n - 1, ren, x - r / 2, y, r /2);
        draw(n - 1, ren, x + r / 2, y, r /2);
        //SDL_Delay(10);
        SDL_RenderPresent(ren);
    }
}
void findMaxMin(int arr[], int n, int &max, int &min)
{
    max = arr[0];
    min = arr[0];
    for(int i = 0; i < n; i++)
    {
        if(max < arr[i])
            max = arr[i];
        if(max > arr[i])
            min = arr[i];
    }
}
void drawLineChart(int data[], int n, int x0, int y0, SDL_Renderer *ren, int vSize)
{
    thickLineRGBA(ren, x0, 0, x0, y0, 5, 255, 255, 255, 255);
    thickLineRGBA(ren, x0, y0, 1280, y0, 5, 255, 255, 255, 255);
    //cal each number found
    int mx, mn;
    findMaxMin(data, n, mx, mn);
    int yy = max(vSize / mx, 1);
    int xx = max((1280 - x0) / (n + 1), 1);
    n--;
    cout<<n;
    for(int i = 0; i < n; i++)
    {
        aalineRGBA(ren, (i + 1) * xx,y0 - data[i] * yy, (i + 2) * xx,y0 - data[i + 1] * yy, rand() % 256, rand() % 256, rand() % 256, 255);
        SDL_RenderPresent(ren);
    }
}

void drawInside(int x, int y, int r, int n,SDL_Renderer *ren)
{
    aaellipseRGBA(ren, x, y, r, r, rand() % 256, rand() % 256, rand() % 256, 255);
    const double pi = 3.14159265358979323846;
    double step = 2 * pi / n;
    for(int i = 0; i <= n; i++)
    {
        aalineRGBA(ren,x + r * cos(step * i),y - r * sin(step * i), x + r * cos(step * (i + 1)), y - r * sin(step * (i + 1)), rand() % 256, rand() % 256, rand() % 256, 255);
        SDL_RenderPresent(ren);
        SDL_Delay(50);
    }
}

short distance(short x0, short y0, short x1, short y1)
{
    return (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
}

short minDis(short xs[], short ys[], short n, short x0, short y0, short index)
{
    int minDis, minIndex;
    if(distance(x0, y0, xs[0], ys[0]) > 0)
    {
        minDis = distance(x0, y0, xs[0], ys[0]);
        minIndex = 0;
    }
    else
    {
        minDis = distance(x0, y0, xs[1], ys[1]);
        minIndex = 1;
    }
    int temp;
    for(short i = 0; i < n; i++)
    {
        temp = distance(xs[i], ys[i], x0, y0);
        if(temp <= minDis && i != index && temp != 0)
        {
            minIndex = i;
            minDis = temp;
        }
    }
    return minIndex;
}

void drawMohaddab(short Xs[], short Ys[], short n, SDL_Renderer *ren)
{
    short indexes[n];
    // calculate the right awnser
    indexes[0] = 0;
    for(int i = 1; i < n; i++)
        indexes[i] = minDis(Xs, Ys, n, Xs[indexes[i - 1]], Ys[indexes[i - 1]], indexes[max(0,i - 2)]);
    short fx[n], fy[n];
    for(int i = 0; i < n; i++)
    {
        fx[i] = Xs[indexes[i]];
        fy[i] = Ys[indexes[i]];
    }
    polygonRGBA(ren, fx, fy, n, rand() % 256, rand() % 256, rand() % 256, 255);
}
struct point{
    int x = -1, y = -1;
};
int dir(int x0, int y0, int x1, int y1){
    if(x0 - x1 == 0){
        if(y0 >= y1)    return 1;
        else            return 3;
    } else if(x0 > x1)  return 2;
      else              return 0;
}
void drawPath(SDL_Renderer *ren, string input){
    struct point pt[100];
    int n = 0;
    ifstream in;
	in.open(input.c_str());
    in>>n;
    for(int i = 0; i < n; i++)
        in>>pt[i].x>>pt[i].y;
    /*  dir
        0 -> right
        1 -> up
        2 -> left
        3 -> down
    */
    int prdir = dir(pt[0].x, pt[0].y, pt[1].x, pt[1].y), dirr = -1, tax = 0, pr_x = pt[0].x, pr_y = pt[0].y;
    for(int i = 1; i < n; i++){
        prdir = dirr;
        dirr = dir(pt[i - 1].x, pt[i - 1].y, pt[i].x, pt[i].y);
        if(dirr != prdir){
            aalineRGBA(ren, pr_x, pr_y, pt[i].x, pt[i].y, 255, 255, 255, 255);
            pr_x = pt[i].x;
            pr_y = pt[i].y;
        }
        if(prdir == 0 && dirr == 1){
            tax++;
            filledCircleRGBA(ren,  pt[i - 1].x, pt[i - 1].y, 5, 255, 0, 0, 255);
        } else if(prdir == 1 && dirr == 2){
            tax++;
            filledCircleRGBA(ren,  pt[i - 1].x, pt[i - 1].y, 5, 255, 0, 0, 255);
        } else if(prdir == 2 && dirr == 3){
            tax++;
            filledCircleRGBA(ren,  pt[i - 1].x, pt[i - 1].y, 5, 255, 0, 0, 255);
        } else if(prdir == 3 && dirr == 0){
            tax++;
            filledCircleRGBA(ren,  pt[i - 1].x, pt[i - 1].y, 5, 255, 0, 0, 255);
        }
    }
    boxRGBA(ren, pt[0].x - 5, pt[0].y - 5, pt[0].x + 5, pt[0].y + 5, 0, 255, 0, 255);
    boxRGBA(ren, pt[n - 1].x - 5, pt[n - 1].y - 5, pt[n - 1].x + 5, pt[n - 1].y + 5, 0, 0, 255, 255);
    aalineRGBA(ren, pr_x, pr_y, pt[n - 1].x, pt[n - 1].y, 255, 255, 255, 255);

}
vector<int> a;
vector<int> b;
vector<int> c;
void drawVectors(SDL_Renderer *ren){
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    SDL_RenderClear(ren);
    int ax = 320, bx = 640, cx = 960;
    int ay = 700, by = ay, cy = ay;
    for(int i = 0; i < a.size(); i++){
        boxRGBA(ren, ax - a[i] / 2, ay, ax + a[i] / 2, ay - 50, 255, 255, 255, 255);
        ay -= 50;
    }
    for(int i = 0; i < b.size(); i++){
        boxRGBA(ren, bx - b[i] / 2, by, bx + b[i] / 2, by - 50, 255, 255, 255, 255);
        by -= 50;
    }
    for(int i = 0; i < c.size(); i++){
        boxRGBA(ren, cx - c[i] / 2, cy, cx + c[i] / 2, cy - 50, 255, 255, 255, 255);
        cy -= 50;
    }
    SDL_RenderPresent(ren);
    SDL_Delay(50);
}

void move(vector<int> &from, vector<int> &to, SDL_Renderer *ren){
    to.push_back(from[from.size() - 1]);
    from.pop_back();
    drawVectors(ren);
}

void hanoi(int n, vector<int> &A, vector<int> &B, vector<int> &C, SDL_Renderer *ren){
	if(n > 0){
		hanoi(n - 1, A, C, B, ren);
		move(A, C, ren);
		hanoi(n - 1, B, A, C, ren);
	}
}

void drawHanoi(SDL_Renderer *ren, int n){
    for(int i = n; i >= 1; i--)
        a.push_back(50 * i);
    hanoi(n, a, b, c, ren);
}

int main( int argc, char * argv[] )
{
    int n;
    cin>>n;
    /*string name;
    cin>>name;*/
    /*int n;
    cin>>n;
    short xs[n], ys[n];
    for(int i = 0; i < n; i++)
        cin>>xs[i]>>ys[i];
    */
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

    //drawMohaddab(xs, ys, n, m_renderer);
    //draw(100, m_renderer, W / 2, H / 2, 360);
    //drawLineChart(arr, n, 100, 620, m_renderer, 620);
    //drawInside(W / 2, H / 2, H / 2, 10, m_renderer);
    //short int x[3] = {0, 100 , 200}, y[3]{0, 300, 400};
    //filledPolygonRGBA(m_renderer, x, y, 3, 255, 255, 255, 255);
    //SDL_RenderPresent(m_renderer);
    //drawPath(m_renderer, name);
    drawHanoi(m_renderer, n);
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
