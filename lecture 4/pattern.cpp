#include <iostream>
using namespace std;
int main(){
    int n;
    cin >>n;
    //  for(int i = 1; i <= n; i++){
    //     for(int j= 1; j <= n; j++){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    //  }

    // for(int i = 1; i <= n; i++){
    //     for (int j= 1; j <= n; j++){
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    
    // for(int i = 1; i <= n; i++){
    //     char ch = 'A';
    //     for (int j = 1; j <= n; j++){
    //         cout << ch << " ";
    //         ch += 1;
    //     }
    //     cout << endl;
    // }

    // int num = 1;
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << num << " ";
    //         num++;
    //     }
    //     cout << endl;
    // }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= i; j++){
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j<= i; j++){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

// char ch = 'A';
//     for(int i = 1; i <= n; i++){
//         for (int j = 1; j <= i; j++){
//             cout << ch << " ";
//             ch = ch + 1;
//         }
//         cout << endl;
//     }
       
    //    for (int i = 1; i <= n; i++){
    //     for(int j= 1; j <= i; j++){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    //    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = i; j >= 1; j--){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    // int num = 1;
    // for(int i = 1; i <= n ; i++){
    //     for(int j= 1; j<= i; j++){
    //         cout << num << " ";
    //         num++;
    //     }
    //     cout << endl;
    // }

    for(int i = 1; i<= n; i++){
        for(int j = i; j>= 1; j--){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
