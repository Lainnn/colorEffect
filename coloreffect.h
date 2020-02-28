#include <stdio.h>
#ifndef COLOREFFECT_H
#define COLOREFFECT_H


void make_grayscale(const char *input_image, const char *output_image);

void posterize(const char *input_image, const char *output_image);

void blow_up(const char *input_image, const char *output_image);

#endif
