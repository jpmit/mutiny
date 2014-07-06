#include "GameCamera.h"

#include <iostream>
#include <iomanip>

GameObject* GameCamera::create()
{
  GameObject* mainGo = new GameObject("GameCamera");
  GameCamera* gameCamera = mainGo->addComponent<GameCamera>();

  return mainGo;
}

void GameCamera::onAwake()
{
  // the actual camera!
  camera = getGameObject()->addComponent<Camera>();
  getGameObject()->getTransform()->setPosition(Vector3(0, 0, -10));
  getGameObject()->getTransform()->setRotation(Vector3(0.1, 0.1, 0));
}

void GameCamera::setActive()
{
  if (active == true)
  {
    Input::hideMouseCursor();
    Input::grabInput(true);
  }
  else
  {
    Input::showMouseCursor();
    Input::grabInput(false);
  }
}

void GameCamera::onStart()
{
  timeActive = false;
  totTime = 0.0f;
  active = true;
  setActive();
}

void GameCamera::onUpdate()
{
  // The first (two?) MOUSEMOTION events from SDL can be large, so we
  // have a timeout here so that we don't capture these.
  if (timeActive == false)
  {
    totTime += Time::getDeltaTime();
    if (totTime > 0.1)
    {
      timeActive = true;
    }
    return;
  }
  
  if (active == true)
  {
    if (Input::getKey(KeyCode::ESC) == true)
    {
      active = false;
      setActive();
    }
  }
  else
  {
    if (Input::getMouseButtonDown(0) == true)
    {
      active = true;
      setActive();
    }
    else
    {
      return;
    }
  }

  Transform* t = getGameObject()->getTransform();

  Vector3 mouseDelta = Input::getMouseDelta();
  t->rotate(Vector3(mouseDelta.y, mouseDelta.x, 0) * 10 * Time::getDeltaTime());
  Vector3 rot = t->getRotation();

  if (rot.x < -90)
  {
    t->setRotation(Vector3(-90, rot.y, rot.z));
  }
  else if (rot.x > 90)
  {
    t->setRotation(Vector3(90, rot.y, rot.z));    
  }
  
  Vector3 mov(0, 0, 0);
  
  if (Input::getKey(KeyCode::D) == true)
  {
    mov = mov + t->getRight() * 10 * Time::getDeltaTime();
  }
  if (Input::getKey(KeyCode::A) == true)
  {
    mov = mov + t->getRight() * -10 * Time::getDeltaTime();
  }
  if (Input::getKey(KeyCode::W) == true)
  {
    mov = mov + t->getForward() * 10 * Time::getDeltaTime();    
  }
  if (Input::getKey(KeyCode::S) == true)
  {
    mov = mov + t->getForward() * -10 * Time::getDeltaTime();
  }
  t->setPosition(t->getPosition() + Vector3(mov.x, 0, mov.z));
  
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

