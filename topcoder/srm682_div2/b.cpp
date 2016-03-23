#include <iostream>
#include <string>
using namespace std;
string cmp[1025];
string tmp[1025];

struct TopBiologist{
	string findShortestNewSequence(string sequence)
	{
		cmp[0] = 'A';
		cmp[1] = 'C';
		cmp[2] = 'G';
		cmp[3] = 'T';

		int ss = 4;
		while(1)
		{
			for(int i = 0; i < ss; i++)
				if(sequence.find(cmp[i]) == string::npos) return cmp[i];

			if(ss >= 1024) return "";
			int idx = 0;
			for(int i = 0; i < ss; i++)
			{
				tmp[idx++] = cmp[i] + "A";
				tmp[idx++] = cmp[i] + "C";
				tmp[idx++] = cmp[i] + "G";
				tmp[idx++] = cmp[i] + "T";
			}
			ss *= 4;
			for(int i = 0; i < ss; i++)
				cmp[i] = tmp[i];
		}
	}
};

int main()
{
	TopBiologist test;
	string str;
	cin >> str;
	cout << test.findShortestNewSequence(str) << endl;
}
