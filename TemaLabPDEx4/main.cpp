#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

ifstream f1 ("date.in");

char s[100], c[100];
int numberOfPals = 0;

int p, q;

void isPal(int i, int j){
p = i;
q = j;
if (s[i] == s[j]){
        if (i != j){
        numberOfPals ++;

        }
        if (i > 0 && j < strlen(s) - 1){
    isPal(i-1, j+1);
        }
    else
    {

        return;
    }
}

}

int main()
{

    f1.get(s, 100);
    int n  =strlen(s);
    if (s[0] == s[1])
        numberOfPals++;
    if (s[n-2] == s[n-1])
        numberOfPals++;
        int a, b;
    for (int i = 0; i < n; i++){
            a = b = i;
        isPal(a, b);
    }
    int i = 0;
    int var = 0;

    while (i < n){
    a = b = (n-1-i)/2 - var;
    isPal(a, b);
    var ++;
    if (p == i+1){
        strncpy(c, s+p, q-p+1);
        cout << c<<" ";
        i = q;
        var = 0;
    }

    }
        //cout << numberOfPals;
    return 0;
}
