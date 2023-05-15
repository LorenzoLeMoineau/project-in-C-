#include <stdlib.h>
#include <printf.h>
#include "point.h"

//
// Created by Amandine Baranger on 21/04/2023.
//
Point *create_point(int px, int py){
    Point *pt = (Point*)malloc(sizeof(Point));
    pt->pos_x = px;
    pt->pos_y = py;
    return pt;
}
void delete_point(Point * point){
    free(point);
}
void print_point(Point * p){
    printf("POINT %d %d",p->pos_x,p->pos_y);
}