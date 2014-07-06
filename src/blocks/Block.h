#ifndef BLOCK_H
#define BLOCK_H

#include <mutiny/mutiny.h>

using namespace mutiny::engine;

class Block : public Behaviour
{
public:
  static GameObject* create();
  static GameObject* create(Vector3 pos);
  
  virtual void onUpdate();
  virtual void onStart();

private:
  Mesh* mesh;
  MeshRenderer* mr;
  MeshFilter* mf;

};

#endif

