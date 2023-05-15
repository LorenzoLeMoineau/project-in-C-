//
// Created by loren on 15/05/2023.
//
#include "pixel_structure.h"
#include "stdlib.h"
#include "stdio.h"
#include "shapes.h"
#include "line.h"

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

void pixel_line(Line* line, Pixel** pixel, int* nb_pixels){
    int x1,x2,y1,y2,dx,dy,dmin,dmax,nb_segs,base_seg_size;
    x1=line->p1->pos_x;
    y1=line->p1->pos_y;
    x2=line->p2->pos_x;
    x2=line->p2->pos_y;
    dx=x2-x1;
    dy=y2-y1;
    dmin= (dx<dy) ? dx:dy;
    dmax= (dx<dy) ? dy:dx;
    nb_segs=dmin+1;
    base_seg_size=(dmax+1)/(dmin+1);

}
