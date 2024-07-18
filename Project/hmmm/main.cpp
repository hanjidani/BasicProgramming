// TODO ask nika for the cordinates
// TODO ask nika for the method to pass score as string
#include <iostream>
//#include <iostream>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "EE_SDL_Linux/lib.h"
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <string>
#define nbtn 50

// by Dr Arasteh
// by Dr Vosoghi Vahdat
// by MohammadAmin Alamalhoda  ma.alamalhoda@gmail.com 
// On linux by mohammad hossein besharti

using namespace std;

int globalStat = 0;


int btn_array[nbtn][4]; // X0, Y0, X1, Y1

int um_btnArray[50][4]; // X0, Y0, X1, Y1

char intToChar(int i){
    return i + '0';
}

string intToString(int a){
    int m = 1;
    string ret = "";
    while(a != 0){
        ret = intToChar(a % 10) + ret;
        a /= 10; 
    }
    return ret;
}
// 0 1 2 just for the pause button
bool um_clicked(int index, int mouse_x, int mouse_y){
    if(mouse_x >= um_btnArray[index][0] && mouse_x <= um_btnArray[index][2] 
    && mouse_y >= um_btnArray[index][1] && mouse_y <= um_btnArray[index][3])   return true;
    else    return false;
}

bool btn_clicked(int index, int mouse_x, int mouse_y){
    if(mouse_x >= btn_array[index][0] && mouse_x <= btn_array[index][2] 
    && mouse_y >= btn_array[index][1] && mouse_y <= btn_array[index][3])   return true;
    else    return false;
}

void gradient(SDL_Renderer* m_renderer, short int vx[], short int vy[])
{
    int n = 40;
    for (int i = 0; i < n; i++)
    {
        aalineRGBA(m_renderer, vx[0] + i * (vx[0] - vx[3]) / (vy[0] - vy[3]), vy[0] + i, vx[1] - i, vy[1] + i, 255, 255, 255, 255 * (n - i) / n);
        aalineRGBA(m_renderer, vx[1] - i, vy[1] + i, vx[2] - i, vy[2] - i, 255, 255, 255, 255 * (n - i) / n);
        aalineRGBA(m_renderer, vx[2] - i, vy[2] - i, vx[3] - i * (vx[0] - vx[3]) / (vy[0] - vy[3]), vy[3] - i, 255, 255, 255, 255 * (n - i) / n);
        //        aalineRGBA(m_renderer,vx[0]+i,vy[0]+i,vx[3]+i,vy[3]-i,255,255,255,255*(n-i)/n);
    }
}


//m_texture: main game texture // W: width of screen // H: height of screen // ump_w: slope of pause menu // score: current score
int PauseMenu(SDL_Renderer* m_renderer, SDL_Texture* m_texture, int W, int H, int ump_w, int score)
{
    SDL_Texture* ump_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, W, H);

    SDL_SetRenderTarget(m_renderer, ump_texture);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);

    //0 for resume, 1 for restart, 2 for quit
    int i = 0;

    //menu background
    short int vx[4] = { W / 2 + ump_w,W,W,W / 2 - ump_w }, vy[4] = { 0,0,H,H };
    filledPolygonColor(m_renderer, vx, vy, 4, 0xff330000);

    //score
    //TODO Ask nika it :)
    textRGBA(m_renderer, W / 2 + ump_w + W / 10, 100, "SCORE:", 2, 40, 255, 255, 255, 255);
    textRGBA(m_renderer, W / 2 + ump_w + W / 6 + 80, 150, ump_score, 2, 40, 255, 255, 255, 255);
    
    SDL_SetRenderTarget(m_renderer, NULL);
    SDL_Event* e = new SDL_Event();
    bool ump_nbp = true; // avoid unnecessary rendering
    while (1)
    {
        e->type = NULL;
        SDL_PollEvent(e);
        mx = e->motion.x;
        my = e->motion.y;
        
        // if (e->type == SDL_KEYDOWN)
        // {
        //     if (e->key.keysym.sym == SDLK_RETURN)
        //     {
        //         SDL_DestroyTexture(ump_texture);
        //         return i;
        //     }

        //     else if (e->key.keysym.sym == SDLK_DOWN)
        //     {
        //         ump_nbp = true;
        //         i++;
        //         i %= 3;
        //     }
        //     else if (e->key.keysym.sym == SDLK_UP)
        //     {
        //         ump_nbp = true;
        //         i--;
        //         i = (3 + i) % 3;
        //     }
        // }

        if (ump_nbp)
        {
            ump_nbp = false;
            SDL_RenderCopy(m_renderer, ump_texture, NULL, NULL);

            //buttons
            if (i == 0)
            {
                short int ump_vx[4] = { ump_w + W / 2 + 10 - 2 * 320 * ump_w / H,W,W,ump_w + W / 2 + 10 - 2 * 420 * ump_w / H };
                short int ump_vy[4] = { 320,320,420,420 };
                filledPolygonRGBA(m_renderer, ump_vx, ump_vy, 4, 0, 150, 150, 255);
                gradient(m_renderer, ump_vx, ump_vy);
                textRGBA(m_renderer, W / 2 + ump_w + 80, 350, "Resume", 2, 40, 0, 0, 0, 255);
                textRGBA(m_renderer, W / 2 + ump_w + 80, 450, "Restart", 2, 40, 255, 255, 255, 255);
                textRGBA(m_renderer, W / 2 + ump_w + 80, 550, "Quit", 2, 40, 255, 255, 255, 255);
            }
            else if (i == 1)
            {
                short int ump_vx[4] = { ump_w + W / 2 + 10 - 2 * 420 * ump_w / H,W,W,ump_w + W / 2 + 10 - 2 * 520 * ump_w / H };
                short int ump_vy[4] = { 420,420,520,520 };
                filledPolygonRGBA(m_renderer, ump_vx, ump_vy, 4, 0, 150, 150, 255);
                gradient(m_renderer, ump_vx, ump_vy);
                textRGBA(m_renderer, W / 2 + ump_w + 80, 450, "Restart", 2, 40, 0, 0, 0, 255);
                textRGBA(m_renderer, W / 2 + ump_w + 80, 350, "Resume", 2, 40, 255, 255, 255, 255);
                textRGBA(m_renderer, W / 2 + ump_w + 80, 550, "Quit", 2, 40, 255, 255, 255, 255);
            }
            else
            {
                short int ump_vx[4] = { ump_w + W / 2 + 10 - 2 * 520 * ump_w / H,W,W,ump_w + W / 2 + 10 - 2 * 620 * ump_w / H };
                short int ump_vy[4] = { 520,520,620,620 };
                filledPolygonRGBA(m_renderer, ump_vx, ump_vy, 4, 0, 150, 150, 255);
                gradient(m_renderer, ump_vx, ump_vy);
                textRGBA(m_renderer, W / 2 + ump_w + 80, 550, "Quit", 2, 40, 0, 0, 0, 255);
                textRGBA(m_renderer, W / 2 + ump_w + 80, 350, "Resume", 2, 40, 255, 255, 255, 255);
                textRGBA(m_renderer, W / 2 + ump_w + 80, 450, "Restart", 2, 40, 255, 255, 255, 255);
            }

            SDL_RenderPresent(m_renderer);
        }

    }

}
