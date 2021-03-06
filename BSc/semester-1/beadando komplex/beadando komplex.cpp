#include <iostream>
#include <string>


using namespace std;


int ellenorzes(int min, int max)
{
	bool hiba = false;
	int szam;

	do
	{
		hiba = false;
		string seged;
		cin >> seged;		

		for (int i = 0; i < seged.length(); ++i)
		{
			if ((!isdigit(seged[i]) && seged[i] != '-') || (i > 0 && seged[i] == '-'))//Hogy '-' csak az elso karakter lehesen
			{
				hiba = true;
			}
		}		

		if (!hiba)
		{
			szam = stoi(seged);
			hiba = szam < min || szam > max;
		}

		if (hiba)
		{
			cout << "Hibas szamot adtal meg!" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	} while (hiba);	

	return szam;
}


int megoldas(int telepulesek, int napok, int ki[])
{
	int db = 0;
	int homersegletek;

	for (int i = 0; i < telepulesek; ++i)
	{
		bool vanharmincfeletti = false;
		int harmincfelett = 0;

		for (int j = 0; j < napok; ++j)
		{
			homersegletek = ellenorzes(-50, 50);

			if (vanharmincfeletti == false && homersegletek > 30)
			{
				++harmincfelett;

				if (harmincfelett == 7)
				{
					vanharmincfeletti = true;
				}
			}
			else
			{
				harmincfelett = 0;
			}

		}
		if (vanharmincfeletti)
		{
			ki[db] = i + 1;
			++db;
		}
	}

	return db;
}



int main()
{
	ios::sync_with_stdio(false);
	const int MAXN = 1000;
	int ki[MAXN];
	int db = 0;
	int telepulesek;
	int napok;


	telepulesek = ellenorzes(-100, 1000);
	napok = ellenorzes(1, 1000);

	db = megoldas(telepulesek, napok, ki);

	//Kimenet

	cout << db << " ";
	for (int i = 0; i < db; ++i)
	{
		cout << ki[i] << " ";
	}
	cout << endl;

	return 0;
}
