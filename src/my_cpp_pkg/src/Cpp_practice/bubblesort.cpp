#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    const int range = 7;
    int arr[range];

    srand(time(0));

    for (int i=0; i<range; i++){
        arr[i] = rand() % 100;
    }

    cout << "Random numbers in the array: ";

    for(int i=0; i<range; i++){
        cout << arr[i] << " " ;
    }    

    cout << endl;
    
    for(int i=0; i<range; i++){
        for (int j = 0; j<range - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            } 
        }
    }

    cout << "Sorted number of arrays: " ;
    for (int i=0; i<range; i++){
        cout << arr[i] << " ";
    }

    cout << endl << endl ;

    return 0;
}