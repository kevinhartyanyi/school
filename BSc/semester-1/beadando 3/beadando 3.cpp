#include <iostream>

using namespace std;

int main()
{
	int telepules, napok, homerseglet;	
	int szum, ki, seged;

	const int MAXN = 1000;
	double atlag[MAXN];

	//Beolvasas es feldolgozas
	cin >> telepules >> napok >> homerseglet;	
	
	for (int i = 1; i <= telepules; ++i)
	{
		szum = 0;
		for (int j = 0; j < napok; ++j)
		{
			cin >> seged;
			szum += seged;
		}
		//Atlag kiszamitasa
		atlag[i] = (double)szum / napok;		
	}

	//Max kereses
	double max = atlag[1];
	ki = 1;
	for (int i = 2; i <= telepules; ++i)
	{
		if (atlag[i] > max)
		{
			max = atlag[i];
			ki = i;
		}
	}
	
	//Kimenet
	cout << ki << endl;
    return 0;
}

