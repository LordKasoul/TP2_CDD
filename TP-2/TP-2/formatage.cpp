#include <iostream>
using namespace std;

void retour(int i)
{
	for (int n(0);n!=i;n++)
	{
		cout << endl;
	}
}

void tab(int i)
{
	for (int n(0);n != i;n++)
	{
		cout << "\t";
	}
}

void espace(int i)
{
	for (int n(0);n != i;n++)
	{
		cout << " ";
	}
}