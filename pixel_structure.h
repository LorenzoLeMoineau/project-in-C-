//
// Created by loren on 15/05/2023.
//

#ifndef PROJET_C_PIXEL_STRUCTURE_H
#define PROJET_C_PIXEL_STRUCTURE_H
#include "shapes.h"
#include "SHAPE.h"
struct pixel {
    int px;
    int py;
};
typedef struct pixel Pixel;
Pixel* create_pixel(int px, int py);
void delete_pixel(Pixel* pixel);
void pixel_point(Shape* shape, Pixel** pixel, int* nb_pixels);
void pixel_line(Line* line, Pixel** pixel, int* nb_pixels);
void pixel_circle(Circle* circle, Pixel** pixel, int* nb_pixels);
void pixel_rectangle(Rectangle* rectangle, Pixel** pixel, int* nb_pixels);
void pixel_square(Square* square, Pixel** pixel, int* nb_pixels);
void pixel_polygon(Polygon * polygon, Pixel** pixel, int* nb_pixels);
Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels);
void delete_pixel_shape(Pixel** pixel, int nb_pixels);

#endif //PROJET_C_PIXEL_STRUCTURE_H
