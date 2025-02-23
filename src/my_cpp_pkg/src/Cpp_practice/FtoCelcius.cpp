#include <iostream>

using namespace std;

int main()
{
    float celsius[10];
    int Fahrenheit;
    int Stepsize;
    int Maxvalue;

    cout << "Enter Fahrenheit value: " ;
    cin >> Fahrenheit;
    cout << "Step size: " ;
    cin >> Stepsize ;
    cout << "Max Value: " ;
    cin >> Maxvalue ;

    int temp = Fahrenheit; // Initialize temp outside the loop
    for ( int i = 0; temp <= Maxvalue && i < 10; temp += Stepsize, i++) {
        celsius[i] = ((temp - 32) * 5.0) / 9.0;
    }

    int index = 0;
    while (index < 10 && Fahrenheit + index * Stepsize <= Maxvalue ) {
        cout << index << " F: " << Fahrenheit + index * Stepsize << "Celsius: " <<  celsius[index] << endl;
        index++;
    }

}