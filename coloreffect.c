#include <stdio.h>
#include "coloreffect.h"
#include "bitmap.h"

void make_grayscale(const char *input_image, const char *output_image){
	struct bitmap map = load_bitmap_from_file(input_image);
	for(int i = 0; i < map.width; i++){
		for(int j = 0; j < map.height; j++){
		pixel *pix = get_pixel(&map, i,j);
		int red = get_red(pix);
		int blue = get_green(pix);
		int green = get_green(pix);
		int average = (red + blue + green) / 3;
		set_color(pix, average, average, average);
		}
	}
	save_bitmap_to_file(&map, grayScale);
}

void posterize(const char *input_image, const char *output_image){
	struct bitmap map = load_bitmap_from_file(input_image);
	for(int i = 0; i < map.width; i++){
		for(int j = 0; j < map.height; j++){
			pixel *pix = get_pixel(&map,i,j);
			int red = get_red(pix);
			int blue = get_green(pix);
			int green = get_green(pix);
			if(red <= 63 && red >= 0){
				red = 32;
			}
			else if (red <=127 && red >= 64){
				red = 96;
			}
			else if (red <= 191 && red >= 128){
				red = 160;
			}
			else {
				red = 224;
			}
			
			if (green <= 63 && green >= 0){
				green = 32;
			}
			else if (green <=127 && green >= 64){
				green = 96;
			}
			else if (green <= 191 && green >= 128){
				green = 160;
			}
			else{
				green = 224;
			}

			if(blue <= 63 && blue >= 0){
				blue = 32;
			}
			else if (blue <=127 && blue >= 64){
				blue = 96;
			}
			else if (blue <= 191 && blue >= 128){
				blue = 160;
			}
			else {
				blue = 224;
			}

			set_color(pix,red, blue,green);
		}
	}
	save_bitmap_to_file(&map,posterize);
}

void blow_up(const char *input_image, const char *output_image){
	struct bitmap original = load_bitmap_from_file(input_image);
	struct bitmap newmap = new_bitmap(original.width * 2, original.height * 2);

	for(int i = 0; i < original.width; i++){
		for(int j = 0; j < original.height; j++){
			pixel *pix = get_pixel(&original,i,j);
			int red = get_red(pix);
			int blue = get_green(pix);
			int green = get_green(pix);
			if(i-1>=0){
			pixel *pixel_left = get_pixel(&newmap,i-1,j);
			set_color(pixel_left,red,blue,green);
			}
			if(i+1<newmap.width){
			pixel *pixel_right = get_pixel(&newmap, i+1,j);
			set_color(pixel_right,red,blue,green);
			}
			if(j-1>=0){
			pixel *pixel_up = get_pixel(&newmap, i, j-1);
			set_color(pixel_up,red,blue,green);
			}
			if(j+1<newmap.height){
			pixel *pixel_down = get_pixel(&newmap,i,j+1);
			set_color(pixel_down,red,blue,green);	
			}
		}
	}
	free_bitmap(&original);
	save_bitmap_to_file(&newmap,blow_up);
}
