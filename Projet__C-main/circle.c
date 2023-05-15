#include <stdlib.h>
#include <printf.h>
#include "circle.h"

//
// Created by Amandine Baranger on 21/04/2023.
//
Circle *create_circle(Point * center, int radius){
    Circle *crl = (Circle*)malloc(sizeof(Circle));
    crl->center = center;
    crl->radius = radius;
    return crl;
}
void delete_circle(Circle * circle){
    free(circle);
}
void print_circle(Circle * circle){
    printf("CIRCLE : %d %d %d",circle->center->pos_x, circle->center->pos_y,circle->radius);
}