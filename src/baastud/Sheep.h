#ifndef SHEEP_H
#define SHEEP_H

#include <mutiny/mutiny.h>

using namespace mutiny::engine;

class GameScreen;

class Sheep : public Behaviour
{
public:
  static GameObject* create(GameScreen* gameScreen);

  virtual void onUpdate();
  virtual void onStart();

  void freeze();
  bool isWolf();

private:
  GameScreen* gameScreen;
  Animation* walkAnimation;
  Animation* eatAnimation;
  int state;
  float stateTimeout;
  AnimatedMeshRenderer* sheepMr;
  int random(int min, int max);
  bool wolf;

};

#endif

