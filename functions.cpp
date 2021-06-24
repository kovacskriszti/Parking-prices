#include<iostream>
#include"constants.cpp"
#include"functions.h"

using namespace std;
// Definirea functiilor

// Functia care citeste pretul parcarii.
int ReadPrice()
{
    int price = 0;
    // citim pretul parcarii, asigurandu-ne ca se va introduce o valoare corecta intre 3 si 120
    do
    {
        cout << "Introduce-ti pretul parcarii intre 3 si 120:" << endl;
        cin >> price;
    } while (price<MINPRICE || price>MAXPRICE);
    return price;
}

// Functia care citeste bancnotele introduse
// Exista o functie care face acelas lucru dar in alt mod mai jos.
int ReadInputBanknotes(int price)
{
    int input = 0;
    // sunt citite bancnotele introduse. Cand suma bancnotelor depaseste pretul introdus anterior, citirea se opreste
    do
    {
        int a = 0;
        cout << "Introduceti o bancnota de 1, 5, 10 sau 50 de lei: " << endl;
        cin >> a;
        // Este testata validitatea bancnotelor cu o functie definita mai jos
        if (CheckBanknote(a))
        {
            // Doar bancnotele valide sunt adaugate in variabila input, care tine totalul sumei introduse.
            input += a;
        }
    }     while (input < price);
    return input;
}

// functia afiseaza pe consola bancnotele pentru rest si scade din restul total bancnotele care au fost deja returnate
void ReturnBanknotes(int bnote, int &remaining)
{
    // Pentru eficienta se foloseste un pointer la variabila care tine restul, astfel aceasta va scadea la terminarea functiei daca au fost returnate bancnote
    // Se ia in considerare ca functia va fi apelata succesiv cu bancnote diferite in ordinea descrescatoare a valorii acestora
    int result = remaining/bnote;
    if (result > 0)
        remaining = remaining - (bnote * result);
    cout << result << " bancnote de " << bnote << endl;
}

// Functia care se foloseste de apelarea succesiva a celei anterioare pentru a afisa restul in bancnote
void ShowRemaining(int remaining)
{
    // mai intai se afiseaza restul total dupa care functia definita anterior este apelata succesiv pentru toate bancnotele care pot fi date ca rest in cazul in care chiar exista un rest
    cout << "Restul este de " << remaining;
    if (remaining > 0)
    {
        // pointerul foloseste functia precedenta la scaderea bancnotelor din total. Dupa fiecare apel al functiei de mai jos variabila la care pointerul este setat va contine restul ramas dupa scaderea bancnotelor deja returnate
        int* ptRemaining = &remaining;
        cout << " impartit astfel:" << endl;
        ReturnBanknotes(ten, *ptRemaining);
        ReturnBanknotes(five, *ptRemaining);
        ReturnBanknotes(one, *ptRemaining);
    }
}

// O alta functie de citit bancnotele introduse. Aceasta citeste bancnotele pe rand, in functie de numarul de bancnote de o anumita valoare.
int ReadInputBanknotes()
{
    int result = 0;
    string message = "Introduceti numarul de bancnote cu valoarea ";
    int values []= { one, five, ten, fifty };
    for (int i = 0; i < 4; i++)
    {
        int value = 0;
        do
        {
            cout << message << values[i] << endl;
            cin >> value;
        } while (CheckBanknote(value));
        result += value * values[i];
    }
    return result;
}

bool CheckBanknote(int value)
{
    if (value == one || value == five || value == ten || value == fifty)
        return true;
    return false;
}