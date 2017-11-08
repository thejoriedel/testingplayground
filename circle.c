#include "cairo.h"
#include <math.h>

// #define _cairo_arc

int main(int argc, char *argv[])
{
    int ten = 10.0;

double xc = 128.0;
double yc = 128.0;
double radius = 100.0;
double angle1 = 45.0  * (M_PI/180.0);  /* angles are specified */
double angle2 = 180.0 * (M_PI/180.0);  /* in radians           */

cairo_surface_t *surface =
cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 400, 400);
cairo_t *cr =
cairo_create (surface);

cairo_set_line_width (cr, ten);
cairo_arc (cr, xc, yc, radius, angle1, angle2);
cairo_stroke (cr);

// cairo_destroy (cr);
cairo_surface_write_to_png (surface, "circle.png");
// cairo_surface_destroy (surface);
return 0;
}