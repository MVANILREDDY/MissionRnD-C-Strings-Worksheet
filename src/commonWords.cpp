/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31
char ** finding_similar(char *str1, char *str2);
char ** commonWords(char *str1, char *str2) 
{
	char **common;
	if (str1 != 0 && str2 != 0)
	{
		common = finding_similar(str1, str2);
		return common;
	}
	else
	{
		return NULL;
	}
}

char** finding_similar(char*a, char *b)
{
	int i = 0, j = 0, k = 0, l, count = 0, q, iterate = 0, x, index = 0, check = 0, loop = 0;
	char **d, **m;
	int *arr;
	arr = (int*)calloc(1, sizeof(int));
	while (b[index] != '\0')
	{
		if (b[index] == 32 && b[index + 1] == 32)
			index++;
		else if (b[index] == 32)
		{
			arr[check] = index + 1;
			index = index + 2;
			check++;
			arr = (int*)realloc(arr, (check + 1)*sizeof(int));
		}
		else
		{
			index++;
		}
	}
	arr[check] = index;
	m = (char**)calloc(1, sizeof(char*));
	d = (char**)calloc(1, sizeof(char*));
	for (i = 0; i<5; i++)
	{
		d[i] = (char*)calloc(31, sizeof(char));
	}
	i = 0;
	while (a[k] != '\0')
	{
		if (a[k] == 32 && a[k + 1] == 32)
		{
			k++;
		}
	  else if (a[k] == 32 || a[k + 1] == '\0')
		{
			if (a[k + 1] == '\0')
			{
				d[i][j] = a[k];
				if (a[k-1]== 32&&i==0)
				{
					return NULL;
				}
				j++;
				d[i][j] = '\0';

			}
			while (b[iterate] != '\0')
			{
				count = 1;
				for (q = 0; q<j; q++)
				{
					if (b[iterate + q] == '\0')
					{
						for (q = 0; q<j; q++)
						{
							d[i][q] = '\0';
						}
						j = 0;
						break;
					}
					if (d[i][q] == b[iterate + q])
					{
						count = count && 1;

					}
					else{
						count = count && 0;
					}
				}
				if (count == 1)
				{
					i++;
					j = 0;
					break;

				}
				if (loop <= check)
				{
					iterate = arr[loop];
					loop++;
				}
			}
			loop = 0;
			iterate = 0;
		}
		else
		{
			d[i][j] = a[k];
			j++;
		}
		k++;
	}
	if (i == 0)//i value used to check no of common words
	{
		return NULL;
	}
	else{
		return d;
	    }
}
