#include <iostream>

using namespace std;

bool in_stock = false;
int animal_number;
char animal_type;
float weight;

// Function declarations
void Menu();
void create_animal(char animal_type, int animal_number, float weight);  // Pass by value (not reference)
void display_animal();
void sell_animal();

int main()
{
    cout << "Revenue for the Pig Sales; " << endl;
    
    Menu();
    return 0;
}

// Function to create a new animal
void create_animal(char animal_type, int animal_number, float weight)
{
    cout << "Enter animal details for selling: " << endl;
    cout << "Animal Type: ";
    cin >> animal_type;  // Get animal type
    cout << "Animal number: ";
    cin >> animal_number;  // Get animal number
    cout << "Weight: ";
    cin >> weight;  // Get weight of the animal

    in_stock = true;  // Animal is now in stock
    cout << "Animal Meat added!" << endl;
}

// Function to display animal details
void display_animal()
{
    if (in_stock) {
        cout << "Animal type: " << animal_type << endl;
        cout << "Animal Number: " << animal_number << endl;
        cout << "Animal weight: " << weight << endl;
        cout << "Status: in stock" << endl;
    } else {
        cout << "No animal in stock" << endl;
    }
}

// Function to sell an animal
void sell_animal()
{
    if (!in_stock) {
        cout << "Animal is not in stock!" << endl;
        return;
    }

    int enterednumber;
    cout << "Enter animal number to sell: ";
    cin >> enterednumber;

    if (enterednumber == animal_number) {
        float daily_price;
        cout << "Enter daily price: ";
        cin >> daily_price;

        // Calculate revenue
        float revenue = weight * daily_price;
        cout << "Animal sold! Revenue: " << revenue << endl;

        // Mark the animal as no longer in stock
        in_stock = false;
    } else {
        cout << "Animal number does not match" << endl;
    }
}

// Function to display the menu and handle user input
void Menu()
{
    int option;

    do {
        // Display menu options
        cout << "Select from the following 3 functions:" << endl;
        cout << "1: Create animal ()" << endl;
        cout << "2: Display animal ()" << endl;
        cout << "3: Sell animal (animal number)" << endl;
        cout << "0: End program" << endl;

        cin >> option;  // Get user input

        switch(option) {
            case 1:
                create_animal(animal_type, animal_number, weight);  // Pass variables by reference
                break;
            case 2:
                display_animal();
                break;
            case 3:
                sell_animal();
                break;
            case 0:
                cout << "Ending Program..." << endl;
                break;
            default:
                cout << "Invalid option, please try again!" << endl;
        }
    } while (option != 0);  // Loop until user chooses to end the program
}
// #include <iostream>

// using namespace std;

// int main()
// {
//     float x, y;
//     char a;
//     float result;

//     while (true){
//         cout << "Enter equation with operations on 2 numbers : " << endl;
//         cin >> x >> a >> y; // input in one line no need to prompt user 3 times
//         // cout << "Number 2: ";
//         // cin >> y;
//         // cout << "Choose operator: + | - | * | / | : " ;
//         // cin >> a;

//         if (a == '+' || a == '-' || a == '*' || a == '/'){
//             break;
//         }else{
//             cout << "Incorrect operator entered, use correct operator from the given options." << endl;
//         }
//     }

//     switch (a) {
//         case '+':
//             result = x + y;
//             cout << "Result: " << result << endl;
//             break;
//         case '-':
//             result = x - y;
//             cout << "Result: " << result << endl;
//             break;
//         case '*':
//             result = x * y;
//             cout << "Result: " << result << endl;
//             break;
//         case '/':
//             if (y != 0) {
//                 result = x / y;
//                 cout << "Result: " << result << endl;
//             }else {
//                 cout << "Error Division by zero" << endl;
//             }
//             break;
//     }
    
// }

// calculator using switch case
// take inputs a and b
// choose operator _+*/ 
// if conditions or switch case 
// 