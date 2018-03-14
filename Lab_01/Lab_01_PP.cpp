//  Lab 01
//      Program production
//  Pages visualisation
//      Ovsyannikov Vitaliy
//  IKBO-6-16

#include <iostream>

using namespace std;

class Pager{
public:
    int amount, current;
    unsigned int* array = new unsigned int [amount+1];
    void pager();
    void print();
    
    Pager()
    {
        cout << "Enter amount of pages: "; cin >> amount;
        cout << "Enter current page: "; cin >> current;
    }
};

using namespace std;


int main()
{
    Pager pg;
    bool cont = 1;
    while (cont)
    {
        pg.pager();
        pg.print();
        cout << "\n\nContinue? (1/0)\n"; cin >> cont;
        if (cont)
        {
            cout << "Enter current page: "; cin >> pg.current;
        }
    }
    cout << "\n\n\n\n\nSee ya\n\n";
    
}

void Pager:: pager()
{
    for (int i = 1; i <= amount; i++)
    {
        if ((i == 1) || (i == amount))
            array[i] = 1;
        else if (i == current)
        {
            if(current <= 4)
                for (int k = 1; k <= current + 2; k++)
                {
                    array[k] = 1;
                    i = k;
                }
            
            else if (amount - current <= 2)
                for (int k = amount; k >= current - 2; k--)
                {
                    array[k] = 1;
                    i = amount - 1;
                }

            else
                for (int k = current - 2; k <= current + 2; k++)
                {
                    array[k] = 1;
                    i = k;
                }
            
        }
        else
            array[i] = 0;
    }
    
    if (current == 1)
        for (int k = 1; k <= current + 2; k++)
            array[k] = 1;
    if (current == amount)
        for (int k = amount; k >= current - 2; k--)
            array[k] = 1;
}

void Pager::print()
{
    cout << "\n\n";
    int k = 1;
    while (k <= amount)
    {
        if ((array[k] == 1) && (array[k+1] == 0) && (k != amount))
            cout << k << " .. ";
            
        else if ((array[k] == 1) && (k != current) && (k != amount))
            cout << k << ' ';
        
        else if ((array[k] == 1) && (k == current))
        {
            cout << '[' << k << "] ";
        }
        else if (k == amount)
            cout << k << '\n';
        k++;
    }
}
