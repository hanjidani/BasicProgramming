#include <SDL2/SDL_ttf.h>
//#include "lib.cpp"

#define IMG_address_01 "EE_SDL_Linux/01.jpeg"

void textRGBA(SDL_Renderer *renderer, int x, int y, const char *text, int font, int font_size, Uint8 R, Uint8 G, Uint8 B, Uint8 A);
void textColor(SDL_Renderer *renderer, int x, int y, const char *text, int font, int font_size, SDL_Color textColor);
