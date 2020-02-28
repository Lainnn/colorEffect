/*
 * bitmap.h
 * Kathryn Lenth
 * 19 September 2019
 * 
 * Header file for simple wrapper around libpng library for use as
 * CMPT 251 course material
 */

#ifndef BITMAP_H
#define BITMAP_H

struct pixel_s;
typedef struct pixel_s pixel;

// Struct representing a bitmap
struct bitmap {
    int width;
    int height;
    void *data;
};

// Creates a new bitmap of the specified dimensions. This function
// allocates memory with malloc() to hold the bitmap data, so make sure
// to call free_bitmap() when you're done with it!
struct bitmap new_bitmap(int width, int height);

// Frees the memory used by the given bitmap. This function will not
// free the bitmap pointer itself, but will clean up bitmap->data.
void free_bitmap(struct bitmap *bitmap);

// Loads a bitmap from the given PNG file; on failure, the returned
// bitmap will have width = height = -1 and data = NULL.
struct bitmap load_bitmap_from_file(const char *filename);

// Saves a bitmap in PNG format to the given file; returns 1 if success
// and 0 on failure.
int save_bitmap_to_file(struct bitmap *bitmap, const char *filename);

// Returns a pointer to the pixel at given coordinates ((0, 0) is at the
// top left, (bitmap->width - 1, bitmap->height - 1) the bottom right).
pixel * get_pixel(struct bitmap *bitmap, int x, int y);

// Returns the red, green, and blue components of a pixel. Each is a
// number between 0 and 255.
int get_red(pixel *p);
int get_green(pixel *p);
int get_blue(pixel *p);

// Sets the red, green, or blue component of a pixel. The value must be
// between 0 and 255.
void set_red(pixel *p, int r);
void set_green(pixel *p, int g);
void set_blue(pixel *p, int b);
// Sets all three components of a pixel at once.
void set_color(pixel *p, int r, int g, int b);

// Some basic colors for your reference:
// r     g     b     color
// -------------------------
// 0     0     0     black
// 255   255   255   white
// 255   0     0     bright red
// 0     255   0     bright green
// 0     0     255   bright blue
// 255   255   0     yellow
// 255   0     255   magenta
// 0     255   255   cyan
// 128   128   128   50% gray

#endif