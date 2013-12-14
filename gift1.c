/*
ID: ch.vasa1
LANG: C
TASK: gift1
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char input[25][25], temp[25];
	int fcount = 0, j = 0, k = 0, l = 0, donation = 0, tot_friends = 0, balance[25];
	FILE *fin  = fopen ("gift1.in", "r");
    	FILE *fout = fopen ("gift1.out", "w");
	fscanf(fin, "%d", &fcount);
	for (j = 0; j < 25; j++)
		balance[j] = 0;
	for(j = 0; j < fcount ; j++)
		fscanf(fin, "%s", input[j]);
	while (!feof(fin))
	{
		if (fscanf(fin, "%s", temp) == EOF)
			break;
		//printf("%s\n", temp);	
		if (fscanf(fin, "%d", &donation) == EOF)
			break;
		//printf("donaion: %d\n", donation);
		if (fscanf(fin, "%d", &tot_friends) == EOF)
			break;
		//printf("no of friends: %d\n", tot_friends);
		for (k = 0; k < fcount; k++)
			if (!strcmp(input[k], temp))
				break;
		if (tot_friends != 0)
			balance[k] -= (donation / tot_friends) * tot_friends;
		//for (k = 0; k < fcount; k++)
		//	printf("%d ", balance[k]);
		//printf("\n");	
		for (k = 0; k < tot_friends; k++) {
			fscanf(fin, "%s", temp);
		//	printf ("%s\n", temp);	
			for (l = 0; l < fcount; l++) {
				if (strcmp(input[l], temp) == 0)
					balance[l] += donation / tot_friends;
			}
			
		}

	}
	for ( l = 0; l < fcount; l++)
    		fprintf (fout, "%s %d\n", input[l], balance[l]);
	return 0;
}
