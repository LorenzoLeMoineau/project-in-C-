#include <stdlib.h>
#include <printf.h>
#include "line.h"

//
// Created by Amandine Baranger on 21/04/2023.
//
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