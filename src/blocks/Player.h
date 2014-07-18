#ifndef PLAYER_H
#define PLAYER_H

#include <mutiny/mutiny.h>

using namespace mutiny::engine;

class Player : public Behaviour
{
public:
  static GameObject* create(GameObject* world);

  virtual void onAwake();
  virtual void onStart();
  virtual void onUpdate();

  void processMovement();
  void setActive();
private:
  GameObject* worldGo;
  static constexpr float maxHeight = 4.0;
  static constexpr float minHeight = 0.0;
  static constexpr float maxHitDistance = 10.0;
  bool active;
  bool timeActive;
  bool jumping;
  bool falling;
  float totTime;
};

#endif

