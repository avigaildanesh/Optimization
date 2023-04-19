#include <stdlib.h>
#include <stdbool.h>
#include "myfunction1.h"
#include "showBMP.h"


	/*
	* [1, 1, 1]
	* [1, 1, 1]
	* [1, 1, 1]
	*/
void smoothtrue(int dim, pixel *src, pixel *dst) {

	int i, j;
	int diker = dim - 1;
	int idim = n+1;
	int ii, jj;
	pixel current_pixel;
	int max_op, min_op;
	int looping;
	int min_intensity;
	int max_intensity;
	int op;
	pixel loop_pixel;
	pixel p;

	for (i = 1 ; i < diker; i++) {
		for (j =  1 ; j < diker; j++) {

		
		min_intensity = 766; // arbitrary value that is higher than maximum possible intensity, which is 255*3=765
		max_intensity = -1; // arbitrary value that is lower than minimum possible intensity, which is 0
		int b = 0, g =0, r =0;
		op = (i-1)* dim + j-1;
		p = src[op];
		r += (p.red);
		g += (p.green);
		b += (p.blue);
	
		loop_pixel = src[op];
		looping = (loop_pixel.red + loop_pixel.green + loop_pixel.blue);
		min_intensity = looping <= min_intensity ? looping: min_intensity;
		min_op = looping <= min_intensity ? op: min_op;

		if (looping > max_intensity) {
			max_intensity = looping;
			max_op = op;
		}
		op++;

		p = src[op];
		r += (p.red);
		g += (p.green);
		b += (p.blue);
	
		loop_pixel = src[op];
		looping = (loop_pixel.red + loop_pixel.green + loop_pixel.blue);
		min_intensity = looping <= min_intensity ? looping: min_intensity;
		min_op = looping <= min_intensity ? op: min_op;
		
		if (looping > max_intensity) {
			max_intensity = looping;
			max_op = op;
		}
		op++;
		p = src[op];
		r += (p.red);
		g += (p.green);
		b += (p.blue);
	
		loop_pixel = src[op];
		looping = (loop_pixel.red + loop_pixel.green + loop_pixel.blue);
		min_intensity = looping <= min_intensity ? looping: min_intensity;
		min_op = looping <= min_intensity ? op: min_op;

		if (looping > max_intensity) {
			max_intensity = looping;
			max_op = op;
		}
		op++;
		op = op -3+ dim;



		p = src[op];
		r += (p.red);
		g += (p.green);
		b += (p.blue);
	
		loop_pixel = src[op];
		looping = (loop_pixel.red + loop_pixel.green + loop_pixel.blue);
		min_intensity = looping <= min_intensity ? looping: min_intensity;
		min_op = looping <= min_intensity ? op: min_op;

		if (looping > max_intensity) {
			max_intensity = looping;
			max_op = op;
		}
		op++;

		p = src[op];
		r += (p.red);
		g += (p.green);
		b += (p.blue);
	
		loop_pixel = src[op];
		looping = (loop_pixel.red + loop_pixel.green + loop_pixel.blue);
		min_intensity = looping <= min_intensity ? looping: min_intensity;
		min_op = looping <= min_intensity ? op: min_op;

		if (looping > max_intensity) {
			max_intensity = looping;
			max_op = op;
		}
		op++;

		p = src[op];
		r += (p.red);
		g += (p.green);
		b += (p.blue);
	
		loop_pixel = src[op];
		looping = (loop_pixel.red + loop_pixel.green + loop_pixel.blue);
		min_intensity = looping <= min_intensity ? looping: min_intensity;
		min_op = looping <= min_intensity ? op: min_op;

		if (looping > max_intensity) {
			max_intensity = looping;
			max_op = op;
		}
		op++;
		op = op -3+ dim;

		p = src[op];
		r += (p.red);
		g += (p.green);
		b += (p.blue);
	
		loop_pixel = src[op];
		looping = (loop_pixel.red + loop_pixel.green + loop_pixel.blue);
		min_intensity = looping <= min_intensity ? looping: min_intensity;
		min_op = looping <= min_intensity ? op: min_op;

		if (looping > max_intensity) {
			max_intensity = looping;
			max_op = op;
		}
		op++;


		p = src[op];
		r += (p.red);
		g += (p.green);
		b += (p.blue);
		loop_pixel = src[op];
		looping = (loop_pixel.red + loop_pixel.green + loop_pixel.blue);
		min_intensity = looping <= min_intensity ? looping: min_intensity;
		min_op = looping <= min_intensity ? op: min_op;

		if (looping > max_intensity) {
			max_intensity = looping;
			max_op = op;
		}
		op++;

		r += (src[op].red);
		g += (src[op].green);
		b += (src[op].blue);
	
		loop_pixel = src[op];
		looping = (loop_pixel.red + loop_pixel.green + loop_pixel.blue);
		min_intensity = looping <= min_intensity ? looping: min_intensity;
		min_op = looping <= min_intensity ? op: min_op;

		if (looping > max_intensity) {
			max_intensity = looping;
			max_op = op;
		}
		op++;
		op = op -3+ dim;


		p = src[min_op];
		r += (p.red) * -1;
		g += (p.green) * -1;
		b += (p.blue) * -1;
		p = src[max_op];
		r += (p.red) * -1;
		g += (p.green) * -1;
		b += (p.blue) * -1;

		r = r / 7;
		g = g / 7;
		b = b / 7;
		current_pixel.red = (r>0 ? (char)r:0) ;
		current_pixel.green = (g>0 ? (char)g:0) ;
		current_pixel.blue = (b>0 ? (char)b:0) ;
		dst[idim] = current_pixel;
				
		idim++;
		}
		idim+=2;
	}
}

void smoothsharpKernel(int dim, pixel *src, pixel *dst) {
	
	int i, j;
	int diker = dim - 1;
	int idim = n+1;
	int ii, jj;
	pixel current_pixel;
	int op;
	for (i = 1 ; i < diker; i++) {
		for (j =  1 ; j < diker; j++) {
		int b = 0, g =0, r =0;
		op = (i-1)* dim + j-1;

		r += (src[op].red) * -1;
		g += (src[op].green) * -1;
		b += (src[op].blue) * -1;
		op++;

		r += (src[op].red) * -1;
		g += (src[op].green) * -1;
		b += (src[op].blue) *-1;
		op++;

		r += (src[op].red) * -1;
		g += (src[op].green) * -1;
		b += (src[op].blue) * -1;
		op++;
		op = op -3+ dim;

		r += (src[op].red) * -1;
		g += (src[op].green) * -1;
		b += (src[op].blue) * -1;
		op++;

		r += (src[op].red) * 9;
		g += (src[op].green) * 9;
		b += (src[op].blue) * 9;
		op++;

		r += (src[op].red) * -1;
		g += (src[op].green) * -1;
		b += (src[op].blue) * -1;
		op++;
		op = op -3+ dim;
		
		r += (src[op].red) * -1;
		g += (src[op].green) * -1;
		b += (src[op].blue) * -1;
		op++;

		r += (src[op].red) * -1;
		g += (src[op].green) * -1;
		b += (src[op].blue) * -1;
		op++;

		r += (src[op].red) * -1;
		g += (src[op].green) * -1;
		b += (src[op].blue) * -1;
		op++;
		op = op -3+ dim;

		current_pixel.red = ((r>0 ? r:0)< 255) ? (r>0 ? r:0):255;
		current_pixel.green = ((g>0 ? g:0)< 255) ? (g>0 ? g:0):255;
		current_pixel.blue = ((b>0 ? b:0)< 255) ? (b>0 ? b:0):255;
		dst[idim]= current_pixel;
		idim++;
	}
	idim+=2;
	}
}

/*
	* [0, 0, 0]
	* [1, 2, 1]
	* [0, 0, 0]
	*/
void smoothrowBlurKernel(int dim, pixel *src, pixel *dst) {

	int i, j;
	int diker = dim - 1;
	int idim = n+1;
	int ii, jj;
	pixel current_pixel;
	int op;
	for (i = 1 ; i < diker; i++) {
		for (j =  1 ; j < diker; j++) {
		int b = 0, g =0, r =0;
		op = (i-1)* dim + j-1;
		op+=3;
		op = op -3+ dim;

		r += (src[op].red);
		g += (src[op].green);
		b += (src[op].blue);
		op++;

		r += (src[op].red) * 2;
		g += (src[op].green) * 2;
		b += (src[op].blue) * 2;
		op++;

		r += (src[op].red);
		g += (src[op].green);
		b += (src[op].blue);
		op++;
		op = op -3+ dim;
		op+=3;
		op = op -3+ dim;

		r = r / 4;
		g = g / 4;
		b = b / 4;
		current_pixel.red = ((r>0 ? r:0)< 255) ? (r>0 ? r:0):255;
		current_pixel.green = ((g>0 ? g:0)< 255) ? (g>0 ? g:0):255;
		current_pixel.blue = ((b>0 ? b:0)< 255) ? (b>0 ? b:0):255;
		dst[idim]= current_pixel;
		idim++;
	}
	idim+=2;
	}
}

/*
	* [0, 0, 0]
	* [-2, 6, -2]
	* [0, 0, 0]
	*/
void smoothrowSharpKernel(int dim, pixel *src, pixel *dst) {

	int i, j;
	int diker = dim - 1;
	int idim = n+1;
	int ii, jj;
	pixel current_pixel;
	int op;
	for (i = 1 ; i < diker; i++) {
		for (j =  1 ; j < diker; j++) {
		int b = 0, g =0, r =0;
		op = (i-1)* dim + j-1;
		op+=3;
		op = op -3+ dim;

		r += (src[op].red) * -2;
		g += (src[op].green) * -2;
		b += (src[op].blue) * -2;
		op++;

		r += (src[op].red) * 6;
		g += (src[op].green) * 6;
		b += (src[op].blue) * 6;
		op++;

		r += (src[op].red) *-2;
		g += (src[op].green) * -2;
		b += (src[op].blue) * -2;
		op++;
		op = op -3+ dim;
		op+=3;
		op = op -3+ dim;

		r = r / 2;
		g = g / 2;
		b = b / 2;
		current_pixel.red = ((r>0 ? r:0)< 255) ? (r>0 ? r:0):255;
		current_pixel.green = ((g>0 ? g:0)< 255) ? (g>0 ? g:0):255;
		current_pixel.blue = ((b>0 ? b:0)< 255) ? (b>0 ? b:0):255;
		dst[idim]= current_pixel;
		idim++;
	}
	idim+=2;
	}
}

/*
	* [1, 1, 1]
	* [1, 1, 1]
	* [1, 1, 1]
*/
void smoothblurKernel(int dim, pixel *src, pixel *dst) {

	int i, j;
	int diker = dim - 1;
	int idim = n+1;
	int ii, jj;
	pixel current_pixel;
	int op;
	for (i = 1 ; i < diker; i++) {
		for (j =  1 ; j < diker; j++) {
		int b = 0, g =0, r =0;
		op = (i-1)* dim + j-1;

		r += (src[op].red);
		g += (src[op].green);
		b += (src[op].blue);
		op++;

		r += (src[op].red) ;
		g += (src[op].green);
		b += (src[op].blue);
		op++;

		r += (src[op].red);
		g += (src[op].green);
		b += (src[op].blue);
		op++;
		op = op -3+ dim;

		r += (src[op].red);
		g += (src[op].green);
		b += (src[op].blue);
		op++;

		r += (src[op].red);
		g += (src[op].green);
		b += (src[op].blue);
		op++;

		r += (src[op].red);
		g += (src[op].green);
		b += (src[op].blue);
		op++;
		op = op -3+ dim;
		
		r += (src[op].red);
		g += (src[op].green);
		b += (src[op].blue);
		op++;

		r += (src[op].red);
		g += (src[op].green);
		b += (src[op].blue);
		op++;

		r += (src[op].red);
		g += (src[op].green);
		b += (src[op].blue);
		op++;
		op = op -3+ dim;

		r = r / 9;
		g = g / 9;
		b = b / 9;
		current_pixel.red = ((r>0 ? r:0)< 255) ? (r>0 ? r:0):255;
		current_pixel.green = ((g>0 ? g:0)< 255) ? (g>0 ? g:0):255;
		current_pixel.blue = ((b>0 ? b:0)< 255) ? (b>0 ? b:0):255;
		dst[idim]= current_pixel;
		idim++;
	}
	idim+=2;
	}
}

void charsToPixels(pixel* pixels) {

	int row;
	int nm = n*m;
	pixel* p = pixels;
	char * im = image->data; 
	for (row = 0 ; row < nm ; row++) {
		pixels->red = *im;
		pixels->green = *(im+1);
		pixels->blue = *(im+2);
		pixels++;
		im+=3;
	}
}

void pixelsToChars(pixel* pixels, Image *charsImg) {

	int row, i = 0,k = 0;
	int nm = m*n;
	char * im = image->data;
	for (row = 0 ; row < nm ; row++) {
		*im = pixels->red;
		*(im+1) = pixels->green;
		*(im+2) = pixels->blue;
		pixels++;
		im+=3;
	}
}

void copyPixels(pixel* src, pixel* dst) {

	int row, i =0;
	int nm = n*m;
	for (row = 0 ; row < nm ; row++) {
		dst->red = src->red;
		dst->green = src->green;
		dst->blue = src->blue;
		src++;
		dst++;

	}
}

void doConvolutiontrue(Image *image) {

	pixel* pixelsImg = malloc(m*n*sizeof(pixel));
	pixel* backupOrg = malloc(m*n*sizeof(pixel));

	charsToPixels(pixelsImg);
	copyPixels(pixelsImg, backupOrg);
	smoothtrue(m, backupOrg, pixelsImg);
	pixelsToChars(pixelsImg, image);

	free(pixelsImg);
	free(backupOrg);
}


void doConvolutionblurKernel(Image *image) {

	pixel* pixelsImg = malloc(m*n*sizeof(pixel));
	pixel* backupOrg = malloc(m*n*sizeof(pixel));

	charsToPixels(pixelsImg);
	copyPixels(pixelsImg, backupOrg);
	smoothblurKernel(m, backupOrg, pixelsImg);
	pixelsToChars(pixelsImg, image);

	free(pixelsImg);
	free(backupOrg);
}

void doConvolutionsharpKernel(Image *image){
	pixel* pixelsImg = malloc(m*n*sizeof(pixel));
	pixel* backupOrg = malloc(m*n*sizeof(pixel));

	charsToPixels(pixelsImg);
	copyPixels(pixelsImg, backupOrg);
	smoothsharpKernel(m, backupOrg, pixelsImg);
	pixelsToChars(pixelsImg, image);

	free(pixelsImg);
	free(backupOrg);
}



void doConvolutionrowBlurKernel(Image *image){
	pixel* pixelsImg = malloc(m*n*sizeof(pixel));
	pixel* backupOrg = malloc(m*n*sizeof(pixel));

	charsToPixels(pixelsImg);
	copyPixels(pixelsImg, backupOrg);
	smoothrowBlurKernel(m, backupOrg, pixelsImg);
	pixelsToChars(pixelsImg, image);
	free(pixelsImg);
	free(backupOrg);
}


void doConvolutionrowSharpKernel (Image *image) {
	pixel* pixelsImg = malloc(m*n*sizeof(pixel));
	pixel* backupOrg = malloc(m*n*sizeof(pixel));

	charsToPixels(pixelsImg);
	copyPixels(pixelsImg, backupOrg);
	smoothrowSharpKernel(m, backupOrg, pixelsImg);
	pixelsToChars(pixelsImg, image);
	free(pixelsImg);
	free(backupOrg);
}