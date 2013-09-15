#include "AllTheBugs.h"

AllTheBugs::AllTheBugs() {
}

int AllTheBugs::OnExecute() {
  return 0;
}

AllTheBugs::AllTheBugs() {
  Running = true;
}
 
int AllTheBugs::OnExecute() {
  if(OnInit() == false) {
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
