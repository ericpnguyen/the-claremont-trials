#ifndef  _TEXTURE_H
#define _TEXTURE_H

#include "Graphics.hpp"
#include "Screens.hpp"

class Texture : public Screens{
private:
    SDL_Texture* mTex;

    Graphics* mGraphics;

public:

    Texture(std::string path);
    ~Texture();

    virtual void Render();
};

#endif