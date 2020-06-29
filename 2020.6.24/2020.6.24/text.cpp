#include <stdio.h>
unsigned int my_strlen(const char *str)
{
	int count = 0;
	while (*str != '\0')
	{
		if ((*str >= 'A'&&*str <= 'Z') || (*str >= 'a'&&*str <= 'z'))
		{
			count++;
		}
		str++;
	}
	return count;
}
int main()
{
	char arr[100];
	gets(arr);
	printf("³¤¶ÈÎª£º%d", my_strlen(arr));
	return 0;
}