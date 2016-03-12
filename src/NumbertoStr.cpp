/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>


void number_to_str(float number, char *str,int afterdecimal)
	
{
	int k, i = 0, l = 1, m = 0, x, loop;
	x = afterdecimal;
	if (afterdecimal == 0)
	{
		x = -1;
	}
	if (number<0)
	{
		str[0] = '-';
		i++;
		m++;
		number = number*-1;
	}
	k = number;
	while (k)
	{
		i++;
		k = k / 10;
	}
	{
		while (afterdecimal>0)
		{
			k = number * 10;
			number = number * 10;
			l++;
			afterdecimal--;
		}
	}
	k = number;
	for (loop = i + x; loop >= m; loop--)
	{
		if (loop == i)
		{
			str[loop] = '.';
		}
		else
		{

			str[loop] = k % 10 + '0';
			k = k / 10;
		}
	}
}

