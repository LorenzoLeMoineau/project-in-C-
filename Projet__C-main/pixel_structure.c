//
// Created by loren on 15/05/2023.
//
#include "pixel_structure.h"
#include "stdlib.h"
#include "stdio.h"

Pixel* create_pixel(int px, int py){
    Pixel*pix=(Pixel*)malloc(sizeof(Pixel));
    pix->px=px;
    pix->py=py;
    return pix;
}
void delete_pixel(Pixel* pixel){
    free(pixel);
}

void pixel_point(Point* point, Pixel** pixel, int* nb_pixels){

}