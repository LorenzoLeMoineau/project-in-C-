//
// Created by Amandine Baranger on 21/04/2023.
//

#ifndef PROJET_C_CIRCLE_H
#define PROJET_C_CIRCLE_H

#include "point.h"

typedef struct {
    int radius;
    Point*center;
}Circle;

Circle *create_circle(Point * center, int radius);
void delete_circle(Circle * circle);
void print_circle(Circle * circle);
#endif //PROJET_C_CIRCLE_H
