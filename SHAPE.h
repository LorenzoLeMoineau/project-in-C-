//
// Created by loren on 23/05/2023.
//

#ifndef PROJET_C_SHAPE_H
#define PROJET_C_SHAPE_H
//============================================POINT=======================
typedef struct {
    int pos_x;
    int pos_y;
}Point;

Point *create_point(int px, int py);
void delete_point(Point * point);
void print_point(Point * p);
//==========================================LINE=========================
typedef struct line {
    Point *p1;
    Point *p2;
}Line;

Line *create_line(Point * p1, Point * p2);
void delete_line(Line * line);
void print_line(Line * line);
//==================================SQUARE===============================
typedef struct{
    int length;
    Point *corner;
}Square;

Square *create_square(Point * point, int length);
void delete_square(Square * square);
void print_square(Square * square);
//==================================RECTANGLE============================

typedef struct{
    int length;
    int width;
    Point *corner;
}Rectangle;

Rectangle *create_rectangle(Point * point, int width, int height);
void delete_rectangle(Rectangle * rectangle);
void print_rectangle(Rectangle * rectangle);
//==================================CIRCLE===============================
typedef struct {
    int radius;
    Point*center;
}Circle;

Circle *create_circle(Point * center, int radius);
void delete_circle(Circle * circle);
void print_circle(Circle * circle);
//==================================POLYGON==============================
typedef struct polygon {
    int n;
    Point ** points; // tableau 1D dynamique de Point*
}Polygon;

Polygon *create_polygon(int n);
void delete_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);
#endif //PROJET_C_SHAPE_H

