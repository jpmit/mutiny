#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <mutiny/mutiny.h>

using namespace mutiny::engine;

class SceneManager : public Behaviour
{
public:
  virtual void onAwake();
  virtual void onGui();
  virtual void onLevelWasLoaded();

private:
  Texture2d* watermark;

  void loadLevel();

};

#endif

