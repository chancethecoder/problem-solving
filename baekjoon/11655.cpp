#include <cstdio>

void proc()
{
	char str[102];
	scanf("%[^\n]", str);

	for(int i = 0; str[i] != '\0'; ++i)
	{
		if(str[i] < 'A' || str[i] > 'z') continue;

		int diff = str[i] < 'a' ? 'A' : 'a';

		str[i] -= diff;
		str[i] = (str[i] + 13) % 26;
		str[i] += diff;
	}

	puts(str);
}

int main()
{
	proc();
	return 0;
}
