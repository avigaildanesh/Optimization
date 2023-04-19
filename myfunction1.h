#ifndef MYFUNCTION1_H
#define MYFUNCTION1_H

#include "myutil.h"
#include "readBMP.h"

void initialize_pixel_sum(pixel_sum *sum);
void doConvolution(Image *image, int kernel[3][3], int kernelScale, bool filter);
void doConvolutionblurKernel(Image *image);
void doConvolutionsharpKernel(Image *image);
void doConvolutionrowBlurKernel(Image *image);
void doConvolutionrowSharpKernel(Image *image);
void doConvolutiontrue(Image *image);

#endif
