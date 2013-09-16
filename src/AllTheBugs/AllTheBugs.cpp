#include "../../include/AllTheBugs/AllTheBugs.h"

AllTheBugs::AllTheBugs() {
  Running = true;
}
 
int AllTheBugs::OnExecute() {
  if(OnSetup() == false) {
    return -1;
  }
 
  SDL_Event Event;
 
  while(Running) {
    while(SDL_PollEvent(&Event)) {
      OnEvent(&Event);
    }
 
    OnLoop();
    OnRender();
  }
 
  OnCleanup();
 
  return 0;
}


int main(int argc, char* argv[]) {
  AllTheBugs theApp;

  return theApp.OnExecute();
}
