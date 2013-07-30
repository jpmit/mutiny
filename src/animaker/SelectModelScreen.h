#ifndef SELECTMODELSCREEN_H
#define SELECTMODELSCREEN_H

#include <mutiny/mutiny.h>

#include <string>
#include <vector>

using namespace mutiny::engine;

class SelectModelScreen : public Behaviour
{
public:
  static std::string choice;

  virtual void onAwake();
  virtual void onUpdate();
  virtual void onGui();

private:
  Font* titleFont;
  std::vector<std::string> files;

  void scanDir(std::string directory, std::vector<std::string>* files);

};

#endif

