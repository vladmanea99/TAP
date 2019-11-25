#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <utility>
#include <vector>
using namespace std;

ifstream f1 ("date.in");

int n;
vector <pair < int, int> > v;
int global_max = 1;
int local_max = 1;

int main()
{
    f1 >> n;
    v.resize(n);
    int m[n][n];

    for(int i = 0; i < n; i++){
        f1 >>v[i].first >> v[i].second;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            m[i][j] = 1;
        }
    }

    for (int i = n-1; i >= 0; i--){
            local_max = 1;
        for (int j = i+1; j < n; j++){
            for (int z = j - 1; z >= i; z--){
                if (v[j].first == v[z].second){
                        //cout <<"da\n";
                        local_max = m[z][i] + 1 > local_max ? m[z][i]+1:local_max;
                }

            }

             m[j][i] = local_max;
                global_max = local_max > global_max?local_max:global_max;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << m[i][j]<< " ";
        }
        cout << endl;
    }
    cout << global_max<<endl;

    int sem = 0;

    for (int i = 0; i < n; i++){
        if (m[i][0] == global_max){
            sem ++;
        }
    }
    cout << "Maxim = "<<sem<<endl;
    return 0;
}
