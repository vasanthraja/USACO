/*
ID: ch.vasa1
LANG: C
TASK: ride
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char input[100], output[100];
	int i = 0, sum1 = 1, sum2 = 1;
	FILE *fin  = fopen ("ride.in", "r");
    	FILE *fout = fopen ("ride.out", "w");
	fscanf(fin, "%s", input);
	fscanf(fin, "%s", output);
	if (strlen(input) > 6 || strlen(output) > 6) {
		fprintf(fout, "STAY\n");
		return 0;
	}
	for(i = 0; i < strlen(input); i++)
		sum1 = (((input[i] - 64)) * sum1 % 47);
	for(i = 0; i < strlen(output); i++)
		sum2 = (((output[i] - 64) * sum2) % 47);
	if (sum1  == sum2)
    		fprintf (fout, "GO\n");
	else
		fprintf(fout, "STAY\n");
	return 0;
}
