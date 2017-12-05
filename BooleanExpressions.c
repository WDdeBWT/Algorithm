#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

int get_shi(char *str, int i);
int get_xiang(char *str, int i);
int get_wei(char *str, int i);

int main()
{
	int i = 0;
	char str[101];
	scanf("%s", str);
	get_shi(str, &i)
}

int get_shi(char *str, int *i)
{
	int bl;
	while (str[i] != '\0')
	{
		if (str[i] == '!')
		{
			(*i)++;
			bl = !get_shi(str, i);
		}
		else if (str[i] == '(')
		{
			bl = get_xiang(str, i);
		}
		else if (str[i] == '&')
		{
			
		}
		else if (str[i] == '|')
		{
			
		}
		else
		{
			bl = str[i];
			(*i)++;
		}
	}
}