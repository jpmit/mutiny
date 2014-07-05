#include "SceneManager.h"

#include <mutiny/mutiny.h>

#include <ctime>
#include <iostream>

using namespace mutiny::engine;

void safe_main(int argc, char* argv[])
{
  srand(time(NULL));
  Application::init(argc, argv);

  Application::loadLevel("game");

  GameObject* smGo = new GameObject();
  // when a component c is added to a gameobject, this calls
  // c.awake(), which goes to Behaviour::awake(), which calls the
  // onAwake() method (phew!)
  smGo->addComponent<SceneManager>();

  Application::run();

  Application::destroy();
}

int main(int argc, char* argv[])
{
    safe_main(argc, argv);

    return 0;
}

