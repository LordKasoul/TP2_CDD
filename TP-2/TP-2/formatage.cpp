#include <iostream>
using namespace std;

void RetourALaLigne(int i)
{
	for (int n(0);n!=i;n++)
	{
		cout << endl;
	}
}

void TabVersDroite(int i)
{
	for (int n(0);n != i;n++)
	{
		cout << "\t";
	}
}

void EspaceVersDroite(int i)
{
	for (int n(0);n != i;n++)
	{
		cout << " ";
	}
}