#include "StartScreen.hpp"


StartScreen::StartScreen(){
    //Top Bar Entities
    mTopBar = new GameEntity(Vector2(Graphics::Instance()->SCREEN_WIDTH*0.5f, 80.0f));

    // mPlayerOne = new Texture("1UP", "emulogic.ttf", 16, {200,0,0});
    // mHiScore = new Texture("HI-SCORE", "emulogic.ttf", 16, { 200,0,0 });

    // mPlayerOne->Parent(mTopBar);
    // mHiScore->Parent(mTopBar);

    // mPlayerOne->Pos(VEC2_ZERO);
    // mHiScore->Pos(VEC2_ZERO);

}

StartScreen::~StartScreen(){

    delete mTopBar;
    mTopBar = NULL;
    delete mPlayerOne;
    mPlayerOne = NULL;
    // delete mHiScore;
    // mHiScore = NULL;


}

void StartScreen::Update(){

}

void StartScreen::Render(){

    mPlayerOne->Render();
    mHiScore->Render();
}