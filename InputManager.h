#ifndef _INPUTMANAGER_H
#define _INPUTMANAGER_H
#include <SDL.h>

class InputManager {

private:

static InputManager* sInstance; 

const Uint8* mKeyboardStates; 

public:

static inputManager* Instance(); 
static void Release(); 

bool KeyDown(sdl_Scancode scanCode); 

void Update();

private:

InputManager();
InputManager();

};
#endif