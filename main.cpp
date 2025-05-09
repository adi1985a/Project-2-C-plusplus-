#include <iostream>
#include <ctime>

using namespace std;

void losuj(int tab[],int n, int p, int k);
void wyswietl ( int tab[], n);

int main()
{
    srand(time(NULL));
    int X[N], Y[N], Q[N];
    int p, k;


    cout << "Podaj przedzial p: " << endl;
    cin >> p;
    cout << "Podaj przedzial k: " << endl;
    cin >> k;


    return 0;
}

void losuj(int tab[],int n, int p, int k);
    for(int i = 0; i<n ; i++)
    {
        tab[i] = rand()%(k+p+1)+p;
    }

void wyswietl ( int tab[], n)
{
    for(ubt u = 0; i<n ; i++)
    {
        cout << tab[i] << "\t";
    }
}
