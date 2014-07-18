#ifndef WORLD_H
#define WORLD_H
#include <mutiny/mutiny.h>

#include <string>
#include <map>

using namespace mutiny::engine;

class World : public Behaviour
{
public:
  static GameObject* create();

  virtual void onAwake();
  void addBlock(int x, int y, int z);
private:
  std::map<std::string, GameObject*> blockMap;
};

#endif
