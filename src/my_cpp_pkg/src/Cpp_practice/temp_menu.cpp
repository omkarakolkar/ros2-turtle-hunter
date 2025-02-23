#include <iostream>

using namespace std;

int main(){
    string month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int temperature[] = {-1, 0, 4, 8, 13, 17, 21, 24, 19, 11, 9, 5};
    int selection = 1;

    do {
        cout
            << "[1] Show temperature of a month (selection)\n"
            << "[2] Show average anual temperature\n"
            << "[3] Show warmest month\n"
            << "[4] Show temperature sorted\n"
            << "[0] Exit\n" << endl << endl;
        cout<< "Select a option: ";

        cin >> selection;

        cout << endl;
        switch(selection)
        {
        case 1:{
            cout << "Select month: ";
            int option;
            cin >> option;

            cout << "Average temperature of " << month[option-1] << " is " << temperature[option-1] << endl;
            break;
        }
        case 2:{
            float sum =0;

            for(int i = 0; i<12; i++){
                sum = sum + temperature[i];
            }

            cout << "Average anual temperature is " << sum/12 << endl;
            break;
        }
        case 3:{
            float maxTemp = temperature[0];
            int maxIndex = 0;

            for(int i = 0; i<12; i++){
                if(maxTemp < temperature[i]){
                    maxTemp = temperature[i];
                    maxIndex =i;
                }
            }

            cout << "Maximum temperature of the year is " << maxTemp << " in the month of " << month[maxIndex] << endl << endl;
            break ;
        }
        case 4:
            for(int i = 0; i < 12; i++){
                for(int j = 0; j < i-1; j++){
                    if(temperature[j] > temperature[j + 1]){
                        int temp = temperature[j];
                        temperature[j] = temperature[j+1];
                        temperature[j+1] = temp;
                    }
                }
            }

            cout << "Sorted average tempeartures ";
            for (int i = 0; i < 12; i++){
                cout << temperature[i] << " ";
            }
            cout << endl;
            break;
        }
    }while(selection != 0);

    return 0;

}