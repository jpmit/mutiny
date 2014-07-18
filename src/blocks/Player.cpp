#include "Player.h"

#include <iostream>
#include <iomanip>

GameObject* Player::create(GameObject* world)
{
  GameObject* mainGo = new GameObject("Player");
  Player* player = mainGo->addComponent<Player>();
  player->worldGo = world;
  return mainGo;
}

void Player::onAwake()
{
  getGameObject()->getTransform()->setPosition(Vector3(0, 0, -10));
  getGameObject()->getTransform()->setRotation(Vector3(0, Player::minHeight, 0));
}

void Player::setActive()
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

void Player::onStart()
{
  timeActive = false;
  totTime = 0.0f;
  active = true;
  setActive();
  jumping = false;
  falling = false;
}

void Player::onUpdate()
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

  // Allow the player to suspend movement by pressing escape, and
  // start moving again by clicking the screen.
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

  // Handle input that moves the player
  processMovement();

  // Get the block that intersects with my line of sight
  Transform* t = getGameObject()->getTransform();
  Vector3 forward = t->getForward();
  
}

void Player::processMovement()
{
  Transform* t = getGameObject()->getTransform();
  Vector3 mouseDelta = Input::getMouseDelta();
  t->rotate(Vector3(mouseDelta.y, mouseDelta.x, 0) * 10 * Time::getDeltaTime());
  Vector3 rot = t->getRotation();
  Vector3 pos = t->getPosition();

  if (rot.x < -90)
  {
    t->setRotation(Vector3(-90, rot.y, rot.z));
  }
  else if (rot.x > 90)
  {
    t->setRotation(Vector3(90, rot.y, rot.z));    
  }
  
  Vector3 mov(0, 0, 0);
  float dt = Time::getDeltaTime();
  
  if (Input::getKey(KeyCode::D) == true)
  {
    mov = mov + t->getRight() * 10 * dt;
  }
  if (Input::getKey(KeyCode::A) == true)
  {
    mov = mov + t->getRight() * -10 * dt;
  }
  if (Input::getKey(KeyCode::W) == true)
  {
    mov = mov + t->getForward() * 10 * dt;    
  }
  if (Input::getKey(KeyCode::S) == true)
  {
    mov = mov + t->getForward() * -10 * dt;
  }

  // jumping
  float y = pos.y;
  if (jumping == true)
  {
    y += 10 * dt;
    if (y > Player::maxHeight)
    {
      y = Player::maxHeight;
      jumping = false;
      falling = true;
    }
  }

  if (Input::getKey(KeyCode::SPACE) == true and falling == false)
  {
    jumping = true;
    falling = false;
  }
  else
  {
    jumping = false;
    falling = true;
  }

  if (falling == true)
  {
    y = pos.y - 10 * dt;
    if (y < Player::minHeight)
    {
      y = Player::minHeight;
      falling = false;
    }
  }
  
  t->setPosition(Vector3(pos.x + mov.x, y, pos.z + mov.z));
}
