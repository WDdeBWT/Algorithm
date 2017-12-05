#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

int get_shi(char *str, int *i);
int get_xiang(char *str, int *i);
int get_wei(char *str, int *i);

main()
{
	int i = 0;
	int bl;
	char str[101];
	scanf("%s", str);
	bl = get_shi(str, &i);
	printf("%d", bl);
}

int get_shi(char *str, int *i)
{
    //printf("---get_shi---");
	int bl;
	bl = get_xiang(str, i);
	while ((str[*i] != '\0') & (str[*i] != ')'))
	{
		if (str[*i] == '|')
		{
			(*i)++;
			bl = bl | get_xiang(str, i);
		}
	}
	(*i)++;
	return bl;
}

int get_xiang(char *str, int *i)
{
    //printf("---get_xiang---");
	int bl;
	bl = get_wei(str, i);
	while (str[*i] == '&')
	{
		(*i)++;
		bl = bl & get_wei(str, i);
	}
	return bl;
}

int get_wei(char *str, int *i)
{
    //printf("---get_wei---");
	if (str[*i] == '!')
	{
		(*i)++;
		return !get_wei(str, i);
	}
	if (str[*i] == '(')
	{
		(*i)++;
		return get_shi(str, i);
	}
	if (str[*i] == 'V')
	{
		(*i)++;
		return 1;
	}
	if (str[*i] == 'F')
	{
		(*i)++;
		return 0;
	}
}

