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

  //adding Food object for the second food
  Food food2;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  //uniform disrtribution for food type
  //std::uniform_int_distribution<std::mt19937::result_type> randType(0,6);
  
  int score{0};

  void PlaceFood();

  // second function to place second food
  void PlaceFood2();
  void Update();
};

#endif