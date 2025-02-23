#include <iostream>

using namespace std;

void welcome();
const float PI = 3.1415;
float square(float num);
void calculate_circle_radius(float radius);

int main()
{
    welcome();
    
    float d_num;
    cout << " Enter decimal: ";
    cin >> d_num;

    float squared_value = square(d_num);
    cout << " Square is " << squared_value << endl;

    float radius;
    cout << "ENter radius: ";
    cin >> radius;

    calculate_circle_radius(radius);

    return  0;
}

void welcome()
{
    cout << "Welcome to program" << endl;
}



float square(float num)
{
    return num * num;
}

void calculate_circle_radius(float radius)
{
    float area = square(radius) * PI;
    cout << "The area of the circle is : " << area << endl;
}