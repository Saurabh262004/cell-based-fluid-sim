#include <stdio.h>
#include <SDL2/SDL.h>
#include "../include/basic/vector.h"
#include "../include/basic/matrix.h"

#define INIT_WIDTH 1280
#define INIT_HEIGHT 720

Vec2F v1 = {10.0, 10.0};
Vec2F v2 = {1.0, 1.0};

Vec2I mousePose = {0, 0};
Vec2I windowSize = {0, 0};

VecNI *sq = NULL;

int running = 1;

void drawLoop(SDL_Window *window, SDL_Renderer *renderer) {
  SDL_GetMouseState(&mousePose.x, &mousePose.y);
  SDL_GetWindowSizeInPixels(window, &windowSize.x, &windowSize.y);

  // clear the screen
  SDL_SetRenderDrawColor(renderer, 128, 32, 160, 255);
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  SDL_Rect rect = {sq->comp[0], sq->comp[1], sq->comp[2], sq->comp[3]};
  SDL_RenderDrawRect(renderer, &rect);

  SDL_RenderDrawLine(renderer, mousePose.x, mousePose.y, windowSize.x, windowSize.y);
}

void handleEvent(SDL_Event event) {
  if (event.type == SDL_QUIT) {
    running = 0;
  }
}

int setupLoop(int delay, SDL_Window *window) {
  SDL_Renderer *renderer = SDL_CreateRenderer(
    window,
    -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
  );
  
  if (!renderer) {
    printf("SDL_CreateRederer: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 3;
  }
  
  SDL_Event event;

  while (running) {
    while (SDL_PollEvent(&event)) {
      handleEvent(event);
    }

    drawLoop(window, renderer);

    SDL_RenderPresent(renderer);

    SDL_Delay(delay);
  }

  return 0;
}

int main() {
  const int sdl_init_status = SDL_Init(SDL_INIT_VIDEO);

  if (sdl_init_status != 0) {
    printf("SDL_Init failed: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Window *window = SDL_CreateWindow(
    "test",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    INIT_WIDTH, INIT_HEIGHT,
    SDL_WINDOW_SHOWN
  );

  if (!window) {
    printf("SDL_CreateWindow failed: %s\n", SDL_GetError());
    return 2;
  }

  sq = vecNI_create(4);

  sq->comp[0] = 0;
  sq->comp[1] = 0;
  sq->comp[2] = 100;
  sq->comp[3] = 100;

  int mainLoopStatus = setupLoop(16, window);

  if (mainLoopStatus != 0) return mainLoopStatus;

  free(sq);

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
