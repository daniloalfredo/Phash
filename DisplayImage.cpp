#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <opencv2/opencv.hpp>
#include "pHash.h"
#define tam 256

using namespace cv;

int main(int argc, char** argv)
{
    char *im1, *im2;
    im1 = (char*) malloc (tam*sizeof(char));
    char filename[tam];
    //im2 = (char*) malloc (tam*sizeof(char));
    //Mat image1, image2;
    ulong64 hash1, hash2;
    ph_dct_imagehash(argv[1], hash2);
    int distance = -1; 
    freopen("imagelist.txt", "r", stdin);
    strcpy(filename, argv[1]);
    strcat(filename, "_phash.txt");
    freopen(filename, "w", stdout);
    //Mat image;
    //image = imread( argv[1], 1 );
    strcpy(filename, "Images/");
    while(scanf("%s", im1) > 0)
    {
        ph_dct_imagehash(strcat(filename, im1), hash1);
        distance = ph_hamming_distance(hash1, hash2);
        if (distance < 15)
            printf("%s e %s sao similares\n", im1, argv[1]);
        else
            printf("%s e %s nao sao similares\n", im1, argv[1]);
        printf("Distancia entre %s e %s = %d\n\n", im1, argv[1], distance);
        strcpy(filename, "Images/");
    }
    return 0;
}