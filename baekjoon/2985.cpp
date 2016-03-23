#include <cstdio>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if(a == (b + c)) printf("%d=%d+%d\n", a, b, c);
	if(a == (b - c)) printf("%d=%d-%d\n", a, b, c);
	if(a == (b * c)) printf("%d=%d*%d\n", a, b, c);
	if(((b % c) == 0) && (a == (b / c))) printf("%d=%d/%d\n", a, b, c);
	if(c == (a + b)) printf("%d+%d=%d\n", a, b, c);
	if(c == (a - b)) printf("%d-%d=%d\n", a, b, c);
	if(c == (a * b)) printf("%d*%d=%d\n", a, b, c);
	if(((a % b) == 0) && (c == (a / b))) printf("%d/%d=%d\n", a, b, c);
}
