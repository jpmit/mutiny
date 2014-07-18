#ifndef GAMECAMERA_H
#define GAMECAMERA_H

#include <mutiny/mutiny.h>

#include <memory>
#include <vector>

using namespace mutiny::engine;

class GameCamera : public Behaviour
{
public:
  static GameObject* create(GameObject* player);

  virtual void onAwake();
  virtual void onUpdate();
  virtual void onGui();
  
private:
  Camera* camera;
  GameObject* playerGo;
};

#endif

