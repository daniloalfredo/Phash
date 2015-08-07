#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define tam 17
#define len 64
#define bits 256

long long unsigned int strToHex(char* str)
{
	int i;
	long long int num = 0, f;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 'a')
			f = str[i] - 'a' + 10;
		else
			f = str[i] - '0';
		num += f*pow(16, 15-i);
	}
	return num;
}

int number_of_ones(long long unsigned int x)
{
	int total_ones = 0;
	while(x!=0)
	{
		x = x & (x-1);
		total_ones++;
	}
	return total_ones;
}

int hamming(char* str1, char* str2)
{
	int i, hamming = 0;
	long long unsigned int a1, a2, ax;
	char aux1[tam], aux2[tam];
	for (i = 0; i < len; i += 16)
	{
		strncpy(aux1, str1+i, 16);
		strncpy(aux2, str2+i, 16);
		aux1[16] = '\0';
		aux2[16] = '\0';
		//printf("%s\n", aux1);
		//printf("%s\n", aux2);
		a1 = strToHex(aux1); a2 = strToHex(aux2);
		ax = a1 ^ a2;
		hamming += number_of_ones(ax);
	}
	return hamming;
}

int main(int argc, char** argv)
{
	char *im1, *im2, *filename1, *filename2;
	char aux[len];
	int distance;
    im1 = (char*) malloc (bits*sizeof(char));
    im2 = (char*) malloc (bits*sizeof(char));
	filename1 = (char*) malloc(bits*sizeof(char));
	filename2 = (char*) malloc(bits*sizeof(char));

	FILE * input;
	input = fopen("input.txt", "r");
	if (input != NULL)
	{
		fscanf(input, "%s %s", filename2, im2);
	}
	fclose(input);
	strcpy(aux, argv[1]);
	strcat(aux, "_output.txt");
	freopen("hashlist.txt", "r", stdin);
	freopen(aux, "w", stdout);
    while(scanf("%s %s", filename1, im1) > 0)
    {
    	distance = hamming(im1, im2);
    	if (distance < 15)
    		printf("Imagens %s e %s são similares\n", filename1, filename2);
    	else
    		printf("Imagens %s e %s nao sao similares\n", filename1, filename2);
    	printf("Distancia de Hamming: %d\n", distance);
    }
}