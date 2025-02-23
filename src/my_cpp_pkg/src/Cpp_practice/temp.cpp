#include <iostream>

using namespace std;

int main()
{ 
   	float f_temp;
	float celsius;

	cout << "Welcome to temperature convertor" << endl;
	cout << "Enter the temperature in fahrenheit :";
	cin >> f_temp;
	celsius = ((f_temp - 32)*5)/9;
	cout << "Temperature in Celsius is " << celsius;
    return 0;

	
}
    
    
 