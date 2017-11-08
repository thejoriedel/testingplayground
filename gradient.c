#include "cairo.h"
#include <math.h>
#include <emscripten/emscripten.h>

int main(int argc, char ** argv) {
    printf("gradient.c: main: WebAssembly module loaded.\n");
}

#ifdef __cplusplus
extern "C" {
#endif

int EMSCRIPTEN_KEEPALIVE drawgradient (int argc, char *argv[]) {
    
    cairo_surface_t *surface =
    cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 400, 400);
    cairo_t *cr =
    cairo_create (surface);
    cairo_pattern_t *pat;

    pat = cairo_pattern_create_linear (0.0, 0.0,  0.0, 256.0);
    cairo_pattern_add_color_stop_rgba (pat, 1, 0, 0, 0, 1);
    cairo_pattern_add_color_stop_rgba (pat, 0, 0.42, 0.75, 1, 1);
    cairo_rectangle (cr, 0, 0, 256, 256);
    cairo_set_source (cr, pat);
    cairo_fill (cr);
    cairo_pattern_destroy (pat);

    pat = cairo_pattern_create_radial (115.2, 102.4, 25.6,
                                    102.4,  102.4, 128.0);
    cairo_pattern_add_color_stop_rgba (pat, 0, 0.42, 0.75, 1, 1);
    cairo_pattern_add_color_stop_rgba (pat, 1, 0, 0, 0, 1);
    cairo_set_source (cr, pat);
    cairo_arc (cr, 128.0, 128.0, 76.8, 0, 2 * M_PI);
    cairo_fill (cr);
    cairo_pattern_destroy (pat);
    
    cairo_destroy(cr);
    printf("ran Cairo code");
    // cairo_surface_write_to_png (surface, "gradient.png");
    return 0;
}

void EMSCRIPTEN_KEEPALIVE sayHi() {
    emscripten_run_script("console.log('hi team awesome wasm!')");
}

void EMSCRIPTEN_KEEPALIVE sayXyzzy() {
    emscripten_run_script("console.log('xyzzy');");
}

#ifdef __cplusplus
}
#endif