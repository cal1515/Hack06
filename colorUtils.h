/**
 *
 * Authors: Cal Malone, Taylor Drahota
 * This is the header file that contains our user defined functions.
 */

//This function will convert from an RGB color model to CMYK color model.
int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k) ;

//This function will convert from a CYMK color model to an RGB color model.
int cmyktoRGB (double c, double m, double y, double k, int *r, int *g, int *b) ;

/**This function will convert RGB Values to a grayscale by changing the average,
 * luminosity, or lightness.
 */
 int toGrayScale (int *r, int *g, int *b, Mode m)  ;

 //This enumerated list contains our error code definitions for the program.

 typedef enum  {
   NO_ERROR,
   INVALID_INPUT_ERROR,
   NO_COLOR_ERROR,
   NULL_POINTER_ERROR,
}   Error;

  typedef enum   {
    AVERAGE,
    LIGHTNESS,
    LUMINOSITY,
  } Mode;
