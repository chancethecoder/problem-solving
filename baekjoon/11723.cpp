#include <cstdio>
#include <cstring>
using namespace std;

struct my_set{
	bool a[21];

	my_set(){ empty();}
	void add(int x) { a[x] = true;}
	void remove(int x) { a[x] = false;}
	const char* check(int x) { return a[x] ? "1" : "0";}
	void toggle(int x) { a[x] = !a[x];}
	void all() { memset(a, true, sizeof(a));}
	void empty() { memset(a, false, sizeof(a));}
};

void proc()
{
	struct my_set set;
	int m, xx;
	char command[10];
	for(scanf("%d", &m); m--;)
	{
		getchar();
		scanf("%s", command);

		if(!strcmp(command, "all")) set.all();
		else if(!strcmp(command, "empty")) set.empty();
		else
		{
			scanf("%d", &xx);
			if(!strcmp(command, "add")) set.add(xx);
			else if(!strcmp(command, "remove")) set.remove(xx);
			else if(!strcmp(command, "check")) puts(set.check(xx));
			else if(!strcmp(command, "toggle")) set.toggle(xx);
		}
	}
}

int main()
{
	proc();
}
