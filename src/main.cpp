#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <fstream>
using namespace std;

int main() {
  string name;
  // asking user for thier name and storing it into a vairable
  cout << "Please enter your name: ";
  cin >> name;
  
  
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Congratulations " << name << "!!!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  
  // storing scores into a text document 
  std::ofstream outfile;
  outfile.open("Gamelog.txt", std::ios_base::app);
  outfile << name << ": " << game.GetScore() << "\n";
  return 0;
}