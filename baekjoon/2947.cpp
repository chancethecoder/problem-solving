#include <iostream>
using namespace std;
int main()
{
    int a[5];
    for(int i = 0; i < 5; i++) cin >> a[i];
    while(a[0] > a[1] || a[1] > a[2] || a[2] > a[3] || a[3] > a[4])
    {
		for(int i = 0; i < 4; i++)
		{
	        if(a[i] > a[i+1])
        	{
    	        int tmp = a[i];
	            a[i] = a[i+1];
            	a[i+1] = tmp;
        	    for(int j = 0; j < 5; j++) cout << a[j] << " ";
	            cout << "\n";
    	    }
		}
    }
}
