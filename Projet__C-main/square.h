//
// Created by Amandine Baranger on 21/04/2023.
//

#ifndef PROJET_C_SQUARE_H
#define PROJET_C_SQUARE_H

#include "point.h"

typedef struct{
    int length;
    Point *corner;
}Square;

Square *create_square(Point * point, int length);
void delete_square(Square * square);
void print_square(Square * square);
#endif //PROJET_C_SQUARE_H
