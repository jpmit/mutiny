#include "IntroductionScreen.h"

#include <iostream>

using namespace mutiny::engine;

GameObject* IntroductionScreen::create()
{
  GameObject* mainGo = new GameObject("IntroductionScreen");
  mainGo->addComponent<IntroductionScreen>();

  return mainGo;
}

void IntroductionScreen::onAwake()
{
  cameraGo = new GameObject("MainCamera");
  Camera* camera = cameraGo->addComponent<Camera>();
}

void IntroductionScreen::onGui()
{
  int middle = Screen::getWidth() / 2;
  int padding = 5;

  if(Gui::button(Rect(middle - 200 - padding, 200, 200, 50), "Transform") == true)
  {
    Application::loadLevel("transform");
  }

  if(Gui::button(Rect(middle - 200 - padding, 300, 200, 50), "Simple Model") == true)
  {
    Application::loadLevel("model");
  }

  if(Gui::button(Rect(middle - 200 - padding, 400, 200, 50), "Mesh Collision") == true)
  {
    Application::loadLevel("collision");
  }

  if(Gui::button(Rect(middle - 200 - padding, 500, 200, 50), "Post-processing") == true)
  {
    Application::loadLevel("post");
  }

  if(Gui::button(Rect(middle + padding, 200, 200, 50), "Bloom Shader") == true)
  {
    Application::loadLevel("bloom");
  }

  if(Gui::button(Rect(middle + padding, 300, 200, 50), "Camera Layers") == true)
  {
    Application::loadLevel("layer");
  }

  if(Gui::button(Rect(middle + padding, 400, 200, 50), "Lightsaber!") == true)
  {
    Application::loadLevel("accum");
  }

  if(Gui::button(Rect(middle + padding, 500, 200, 50), "Water Shader") == true)
  {
    Application::loadLevel("water");
  }
}

