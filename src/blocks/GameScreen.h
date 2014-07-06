#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "Block.h"

#include <mutiny/mutiny.h>

#include <memory>

using namespace mutiny::engine;

class GameScreen : public Behaviour
{
public:
  static GameObject* create();

  virtual void onAwake();
  virtual void onGui();
  // onStart is called on the first update
  virtual void onStart();

private:
  GameObject* cameraGo;
  Texture2d* crosshairs;

};

#endif

