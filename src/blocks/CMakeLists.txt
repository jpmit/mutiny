add_executable(blocks
  Audio.cpp
  Block.cpp
  GameCamera.cpp
  GameScreen.cpp
  Ground.cpp
  Player.cpp
  main.cpp
  SceneManager.cpp
  World.cpp
)

target_link_libraries(blocks mutiny)
