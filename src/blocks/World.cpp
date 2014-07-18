#include "World.h"
#include "Block.h"

using namespace mutiny::engine;

GameObject* World::create()
{
  GameObject* worldGo = new GameObject("World");
  World* world = worldGo->addComponent<World>();
}

void World::onAwake()
{
  for (int i = 0; i < 10; ++i)
  {
    addBlock(0, 0, i * 2);
  }
}

void World::addBlock(int x, int y, int z)
{
  blockMap[std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z)] = Block::create(Vector3(x, y, z));
}
