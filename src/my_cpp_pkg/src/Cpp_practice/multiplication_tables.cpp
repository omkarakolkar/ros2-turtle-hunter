#include <iostream>

using namespace std;

void printTable();
void whileTable();
void dowhileTable();

void printTable() //using for loop
{
    for (int i=1; i<=10; i++)
    {
        for (int j=1; j<=10; j++){
            int product = i*j;
            cout << product << "\t";

        }
        cout << endl;
    }

}

void whileTable()  // using while loop
{
    int q=1;
    while(q <= 10)
    {
        int w = 1;
        while(w <= 10)
        {
            int product = q * w;
            cout << product << "\t";
            w++;
        }  
        q++;
        cout << endl;
    }
    
}

void dowhileTable() // using dowhile loop
{
    int i = 1;
    do
    {
        int j =1;
        do
        {
            int product = i * j;
            cout << product << " \t";
            j++;
        } while (j <= 10);
        cout << endl;
        i++;
    } while (i <= 10);
}

int main()
{
    dowhileTable(); //use function according to the loop required but it prints the same
    return 0;
}