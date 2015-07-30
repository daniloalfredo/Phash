#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define tam 17
#define len 64
#define bits 256

//Função converte uma string de um número hexadecimal (e.g. "ff283bc") e converte para long long unsigned int
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

//calcula o número de bits setados em 1 do número x
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

//calcula a distância de Hamming entre dois hashs de 256 bits
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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char *im1, *im2;
	int distance;
    im1 = (char*) malloc (bits*sizeof(char));
    im2 = (char*) malloc (bits*sizeof(char));
    while(scanf("%s %s %s %s", im1, im1, im2, im2) > 0)
    {
    	distance = hamming(im1, im2);
    	if (distance < 15)
    		printf("Imagens 1 e 2 são similares\n");
    	else
    		printf("Imagens nao sao similares\n");
    	printf("Distancia de Hamming: %d\n", distance);
    }
}