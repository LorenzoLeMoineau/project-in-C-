//
// Created by loren on 15/05/2023.
//
#include "pixel_structure.h"
#include "stdlib.h"
#include "stdio.h"
#include "shapes.h"
#include "SHAPE.h"

Pixel* create_pixel(int px, int py){
    Pixel*pix=(Pixel*)malloc(sizeof(Pixel));
    pix->px=px;
    pix->py=py;
    return pix;
}
void delete_pixel(Pixel* pixel){
    free(pixel);
}

void pixel_point(Shape* shape, Pixel** pixel, int* nb_pixels){
    Point* pt = (Point*) shape->ptrShape;
    pixel= (Pixel**) malloc (sizeof (Pixel*));
    pixel[0] = create_pixel(pt->pos_x, pt->pos_y);
    *nb_pixels = 1;
}
//algorithm of Nicolas Flasque
void pixel_line(Line* line, Pixel** pixel, int* nb_pixels){
    int x1,x2,y1,y2,dx,dy,dmin,dmax,nb_segs,base_seg_size,remaining_segs;
    x1=line->p1->pos_x;
    y1=line->p1->pos_y;
    x2=line->p2->pos_x;
    x2=line->p2->pos_y;
    dx=x2-x1;
    dy=y2-y1;
    dmin= (dx<abs(dy)) ? dx:dy;
    dmax= (dx<abs(dy)) ? dy:dx;
    nb_segs=dmin+1;
    base_seg_size=(dmax+1)/(dmin+1);
    remaining_segs=(dmax+1)%(dmin+1);
    int* segments=(int*)calloc(nb_segs,sizeof(int));
    for(int i = 0; i<nb_segs; i++) {
        segments[i] = base_seg_size;
    }
    int *cumuls = (int *)malloc(nb_segs*sizeof(int));
    for (int i = 1; i < nb_segs;i++)
    {
        cumuls[i] = ((i*remaining_segs)%(dmin+1) < (i-1)*remaining_segs)%(dmin+1);
        segments[i] = segments[i]+cumuls[i];
    }
    if(dy<0){
        if(abs(dx)>abs(dy)){
            if(dx>0){
                printf("1__");
                int add = 0;
                for(int i = 0; i<nb_segs; i++){
                    for(int j = 0; j<segments[i]; j++){
                        pixel[*nb_pixels] = create_pixel(line->p2->pos_x-add-j,line->p2->pos_y+i);
                        printf("\nx: %d||y: %d\n", pixel[*nb_pixels]->px, pixel[*nb_pixels]->py );
                        (*nb_pixels)++;
                    }
                    add += segments[i];
                }
            }
            else{
                printf("2__");
                int add = 0;
                for(int i = 0; i<nb_segs; i++){
                    for(int j = 0; j<segments[i]; j++){
                        pixel[*nb_pixels] = create_pixel(line->p2->pos_x+add+j,line->p2->pos_y+i);
                        (*nb_pixels)++;
                    }
                    add += segments[i];
                }
            }
        }
        else{
            if(dx>0){
                printf("3__");
                int add = 0;
                for(int i = 0; i<nb_segs; i++){
                    for(int j = 0; j<segments[i]; j++){
                        pixel[*nb_pixels] = create_pixel(line->p2->pos_x-i,line->p2->pos_y+add+j);
                        (*nb_pixels)++;
                    }
                    add += segments[i];
                }
            }
            else{
                printf("4__");
                int add = 0;
                for(int i = 0; i<nb_segs; i++){
                    for(int j = 0; j<segments[i]; j++){
                        pixel[*nb_pixels] = create_pixel(line->p2->pos_x+i,line->p2->pos_y+add+j);
                        (*nb_pixels)++;
                    }
                    add += segments[i];
                }
            }
        }
    }
    else{
        if(abs(dx)>abs(dy)){
            if(dx>0){
                printf("5__");
                int add = 0;
                for(int i = 0; i<nb_segs; i++){
                    for(int j = 0; j<segments[i]; j++){
                        pixel[*nb_pixels] = create_pixel(line->p1->pos_x+add+j,line->p1->pos_y+i);
                        (*nb_pixels)++;
                    }
                    add += segments[i];
                }
            }
            else{
                printf("6__");
                int add = 0;
                for(int i = 0; i<nb_segs; i++){
                    for(int j = 0; j<segments[i]; j++){
                        pixel[*nb_pixels] = create_pixel(line->p1->pos_x-add-j,line->p1->pos_y+i);
                        (*nb_pixels)++;
                    }
                    add += segments[i];
                }
            }
        }
        else{
            if(dx>0){
                printf("7__");
                int add = 0;
                for(int i = 0; i<nb_segs; i++){
                    for(int j = 0; j<segments[i]; j++){
                        pixel[*nb_pixels] = create_pixel(line->p1->pos_x+i,line->p1->pos_y+add+j);
                        (*nb_pixels)++;
                    }
                    add += segments[i];
                }
            }
            else{
                printf("8__");
                int add = 0;
                for(int i = 0; i<nb_segs; i++){
                    for(int j = 0; j<segments[i]; j++){
                        pixel[*nb_pixels] = create_pixel(line->p1->pos_x-i,line->p1->pos_y+add+j);
                        (*nb_pixels)++;
                    }
                    add += segments[i];
                }
            }
        }
    }
    free(cumuls);
    free(segments);
}

void pixel_circle(Circle * circle, Pixel** pixel_arr, int* k) {
    int x = 0;
    int y = circle->radius;
    int d = circle->radius - 1;

    while (y >= x) {
        // Add the point for the first octant
        Pixel* px = create_pixel(circle->center->pos_x + x, circle->center->pos_y + y);
        pixel_arr[(*k)++] = px;

        // Add the point for the octant opposite
        px = create_pixel(circle->center->pos_x + y, circle->center->pos_y + x);
        pixel_arr[(*k)++] = px;

        // Add the same for the remaining six octants
        // ...

        if (d >= 2 * x) {
            d -= 2 * x + 1;
            x++;
        } else if (d < 2 * (circle->radius - y)) {
            d += 2 * y - 1;
            y--;
        } else {
            d += 2 * (y - x - 1);
            y--;
            x++;
        }
    }
}

void pixel_square(Square * square, Pixel** pixel_arr, int* nb_pixels) {
    int lenght = square->length;
    int x = square->corner->pos_x;
    int y = square->corner->pos_y;

    pixel_arr[*nb_pixels] = create_pixel(x, y);
    (*nb_pixels)++;

    for(int i = 0; i<lenght-1; i++){
        pixel_arr[*nb_pixels] = create_pixel(x+i+1, y);
        (*nb_pixels)++;
        pixel_arr[*nb_pixels] = create_pixel(x+i+1, y+lenght-1);
        (*nb_pixels)++;
        pixel_arr[*nb_pixels] = create_pixel(x, y+i+1);
        (*nb_pixels)++;
        pixel_arr[*nb_pixels] = create_pixel(x+lenght-1, y+i+1);
        (*nb_pixels)++;
    }
    (*nb_pixels)--;
}

void pixel_rectangle(Rectangle * rectangle, Pixel** pixel_arr, int* nb_pixels){
    int lenght = rectangle->length;
    int width = rectangle->width;
    int x = rectangle->corner->pos_x;
    int y = rectangle->corner->pos_y;

    pixel_arr[*nb_pixels] = create_pixel(x, y);
    (*nb_pixels)++;

    for(int i = 0; i<lenght-1; i++){
        pixel_arr[*nb_pixels] = create_pixel(x+i+1, y);
        (*nb_pixels)++;
        pixel_arr[*nb_pixels] = create_pixel(x+i+1, y+width-1);
        (*nb_pixels)++;

    }
    for(int i = 0; i<width-1; i++){
        pixel_arr[*nb_pixels] = create_pixel(x, y+i+1);
        (*nb_pixels)++;
        pixel_arr[*nb_pixels] = create_pixel(x+lenght-1, y+i+1);
        (*nb_pixels)++;
    }
    (*nb_pixels)--;
}

void pixel_polygon(Polygon * polygon, Pixel** pixel_arr, int* nb_pixels){
    int nb_point = polygon->n;
    for(int i = 0; i<nb_point-1; i++){
        Line *line = (Line*) malloc(sizeof(Line));
        line->p1 = (Point*) malloc(sizeof(Point));
        *line->p1 = (Point){polygon->points[i]->pos_x, polygon->points[i]->pos_y};
        line->p2 = (Point*) malloc(sizeof(Point));
        *line->p2 = (Point){polygon->points[i+1]->pos_x, polygon->points[i+1]->pos_y};
        pixel_line(line, pixel_arr, nb_pixels);
    }
}

Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels){
    *nb_pixels = 0;
    if (shape->shape_type==POINT){
        Point *point = (Point *) shape->ptrShape;
        Pixel** pixel_arr = (Pixel**) calloc(1, sizeof(Pixel*));
        pixel_point(point, pixel_arr, nb_pixels);
        return pixel_arr;
    }
    if (shape->shape_type==LINE){
        Line *line = (Line*) shape->ptrShape;
        int dx_ab = abs(line->p2->pos_x - line->p1->pos_x);
        int dy_ab = abs(line->p2->pos_y - line->p1->pos_y);
        Pixel** pixel_arr = (Pixel**)calloc((dx_ab+1)*(dy_ab+1), sizeof(Pixel*));
        pixel_line(line, pixel_arr, nb_pixels);
        pixel_arr = (Pixel**) realloc(pixel_arr, *nb_pixels*sizeof(Pixel*));
        return pixel_arr;
    }
    if (shape->shape_type==SQUARE){
        Square *square = (Square *) shape->ptrShape;
        int size = square->length*square->length;
        Pixel** pixel_arr = (Pixel**)calloc(size, sizeof(Pixel*));
        pixel_square(square, pixel_arr, nb_pixels);
        pixel_arr = (Pixel**) realloc(pixel_arr, *nb_pixels*sizeof(Pixel*));
        return pixel_arr;
    }
    if (shape->shape_type==RECTANGLE){
        Rectangle *rectangle = (Rectangle *) shape->ptrShape;
        int size = rectangle->length*rectangle->width;
        Pixel** pixel_arr = (Pixel**)calloc(size, sizeof(Pixel*));
        pixel_rectangle(rectangle, pixel_arr, nb_pixels);
        pixel_arr = (Pixel**) realloc(pixel_arr, *nb_pixels*sizeof(Pixel*));
        return pixel_arr;
    }
    if (shape->shape_type==CIRCLE){
        Circle *circle = (Circle *) shape->ptrShape;
        int size = (circle->radius+1)*(circle->radius+1);
        Pixel **pixel_arr = (Pixel**)calloc(size, sizeof(Pixel*));
        pixel_circle(circle, pixel_arr, nb_pixels);
        pixel_arr = (Pixel**) realloc(pixel_arr, *nb_pixels*sizeof(Pixel*));
        return pixel_arr;
    }
    if (shape->shape_type==POLYGON){
        Polygon *polygon = (Polygon *) shape->ptrShape;
        int nb_point = polygon->n;
        int size = 0;
        for(int i = 0; i<nb_point-1; i++){
            int dx_ab = abs(polygon->points[i+1]->pos_x - polygon->points[i]->pos_x);
            int dy_ab = abs(polygon->points[i+1]->pos_y - polygon->points[i]->pos_y);
            size += (dx_ab+1)*(dy_ab+1);
        }
        printf("\nsize : %d\n", size);
        Pixel** pixel_arr = (Pixel**)calloc(size, sizeof(Pixel*));
        pixel_polygon(polygon, pixel_arr, nb_pixels);
        pixel_arr = (Pixel**) realloc(pixel_arr, *nb_pixels*sizeof(Pixel*));
        return pixel_arr;
    }
    return NULL;
}

void delete_pixel_shape(Pixel** pixel, int nb_pixels){
    free(pixel);
}
