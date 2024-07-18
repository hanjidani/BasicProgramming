#include "lib.h"

void textRGBA(SDL_Renderer *renderer, int x, int y, const char *text, int font, int font_size, Uint8 R, Uint8 G, Uint8 B, Uint8 A)
{

    TTF_Init();

    SDL_Color text_color = {R, G, B, A};

    const char *font_address_01 = "./EE_SDL_Linux/lazy.ttf";

    const char *font_address_02 = "./EE_SDL_Linux/arial.ttf";

    const char *font_address_03 = "./B_Roya.ttf";

    const char *font_address_04 = "./SHABNAM.ttf";

    const char *font_address_05 = "./SHABNAM_BOLD.ttf";

    const char *font_address_06 = "./SHABNAM_LIGHT.ttf";

    const char *Font = NULL;

    if (font == 1)
    {
        Font = font_address_01;
    }

    if (font == 2)
    {
        Font = font_address_02;
    }

    if (font == 3)
    {
        Font = font_address_03;
    }

    if (font == 4)
    {
        Font = font_address_04;
    }

    if (font == 5)
    {
        Font = font_address_05;
    }

    if (font == 6)
    {
        Font = font_address_06;
    }

    int mWidth = 0;
    int mHeight = 0;
    SDL_Rect *clip = NULL;
    TTF_Font *gFont = NULL;
    double angle = 0.0;
    SDL_Point *center = NULL;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_Texture *mTexture = NULL;
    gFont = TTF_OpenFont(Font, font_size);

    SDL_Surface *textSurface = TTF_RenderText_Solid(gFont, text, text_color);

    mWidth = textSurface->w;
    mHeight = textSurface->h;
    mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);

    SDL_Rect renderQuad = {x, y, mWidth, mHeight};
    SDL_RenderCopyEx(renderer, mTexture, clip, &renderQuad, angle, center, flip);

    SDL_DestroyTexture(mTexture);
    SDL_RenderPresent(renderer);
}

void textColor(SDL_Renderer *renderer, int x, int y, const char *text, int font, int font_size, SDL_Color textColor)

{
    TTF_Init();

    const char *font_address_01 = "./lazy.ttf";

    const char *font_address_02 = "./EE_SDL_Linux/arial.ttf";

    const char *font_address_03 = "./B_Roya.ttf";

    const char *font_address_04 = "./SHABNAM.ttf";

    const char *font_address_05 = "./SHABNAM_BOLD.ttf";

    const char *font_address_06 = "./SHABNAM_LIGHT.ttf";

    const char *Font = NULL;

    if (font == 1)
    {
        Font = font_address_01;
    }

    if (font == 2)
    {
        Font = font_address_02;
    }

    if (font == 3)
    {
        Font = font_address_03;
    }

    if (font == 4)
    {
        Font = font_address_04;
    }

    if (font == 5)
    {
        Font = font_address_05;
    }

    if (font == 6)
    {
        Font = font_address_06;
    }

    int mWidth = 0;
    int mHeight = 0;
    SDL_Rect *clip = NULL;
    TTF_Font *gFont = NULL;
    double angle = 0.0;
    SDL_Point *center = NULL;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_Texture *mTexture = NULL;
    gFont = TTF_OpenFont(Font, font_size);

    SDL_Surface *textSurface = TTF_RenderText_Solid(gFont, text, textColor);

    mWidth = textSurface->w;
    mHeight = textSurface->h;
    mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);

    SDL_Rect renderQuad = {x, y, mWidth, mHeight};
    SDL_RenderCopyEx(renderer, mTexture, clip, &renderQuad, angle, center, flip);

    SDL_DestroyTexture(mTexture);
    SDL_RenderPresent(renderer);
}
