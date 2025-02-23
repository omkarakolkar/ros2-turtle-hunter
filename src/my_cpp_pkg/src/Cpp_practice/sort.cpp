#include <iostream>
#include <cstring>
using namespace std;

int main(){

    int n;
    cout << "Enter number names to be sorted: ";
    cin >> n;
    cin.ignore();
    string a[n];

    cout <<"Enter " << n << " names: ";

    for( int i = 0; i < n; ++i){
        getline(cin, a[i]);
    }

    string temp;
    for(int i = 0; i < n-1; ++i){
        for(int j = i+1; j < n; ++j){
            if (a[i].compare(a[j]) > 0){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    cout << "\nIn Aplhabetical Order is" << endl;
    for (int i=0; i < n; ++i){
        cout << a[i] << endl;
    }

    return 0;
}
































// int main()
// {
//   int i, j, n;
//   string a[10], temp;
//   cout << "How many Names to Sort ? "; cin >> n;
//   cout << "\nEnter "<< n <<" Names\n";
//   cin.ignore();

//   for ( i=0 ; i<n ; ++i )   // loop runs till 0 to n like if entered 3 (0 1 2) so taking n values
//        	getline(cin, a[i]); // it takes the input till enter is pressed all spaces and any characters
//                             // while cin doesnt allow spaces
//   for ( i=0 ; i < n-1 ; ++i )
//       for ( j = i+1 ; j<n; ++j )
//            if ( a[i].compare(a[j]) > 0 )
//                {
//                    a[i]=temp;
//                    a[i]=a[j];
//                    temp=a[j];
//                 }   
        
//   cout << "\nNames in Alphabetical Order\n\n";
//   for ( i=0 ; i<n ; ++i )
//        cout << a[i] <<" \n";
// }