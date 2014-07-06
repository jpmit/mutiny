#include "Block.h"

#include <iostream>

using namespace mutiny::engine;

GameObject* Block::create()
{
  int p = rand() % 100;
  return Block::create(Vector3(p, 0, 0));
}

void Block::onUpdate()
{
  getGameObject()->getTransform()->rotate(Vector3(20, 0, 0) * Time::getDeltaTime());
}

GameObject* Block::create(Vector3 pos)
{
  GameObject* mainGo = new GameObject("Block");
  Block* cube = mainGo->addComponent<Block>();
  mainGo->getTransform()->setPosition(pos);

  return mainGo;
}

void Block::onStart()
{
  // called first update
  mesh = Resources::load<Mesh>("models/cube");

  // create mesh renderer
  mr = getGameObject()->addComponent<MeshRenderer>();

  // we also need to add a MeshFilter
  mf = getGameObject()->addComponent<MeshFilter>();
  // call this with a Mesh*
  mf->setMesh(mesh);
}
