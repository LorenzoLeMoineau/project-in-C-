//
// Created by loren on 23/05/2023.
//
#include "SHAPE.h"
#include <stdlib.h>
#include <stdio.h>
//------------------------------------------------------POINT---------------
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
//-------------------------------------------------------LINE------------
Line *create_line(Point * p1, Point * p2){
    Line *l = (Line*)malloc(sizeof(Line));
    l->p1 = p1;
    l->p2 = p2;
    return l;
}
void delete_line(Line * line){
    free(line);
}
void print_line(Line * line){

    printf("LINE %d %d %d %d", line->p1->pos_x,line->p1->pos_y,line->p2->pos_x,line->p2->pos_y);
}
//--------------------------------------------------SQUARE------------
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
//---------------------------------RECTANGLE----------------------
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
//-------------------------------CIRCLE------------------------------------
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
//-------------------------------------------------------POLYGON---------
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
}//
// Created by loren on 23/05/2023.
//
