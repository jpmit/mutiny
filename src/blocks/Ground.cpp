#include "Ground.h"

#include <iostream>

using namespace mutiny::engine;

GameObject* Ground::create()
{
  GameObject* mainGo = new GameObject("Ground");
  mainGo->addComponent<Ground>();

  return mainGo;
}

void Ground::onAwake()
{
  MeshRenderer* mr = getGameObject()->addComponent<MeshRenderer>();
  MeshFilter* mf = getGameObject()->addComponent<MeshFilter>();
  //Mesh* mesh = Resources::load<Mesh>("models/ground/ground");
  Mesh* mesh = Resources::load<Mesh>("models/sheet");  
  Texture2d* tex = Resources::load<Texture2d>("models/ground/ground");
  Material* material = new Material(Resources::load<Material>("shaders/Internal-MeshRendererTexture"));
  material->setMainTexture(tex);

  mr->setMaterial(material);
  mf->setMesh(mesh);

  MeshCollider* meshCollider = getGameObject()->addComponent<MeshCollider>();

//  getGameObject()->getTransform()->setPosition(Vector3(0, -1, 25));
}

void Ground::onUpdate()
{
}
