#include <iostream>

using namespace std;

int main (){

    int option=1;
    string pname[10];
    float pprice[10];

    

    while(option != 0){

        cout << "1. New items\n"
             << "2. Show items\n"
             << "3. Sort items\n"
             << "0. Exit\n"
             << "Enter your option: ";
        cin >> option;

        switch(option)
        {

        case 1:
            int n;
            
            cout << "Number of products:";
            cin >> n;

            for(int i=0; i<n; i++){
                cout << "Enter product name: ";
                getline(cin, pname[i]);
            }

            // cout << "Enter product price: ";

            // for(int i=0; i<n; i++){
            //     cin >> pprice[i];
            // }
        }
    }
}
