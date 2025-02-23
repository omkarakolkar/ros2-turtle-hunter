#include <iostream>

using namespace std;

bool in_stock[50] = {false};
int animal_number[50];
char animal_type[50];
float weight[50];

// Function declarations
void Menu();
void create_animal();  // Use global variables directly
void display_animal();
void sell_animal();

int main()
{
    cout << "Revenue for the Pig Sales; " << endl;
    Menu();
    return 0;
}

void create_animal()
{
    int i = 0;
    while (i < 50 && in_stock[i] == true ){
        i++;
    }

    if(i<50) {
        cout << "Enter animal details for selling: " << endl;

        cout << "Animal Type: ";
        cin >> animal_type[i];

        cout << "Animal Number: ";
        while (!(cin >> animal_number[i] || animal_number[i] <= 0)) {  // Input validation
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a valid Animal Number: ";
        }

        cout << "Weight: ";
        while (!(cin >> weight[i] || weight[i] <= 0)) {  // Input validation
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a valid Weight: ";
        }

        in_stock[i] = true;
        cout << "Animal Meat added!" << endl;
    } else {
        cout << "Animal storage full!" << endl;
    }
}

void display_animal()
{
    bool any_in_stock =false;
    for(int i =0; i <50; i++) {
        if (in_stock[i]) {
            cout << "Animal " << i + 1 << " Type: " << animal_type[i] << ", Number: " << animal_number[i] << " Weight: " << weight[i] << endl;
            any_in_stock = true;
        }
    }
    if (!any_in_stock) {
        cout << "No animals in stock." << endl;
    }
    // if (in_stock) {
    //     cout << "Animal Type: " << animal_type << endl;
    //     cout << "Animal Number: " << animal_number << endl;
    //     cout << "Animal Weight: " << weight << endl;
    //     cout << "Status: In Stock" << endl;
    // } else {
    //     cout << "No animal in stock." << endl;
    // }
}

void sell_animal()
{
    bool found = false;
    int entered_number;
    cout << "Enter animal number to sell: ";
    cin >> entered_number;

    for (int i = 0; i < 50; i++) {
        if (animal_number[i] == entered_number && in_stock[i]) {
            found = true; 
            cout << "Animal " << i + 1 << "found! Proceed with selling." << endl;
                
            float daily_price;
            cout << "Enter daily price per unit weight: " ;
            cin >> daily_price;
            while (!(cin >> daily_price || daily_price <= 0)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Enter a valid Daily Price: ";
            }

            float revenue = weight[i] * daily_price;
            cout << "Animal sold! Revenue: " << revenue << endl;

            in_stock[i] = false;  // Mark as sold
            break;
        }
    }

    if (!found) {
        cout << "animal number not found or animal is not in stock." << endl;
    }
}

void Menu()
{
    int option;

    do {
        cout << "\nSelect from the following options:\n" 
             << "1: Create animal\n" 
             << "2: Display animal\n"
             << "3: Sell animal\n"
             << "0: End program\n"

             << "Enter your choice: ";
        while (!(cin >> option)) {  // Input validation
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a valid option: ";
        }

        switch (option) {
            case 1:
                create_animal();
                break;
            case 2:
                display_animal();
                break;
            case 3:
                sell_animal();
                break;
            case 0:
                cout << "Ending program..." << endl;
                break;
            default:
                cout << "Invalid option, please try again!" << endl;
        }
    } while (option != 0);
}

//code with logic and working state failing due to not validating input ffrom the user because of that output going into infinite loop ofm outputs

// #include <iostream>

// using namespace std;

// bool in_stock = false;
// int animal_number;
// char animal_type;
// float weight;

// // Function declarations
// void Menu();
// void create_animal(char &animal_type, int &animal_number, float &weight);  // Pass by reference
// void display_animal();
// void sell_animal();

// int main()
// {
//     cout << "Revenue for the Pig Sales; " << endl;
    
//     Menu();
//     return 0;
// }

// void create_animal(char &animal_type, int &animal_number, float &weight)
// {
    
//     cout << "Enter animal details for selling: " << endl << "Animal Type: ";
//     cin >> animal_type;
//     cout << endl << "Animal number";
//     cin >> animal_number;
//     cout << endl << "Weight: ";
//     cin >> weight;

//     in_stock = true;
//     cout << "Animal Meat added!" << endl;
// }

// void display_animal()
// {
//     if (in_stock) {
//         cout << "Animal type" << animal_type << endl;
//         cout << "Animal Number: " << animal_number << endl;
//         cout << "Animal weight: " << weight << endl;
//         cout << "in stock";
//     } else {
//         cout << "No animal in stock" ;
//     }
// }

// void sell_animal()
// {
//     if (!in_stock){
//         cout << "Animal is not in stock!" ;
//     }

//     int enterednumber;
//     cout << "Enter animal number: " ;
//     cin >> enterednumber;

//     if (enterednumber == animal_number){
//         float daily_price;
//         cout << "Enter daily price: ";
//         cin >> daily_price;

//         float revenue = weight * daily_price;
//         cout << "Animal sold! Revenue: " << revenue << endl; 

//         in_stock = false;
//     }else{
//         cout << "Animal number does not match" << endl;
//     }
// }

// void Menu()
// {   
//     int option;
    
//     do {
//         cout << "Select from following 3 functions:" << endl;
//         cout << "1: Create animal ()" << endl;
//         cout << "2: Display animal ()" << endl;
//         cout << "3: Sell animal (animal number)" << endl;
//         cout << "0: End program" << endl;

//         cin >> option;

//         // if (option == 0){
//         //     break;
//         // }else{
//         //     cout << "Select operation again:" ;
//         // }

//         switch(option){
//             case 1:
//                 create_animal(animal_type, animal_number, weight);
//                 break;
//             case 2:
//                 display_animal();
//                 break;
//             case 3:
//                 sell_animal();
//                 break;
//             case 0:
//                 cout << "Ending Program..." << endl;
//                 break;
//             default:
//                 cout << "Invalid option, please try again!"<< endl;
//         }
//     }while (option != 0);
// }

// void Data_query()
// {
//     float weight;
//     float dailyprice;
    
//     cout << "Weight: " << endl;
//     cin >> weight;
//     cout << "DailyPrice: " << endl;
//     cin >> dailyprice;
//     float r = Calculate_revenue(weight, dailyprice);

//     cout << "Revenue is " << r << endl;
// }

// float Calculate_revenue(float x, float y)
// {
//     float result = x * y;
//     return result;
// }