#include "SceneManager.h"
#include "GameScreen.h"
#include "Audio.h"

using namespace mutiny::engine;

void SceneManager::onAwake()
{
  // the gameobject that holds a shared_ptr to this component (the
  // SceneManager object) should not be destroyed when we load a new
  // level.
  dontDestroyOnLoad(getGameObject());
  loadLevel();
}

void SceneManager::onLevelWasLoaded()
{
  loadLevel();
}

void SceneManager::loadLevel()
{
  Debug::log("Level loaded: " + Application::getLoadedLevelName());

  Audio::initialize();

  if(Application::getLoadedLevelName() == "game")
  {
    GameScreen::create();
  }
}

