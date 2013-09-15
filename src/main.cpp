#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char **argv){
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
    std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return 1;
  }
  SDL_Quit();

  SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
  if (win == nullptr){
    std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  SDL_Renderer *ren = SDL_CreateRenderer(win, -1, 
					 SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (ren == nullptr){
    std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  SDL_Surface *bmp = SDL_LoadBMP("../res/lessone/hello.bmp");
  if (bmp == nullptr){
    std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
  SDL_FreeSurface(bmp);
  if (tex == nullptr){
    std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
    return 1;
  }


  SDL_Event e;
  bool quit = false;
  while (!quit){
    while (SDL_PollEvent(&e)){
      if (e.type == SDL_QUIT)
	quit = true;
      if (e.type == SDL_KEYDOWN)
	quit = true;
      if (e.type == SDL_MOUSEBUTTONDOWN)
	quit = true;
    }
    //Render the scene
    SDL_RenderClear(ren);
    //   renderTexture(image, renderer, x, y);
    SDL_RenderCopy(ren, tex, NULL, NULL);
    SDL_RenderPresent(ren);
  }

  //  SDL_Delay(2000);

  SDL_DestroyTexture(tex);
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  SDL_Quit();

  return 0;
}
