#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int x = rand() %100 +1;

    for(int i = 0; i <= 5; i++)
    {
        
        int y;

        cout << "Enter number: ";
        cin >> y;

        if (y == x)
        {
            cout << "You Won" << endl;
            break;
        }
        else if(y > x)
        {
            cout << "Too large" << endl;
        }
        else{
            cout << "Too small" << endl;
        }

        if(i == 5){
            cout << "You lose! Number of attempts exhausted. number was :" << x; 
        }
    }
    return 0;
}