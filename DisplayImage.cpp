#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include "pHash.h"
#define tam 256

using namespace cv;

int main()
{
    char *im1, *im2;
    im1 = (char*) malloc (tam*sizeof(char));
    im2 = (char*) malloc (tam*sizeof(char));
    ulong64 hash1, hash2;
    int distance = -1; 
    freopen("Comp.txt", "r", stdin);
    freopen("result.txt", "w", stdout);
    /*lê uma lista de pares de imagens com o seguinte formato
    img1.ext img2.ext
    img3.ext img4.ext
    O programa então calcula o hash de cada par e compara a distância de Hamming entre cada imagem do par*/
    while(scanf("%s %s", im1, im2) > 0)
    {
        ph_dct_imagehash(im1, hash1);
        ph_dct_imagehash(im2, hash2);
        distance = ph_hamming_distance(hash1, hash2);
        if (distance < 15)
            printf("%s e %s sao similares\n", im1, im2);
        else
            printf("%s e %s nao sao similares\n", im1, im2);
        printf("Distancia entre %s e %s = %d\n\n", im1, im2, distance);
    }
    return 0;
}