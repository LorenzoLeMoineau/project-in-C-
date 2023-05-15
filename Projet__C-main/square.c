#include <stdlib.h>
#include <printf.h>
#include "square.h"
#include "point.h"

//
// Created by Amandine Baranger on 21/04/2023.
//
Square *create_square(Point * point, int length){
    Square *sqr = (Square*)malloc(sizeof(Square));
    sqr->corner = point;
    sqr->length = length;
    return sqr;

}
void delete_square(Square * square){
    free(square);
}
void print_square(Square * square){
    printf("SQUARE: %d %d %d", square->corner->pos_x, square->corner->pos_y,square->length);

}