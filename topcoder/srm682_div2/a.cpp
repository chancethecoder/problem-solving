#include <string>
using namespace std;

struct DNASequence{
	int longestDNASequence(string sequence)
	{
		int sol = 0;
		for(int i = 0; i < sequence.length(); i++)
		{
			int j = i;
			while(sequence[j] == 'A' ||
					sequence[j] == 'C' ||
					sequence[j] == 'G' ||
					sequence[j] == 'T') j++;
			if(sol < j) sol = j;
			if(j == sequence.length() - 1) break;
		}

		return sol;
	}
};
