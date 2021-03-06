#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <mutiny/mutiny.h>

using namespace mutiny::engine;

class QuickNumber;

class GameOverScreen : public Behaviour
{
public:
  static int score;

  static GameObject* create();

  virtual void onAwake();
  virtual void onGui();

private:
  std::shared_ptr<QuickNumber> qn;
  Texture2d* background;
  float timeout;

};

#endif

