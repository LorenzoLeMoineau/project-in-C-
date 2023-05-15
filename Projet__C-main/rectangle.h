//
// Created by Amandine Baranger on 21/04/2023.
//

#ifndef PROJET_C_RECTANGLE_H
#define PROJET_C_RECTANGLE_H

#include "point.h"

typedef struct{
    int length;
    int width;
    Point *corner;
}Rectangle;

Rectangle *create_rectangle(Point * point, int width, int height);
void delete_rectangle(Rectangle * rectangle);
void print_rectangle(Rectangle * rectangle);
#endif //PROJET_C_RECTANGLE_H
