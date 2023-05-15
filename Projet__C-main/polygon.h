//
// Created by Amandine Baranger on 21/04/2023.
//

#ifndef PROJET_C_POLYGON_H
#define PROJET_C_POLYGON_H

#include "point.h"

typedef struct polygon {
    int n;
    Point ** points; // tableau 1D dynamique de Point*
}Polygon;

Polygon *create_polygon(int n);
void delete_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);
#endif //PROJET_C_POLYGON_H
