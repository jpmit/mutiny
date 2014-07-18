#include "GameCamera.h"

#include <iostream>
#include <iomanip>

GameObject* GameCamera::create(GameObject* player)
{
  GameObject* mainGo = new GameObject("GameCamera");
  GameCamera* gameCamera = mainGo->addComponent<GameCamera>();
  gameCamera->playerGo = player;
  return mainGo;
}

void GameCamera::onAwake()
{
  // the actual camera!
  camera = getGameObject()->addComponent<Camera>();
}

void GameCamera::onUpdate()
{
  getGameObject()->getTransform()->setPosition(playerGo->getTransform()->getPosition());
  getGameObject()->getTransform()->setRotation(playerGo->getTransform()->getRotation());  
}

void GameCamera::onGui()
{
  std::stringstream p, r;
  p.precision(2);
  r.precision(2);  

  Vector3 pos = getGameObject()->getTransform()->getPosition();
  Vector3 rot = getGameObject()->getTransform()->getRotation();

  p << "pos: " << std::fixed << pos.x << " " << pos.y << " " << pos.z;
  r << "rot: " << std::fixed << rot.x << " " << rot.y << " " << rot.z;
  Gui::label(Rect(300, 10, 300, 100), p.str());
  Gui::label(Rect(300, 30, 300, 100), r.str());  
}

