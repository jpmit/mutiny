add_executable(blocks
  Audio.cpp
  Block.cpp
  GameCamera.cpp
  GameScreen.cpp
  Ground.cpp
  main.cpp
  SceneManager.cpp
)

target_link_libraries(blocks mutiny)
