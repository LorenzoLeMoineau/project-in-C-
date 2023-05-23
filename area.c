#include "area.h"
#include "stdlib.h"
#include "SHAPE.h"
#include "stdio.h"
#include "pixel_structure.h"
#include <stdbool.h>

//
// Created by Amandine Baranger on 15/05/2023.
//
Area* create_area(unsigned int width, unsigned int height){
    Area* new_area = (Area*) malloc(sizeof(Area));
    new_area->height = height;
    new_area->width = width;
    new_area->nb_shape = 0;
    BOOL** B1 = (BOOL**)malloc(sizeof(BOOL*) * width);
    for (unsigned int i = 0; i < width; i++) {
        B1[i] = (BOOL*)malloc(sizeof(BOOL) * height);
    }
    new_area->mat = B1;
    return new_area;
    return new_area;
}

void add_shape_to_area(Area* area, Shape* shape){
    area->shapes[area->nb_shape]=shape;
    area->nb_shape++;
}
void clear_area(Area* area){
    int **matrix = malloc(area->height * sizeof(int *));
    for (int i = 0; i < area->height; i++) {
        matrix[i] = calloc(area->width, sizeof(int));
    }
    area->mat = matrix;
}
void erase_area(Area* area){
    for (int i = 0; i < area->nb_shape; i++) {
        free(area->mat[i]);
    }
    free(area->mat);

    for (int j =0; j < area->height; j++){
        free(area->mat[j]);
    }
    free(area->mat);
}
void delete_area(Area* area){
    erase_area(area);
    free(area);
}

int in_list(Pixel** p1, int nb_pixels, int x, int y){
    for (int n=0; n<nb_pixels ; n++){
        if ((p1[n]->px==x)&&(p1[n]->py==y)){
            return 1;
        }
    }
    return 0;
}
void draw_area(Area* area){
    clear_area(area);
    for (int i=0; i < area->nb_shape; i++){
        if (area->shapes[i]->shape_type==POINT){
            int nb_pixels;
            Pixel** p1 = create_shape_to_pixel(area->shapes[i], &nb_pixels);
            Point* p0 = area->shapes[i]->ptrShape;
            for (int j = 0; j < area->width; j++) {
                for (int k = 0; k < area->height; k++) {
                    if ((j==p0->pos_x)&&(k==p0->pos_y)){
                        area->mat[j][k]=1;
                    }
                }
            }
        } else if (area->shapes[i]->shape_type == LINE) {
            int nb_pixels;
            Pixel** p1 = create_shape_to_pixel(area->shapes[i], &nb_pixels);
            for (int j = 0; j < area->width; j++) {
                for (int k = 0; k < area->height; k++) {
                    if (in_list(p1, nb_pixels, j, k) == 1) {
                        area->mat[j][k] = 1;
                    }
                }
            }
        } else if (area->shapes[i]->shape_type==SQUARE){
            int nb_pixels;
            Pixel** p1 = create_shape_to_pixel(area->shapes[i], &nb_pixels);
            for (int j = 0; j < area->width; j++) {
                for (int k = 0; k < area->height; k++) {
                    if (in_list(p1, nb_pixels, j, k) == 1) {
                        area->mat[j][k] = 1;
                    }
                }
            }
        } else if (area->shapes[i]->shape_type==RECTANGLE){
            int nb_pixels;
            Pixel** p1 = create_shape_to_pixel(area->shapes[i], &nb_pixels);
            for (int j = 0; j < area->width; j++) {
                for (int k = 0; k < area->height; k++) {
                    if (in_list(p1, nb_pixels, j, k) == 1) {
                        area->mat[j][k] = 1;
                    }
                }
            }
        } else if (area->shapes[i]->shape_type == CIRCLE) {
            int nb_pixels;
            Pixel** p1 = create_shape_to_pixel(area->shapes[i], &nb_pixels);
            for (int j = 0; j < area->width; j++) {
                for (int k = 0; k < area->height; k++) {
                    if (in_list(p1, nb_pixels, j, k) == 1) {
                        area->mat[j][k] = 1;
                    }
                }
            }
        } else if (area->shapes[i]->shape_type == POLYGON) {
            int nb_pixels;
            Pixel **p1 = create_shape_to_pixel(area->shapes[i], &nb_pixels);

            for (int j = 0; j < area->width; j++) {
                for (int k = 0; k < area->height; k++) {
                    if (in_list(p1, nb_pixels, j, k) == 1) {
                        area->mat[j][k] = 1;
                    }
                }
            }
        }
    }
}

void print_area(Area* area){
    for (int i = 0 ; i<area->width ;i++){
        for (int j = 0; j<area->height ;j++){
            if (area->mat[i][j]==1){
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}
