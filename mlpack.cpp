#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <string.h>
#include <iostream>
#include <fstream>
#define TAM 250
#define LIMITE 20000
#define PXL_INTENSITY

using namespace cv;
int main(){
	char *im, *filename;
	std::fstream dataset;
	FILE* imagelist = fopen("imagelist.txt", "r");
	dataset.open("dataset.csv", std::fstream::out);
	im = (char*) malloc (TAM*sizeof(char));
	filename = (char*) malloc(TAM*sizeof(char));
	strcpy(filename, "Images/");

	#ifdef
	while(fscanf(imagelist, "%s", im) > 0)
	{
		strcat(filename, im);
		Mat image = imread(filename, 1);
		for (int i = 0; i < image.rows; i++)
		{
			dataset << format(image.row(i), "csv") << ",";
		}
		for (int j = image.cols; j < LIMITE; j++)
		{
			dataset << "0,";
		}
		dataset << std::endl;
		strcpy(filename, "Images/");
	}
	#endif

	dataset.close(); fclose(imagelist);
	return 0;
}