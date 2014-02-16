#include "Horse.h"
#include "GameScreen.h"
#include "GameCamera.h"

#include <iostream>

using namespace mutiny::engine;

Horse* Horse::create(GameScreen* gameScreen)
{
  GameObject* mainGo = new GameObject("Horse");
  Horse* horse = mainGo->addComponent<Horse>();
  horse->gameScreen = gameScreen;

  return horse;
}

void Horse::onAwake()
{
  mr = getGameObject()->addComponent<AnimatedMeshRenderer>();
  AnimatedMesh* mesh = Resources::load<AnimatedMesh>("models/horse/horse");
  mr->setAnimatedMesh(mesh);

  runAnimation = Resources::load<Animation>("models/horse/run.anm");

  mr->setAnimation(runAnimation);
  mr->setInterpolateEnd(false);
  mr->setFps(8.0f);
  mr->play();

  getGameObject()->getTransform()->setPosition(Vector3(0, -0.5f, 0));
}

void Horse::onUpdate()
{
  getGameObject()->getTransform()->translate(Vector3(5, 0, 0) * Time::getDeltaTime());
}

void Horse::onGui()
{

}
