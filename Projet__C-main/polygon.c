#include "polygon.h"
#include "point.h"
#include <stdio.h>
#include <stdlib.h>
//
// Created by Amandine Baranger on 21/04/2023.
//
Polygon *create_polygon(int n){
    Polygon *plg = (Polygon*) malloc(sizeof(Polygon));
    plg->n=n;
    plg->points = (Point**)malloc(sizeof(Point*));
    for(int i=0; i<n; i++){
        plg->points[i]= create_point(i,n);
    }
    return plg;
}
void delete_polygon(Polygon * polygon){
    for(int i=0; i< polygon->n; i++){
        delete_point(polygon->points[i]);
    }
    free(polygon->points);
    free(polygon);
}
void print_polygon(Polygon * polygon){
    printf("POLYGON with %d points : \n",polygon->n);
    for(int i=0; i< polygon->n; i++){
        printf("POINT %d : ", i+1);
        print_point(polygon->points[i]);
    }
}