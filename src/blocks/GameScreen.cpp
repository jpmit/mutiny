#include "GameScreen.h"
#include "Block.h"
#include "GameCamera.h"
#include "Ground.h"

#include <iostream>

using namespace mutiny::engine;

GameObject* GameScreen::create()
{
  GameObject* mainGo = new GameObject("GameScreen");
  mainGo->addComponent<GameScreen>();

  return mainGo;
}

void GameScreen::onAwake()
{
  crosshairs = Resources::load<Texture2d>("textures/crosshairs");
}

void GameScreen::onGui()
{
  Gui::drawTexture(Rect((Screen::getWidth() / 2) - (crosshairs->getWidth() / 2),
                        (Screen::getHeight() / 2) - (crosshairs->getHeight() / 2),
                        crosshairs->getWidth(), crosshairs->getHeight()), crosshairs);
}

void GameScreen::onStart()
{
  cameraGo = GameCamera::create();

  Block::create(Vector3(0, 0, 0));
  
  for (int i = 0; i < 10; ++i)
  {
    Block::create();
  }

  Ground::create();
}

