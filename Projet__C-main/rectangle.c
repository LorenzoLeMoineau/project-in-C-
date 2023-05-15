#include <stdlib.h>
#include <printf.h>
#include "rectangle.h"

//
// Created by Amandine Baranger on 21/04/2023.
//
Rectangle *create_rectangle(Point * point, int width, int length){
    Rectangle *rct = (Rectangle*)malloc(sizeof(Rectangle));
    rct->corner = point;
    rct->length = length;
    rct->width = width;
    return rct;
}
void delete_rectangle(Rectangle * rectangle){
    free(rectangle);
}
void print_rectangle(Rectangle * rectangle){
    printf("RECTANGLE : %d %d %d %d", rectangle->corner->pos_x, rectangle->corner->pos_y, rectangle->length, rectangle->width);
}