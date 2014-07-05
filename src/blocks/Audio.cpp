#include "Audio.h"

#include <mutiny/mutiny.h>
#include <SDL/SDL.h>

#include <iostream>

using namespace mutiny::engine;

std::vector<AudioClip*> Audio::sounds;
Mix_Music* Audio::music = NULL;
Mix_Music* Audio::musicA = NULL;
Mix_Music* Audio::breathing = NULL;

void Audio::initialize()
{
  // add some audio later!
}

void Audio::addSound(std::string path)
{
  AudioClip* clip = Resources::load<AudioClip>(path);

  if(clip == NULL)
  {
    throw std::exception();
  }

  sounds.push_back(clip);
}

void Audio::playSound(int sound)
{
  AudioSource::playClipAtPoint(sounds[sound], Vector3());
}

void Audio::playMusic()
{
  Mix_PlayMusic(music, -1);
}

void Audio::playMusicA()
{
  Mix_PlayMusic(musicA, -1);
}

void Audio::playBreathing()
{
  Mix_PlayMusic(breathing, -1);
}

void Audio::stopMusic()
{
  Mix_HaltMusic();
}
