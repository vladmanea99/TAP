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
    int m[n];

    for(int i = 0; i < n; i++){
        f1 >>v[i].first >> v[i].second;
    }


        for (int j = 0; j < n; j++){
            m[j] = 1;
        }



            local_max = 1;
        for (int j = 1; j < n; j++){
            for (int z = j - 1; z >= 0; z--){
                if (v[j].first == v[z].second){
                        //cout <<"da\n";
                        local_max = m[z] + 1 > local_max ? m[z]+1:local_max;
                }

            }

             m[j] = local_max;
                global_max = local_max > global_max?local_max:global_max;
        }


        for (int j = 0; j < n; j++){
            cout << m[j]<< " ";
        }
        cout << endl;

    cout << global_max<<endl;

    int sem = 0;

    for (int i = 0; i < n; i++){
        if (m[i] == global_max){
            sem ++;
        }
    }
    cout << "Maxim = "<<sem<<endl;
    return 0;
}
