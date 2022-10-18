#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "food.h"
#include <cstdlib>

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  Food food;

  //adding SDL point for the second food
  Food food2;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  //uniform disrtribution for food type
  //std::uniform_int_distribution<std::mt19937::result_type> randType(0,6);
  
  int score{0};

  void PlaceFood();
  void Update();
};

#endif