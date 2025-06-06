#include "SHAPE.h"
#include "shapes.h"
#include <stdio.h>
#include <stdlib.h>


Shape *create_empty_shape(SHAPE_TYPE shape_type)
{
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL;
    shp->id = 1; // plus tard on appelera get_next_id();
    shp->shape_type = shape_type;
    return shp;
}
Shape *create_point_shape(int px, int py)
{
    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    return shp;
}
Shape *create_line_shape(int px1, int py1, int px2, int py2){
    Shape *shp = create_empty_shape(LINE);
    Point *p1 = create_point(px1, py1);
    Point *p2 = create_point(px2, py2);
    Line *line = create_line(p1, p2);
    shp->ptrShape = line;
    return shp;
}
Shape *create_square_shape(int px, int py, int length){
    Shape *shp = create_empty_shape(SQUARE);
    Point *p = create_point(px,py);
    Square *square = create_square(p,length);
    shp->ptrShape = square;
    return shp;
}
Shape *create_rectangle_shape(int px, int py, int width, int height){
    Shape *shp = create_empty_shape(RECTANGLE);
    Point *p = create_point(px, py);
    Rectangle *rectangle = create_rectangle(p, width, height);
    shp->ptrShape = rectangle;
    return shp;
}
Shape *create_circle_shape(int px, int py, int radius){
    Shape *shp = create_empty_shape(CIRCLE);
    Point *p = create_point(px,py);
    Circle *circle = create_circle(p, radius);
    shp->ptrShape = circle;
    return shp;
}
Shape *create_polygon_shape(int lst[], int n){
    if(n%2 == 1){
        printf("Your number of points needs to be a multiple of two.");
    }
    Shape *shp = create_empty_shape(POLYGON);
    Polygon *polygon = create_polygon(n);
    shp->ptrShape = polygon;
    return shp;
}
void delete_shape(Shape * shape){
    if(shape){
        if (shape->ptrShape){
            free(shape->ptrShape);
        }
        free(shape);
    }
}
void print_shape(Shape * shape){
    printf("ID : %d",shape->id);
    if (shape -> ptrShape == POINT) {
        print_point(shape->ptrShape);
    }
    else if (shape -> ptrShape == LINE){
        print_line(shape->ptrShape);
    }
    else if (shape -> ptrShape == CIRCLE){
        print_circle(shape->ptrShape);
    }
    else if (shape -> ptrShape == SQUARE){
        print_square(shape->ptrShape);
    }
    else if (shape -> ptrShape == RECTANGLE){
        print_rectangle(shape->ptrShape);
    }
    else if (shape -> ptrShape == POLYGON){
        print_polygon(shape->ptrShape);
    }
}//
// Created by loren on 23/05/2023.
//

#include "shapes.h"
