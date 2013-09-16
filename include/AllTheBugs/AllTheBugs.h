#ifndef _ALLTHEBUGS_H_
    #define _ALLTHEBUGS_H_

#include <SDL.h>

class AllTheBugs {

 private:
  bool    Running;

 public:
  AllTheBugs();

  int OnExecute();

 public:
  bool OnSetup();

  void OnEvent(SDL_Event* Event);

  void OnLoop();

  void OnRender();

  void OnCleanup();

};

#endif
