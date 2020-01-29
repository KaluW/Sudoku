#include <stddef.h>
#include <fontlibc.h>

#include "font.h"

static const uint8_t font20_data[] = {
        /* `make font` if font.inc does not exist */
#include "font20.inc"
};

const fontlib_font_t *font20 = (fontlib_font_t *)font20_data;