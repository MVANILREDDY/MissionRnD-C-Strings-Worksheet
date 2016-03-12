/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void word_reverse(char*input, int i, int j);
void str_words_in_rev(char *input, int len)
{
	int i = 0, low = 0, high = -1, spaces[5];
	while (i <= len)
	{
		if ((input[i] == 32 && input[i - 1] != 32) || input[i] == '\0')
		{
			word_reverse(input, low, high);
			low = -1;
		}
		else if (input[i] == 32 && input[i + 1] == 32)
		{
	
			low = -1;
		}
		else 
		{
			if (i == 0 && low == 0)
			{
				low = 0;
			}
			if (low == -1&&input[i]!=32)
			{
				low = i;
			}
			
		}
		high++;
		i++;
	}
	low = 0;
	high = high - 1;
	while (high - low>0)
	{
		input[low] = input[low] ^ input[high];
		input[high] = input[low] ^ input[high];
		input[low] = input[low] ^ input[high];
		low++;
		high--;
	}

}
void word_reverse(char*input, int low, int high)
{
	while (high - low>0)
	{
		input[low] = input[low] ^ input[high];
		input[high] = input[low] ^ input[high];
		input[low] = input[low] ^ input[high];
		low++;
		high--;
	}
}
