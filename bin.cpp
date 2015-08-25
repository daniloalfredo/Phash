#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max_BINARY_value 255

using namespace cv;

/// Global variables

Mat src, src_gray, dst;
char dir[] = "Images/";
char name[] = "bin_";

/// Function headers
bool binarize(FILE* fid, int threshold_value, int threshold_type);

/**
 * @function main
 */
int main( int argc, char** argv )
{
	FILE* Imlist = fopen("imagelist.txt", "r");
	if (!binarize(Imlist, 130, 0))
		printf("Operation failed\n");
	else
		printf("Imagens binarizadas e salvas\n");
	return 0;
}

bool binarize(FILE* fid, int threshold_value, int threshold_type)
{
	char str[100];
	char aux[100];
	char aux2[100];
	while(fscanf(fid, "%s", str) > 0)
	{
		strcpy(aux, dir);
		strcpy(aux2, dir);
		strcat(aux, str);
		strcat(aux2, name);
		strcat(aux2, str);
		src = imread(aux, 1);
		cvtColor(src, src_gray, CV_RGB2GRAY);
		threshold(src_gray, dst, threshold_value, max_BINARY_value, threshold_type);
		if (!imwrite(aux2, dst))
		{
			printf("Erro na escrita da imagem %s\n", aux2);
			return false;
		}
	}
	return true;
}