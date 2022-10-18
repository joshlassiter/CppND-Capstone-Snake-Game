#ifndef FOOD_H
#define FOOD_H

#include <random>
#include "SDL.h"

enum class foodType{regular, bonus};
class Food{
public:
int x, y;

foodType type;

Food(int X, int Y, foodType Type){
    x = X;
    y = Y;
    type = Type;
}
~Food(){}
private:


};

#endif