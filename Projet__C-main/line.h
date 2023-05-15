//
// Created by Amandine Baranger on 21/04/2023.
//

#ifndef PROJET_C_LINE_H
#define PROJET_C_LINE_H

#include "point.h"

typedef struct line {
    Point *p1;
    Point *p2;
}Line;

Line *create_line(Point * p1, Point * p2);
void delete_line(Line * line);
void print_line(Line * line);
#endif //PROJET_C_LINE_H
