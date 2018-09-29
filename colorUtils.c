/**
 * Authors: Cal Malone, Taylor Drahota
 *
 * The source file that implements and converts between color scales
 * using our defined functions.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "colorUtils.h"

int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k)  {

double newR = r / 255 ;
double newG = g / 255 ;
double newB = b / 255 ;

  if(((r || g || b) >255) || ((r || g || b)<0)) {
    return INVALID_INPUT_ERROR ;
  } else if (r == 0 && g == 0 && b ==0) {
    return NO_COLOR_ERROR ;
  ) else if (m == NULL || y == NULL || k == NULL || c== NULL) {
    return NULL_POINTER_ERROR ;
  }
  if(newR > newG && newR > newB) {
    newR = double maxRGBValue ;
  }
  if(newG > newR && newG > newB) {
    newG = maxRGBValue ;
  }
  if(newB > newR && newB > newG) {
    newB = maxRGBValue ;
  }
*k = (1 - maxRGBValue) ;
*c = (1 - newR - *k)/(1-*k) ;
*m = (1 - newG - *k)/(1-*k) ;
*y = (1 - newB - *k)/(1-*k) ;
}
return NO_ERROR ;
}

int cmyktoRGB (double c, double m, double y, double k, int *r, int *g, int *b)  {
  if (((c || y || m || k) < 0) || ((c || y || m || k) > 1))
  return INVALID_INPUT_ERROR ;
} else if (r == NULL || g == NULL || b == NULL) {
  return NULL_POINTER_ERROR ;
}
*r = round( (255.0 * (1 - c) * (1 - k) * 100) / 100) ;
*g = round( (255.0 * (1 - m) * (1 - k) * 100) / 100) ;
*b = round( (255.0 * (1 - y) * (1 - k) * 100) / 100) ;

return NO_ERROR ;
}

int toGrayScale (int *r, int *g, int *b, Mode m)  {
  double max = 0
  double min = 0

  if(((*r || *g || *b) > 255) || ((*r || *g || *b) < 0))
    return INVALID_INPUT_ERROR ;
  }
  if(r == NULL || g == NULL || b == NULL) {
    return NULL_POINTER_ERROR ;
  }

  if(m == AVERAGE) {
    *r = round((((*r + *g + *b) / 3.0) * 100) / 100) ;
    *g = *r ;
    *b = *r ;

  } else if(m == LIGHTNESS) {
    if(*r >= *g && *r >= *b) {
      max = *r ;
  }   else if(*g >= *r && *g >= *b) {
      max = *g ;
  }   else if(*b >= *r && *b >= *g) {
      max = *b ;
  }
  if(*r <= *g && *r <= *b) {
    min = *r ;
}   else if(*g <= *r && *g <= *b) {
    min = *g ;
}   else if(*b <= *r && *b <= *g) {
    min = *b ;
  }
  *r = round (((max + min) / 2) * 100) / 100) ;
  *g = round (((max + min) / 2) * 100) / 100) ;
  *b = round (((max + min) / 2) * 100) / 100) ;

} else if(m == LUMINOSITY)  {
  *r = round((((*r * .21) + (*g * .72) + (*b * .07)) * 100) / 100) ;
  *g = *r ;
  *b = *r ;
}
  return NO_ERROR;
}
