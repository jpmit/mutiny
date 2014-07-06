#ifndef GROUND_H
#define GROUND_H

#include <mutiny/mutiny.h>

using namespace mutiny::engine;

class Ground : public Behaviour
{
public:
  static GameObject* create();

  virtual void onAwake();
  virtual void onUpdate();

private:

};

#endif

