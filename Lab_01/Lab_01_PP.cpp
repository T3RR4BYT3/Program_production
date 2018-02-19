//  Lab 01
//      Program production
//  Pages visualasation
//      Ovsyznnikov Vitaliy
//  IKBO-6-16

#include <iostream>
#include <vector>

using namespace std;

void print(int amount, int current);

int main()
{
    int amount, current = 1;
    
    cout << "Enter the amount of pages: ";  cin >> amount;
    if (amount < 1)
    {
        do{
        cout << "Error, try again. \n\n";

        cout << "Enter the amount of pages: ";  cin >> amount;
       
        }while (amount < 1);
    }
    
    cout << "\nEnter current page: "; cin >> current;
    if ((current < 1) || (current > amount))
    {
        do{
            cout << "Invalid input. Try again\n\n";
            cout << "\nEnter current page: "; cin >> current;
        }while((current < 1) || (current > amount));
    }
    
    print(amount, current);
    
    cout << "\n\n";
}

void print(int amount, int current)
{
    if (amount <= 6)
    {
        for (int i = 1; i <= amount; i++)
        {
            if ( i == current)
                cout << '[' << i << "] ";
            else
                cout << i << ' ';
        }
    }
    
    else{
        if (current - 1 <= 2)
        {
            for (int i = 1; i < 6; i++)
            {
                if ( i == current)
                    cout << '[' << i << "] ";
                else
                    cout << i << ' ';
            }
            cout << ".. " << amount;
        }
        else if((current - 1 > 2) && (amount - current > 2))
        {
            cout << 1 << " .. ";
            for (int i = 2; i >= -2; i--)
            {
                if ( current - i == current)
                    cout << '[' << current << "] ";
                else
                    cout << current - i << ' ';
            }
            cout << ".. " << amount;
        }
        else if (amount - current < 4)
        {
            cout << 1 << " .. ";
            for (int i = 4; i >= 0; i--)
            {
                if (amount - i == current)
                    cout << '[' << amount - i << "] ";
                else
                    cout << amount - i << ' ';
            }
        }
    }
}
