#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <mutiny/mutiny.h>

#include <memory>

using namespace mutiny::engine;

class GameScreen : public Behaviour
{
public:
  static GameObject* create();

  virtual void onAwake();
  virtual void onGui();

private:
  Texture2d* wwwTexture;
  Texture2d* titleTexture;
  GameObject* cameraGo;

};

#endif

