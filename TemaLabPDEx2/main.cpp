#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <utility>
#include <vector>
using namespace std;

ifstream f1 ("date.in");

int n, m;
vector <vector <int > > v, mat;

void func(int i, int j)
{
    if (i == 0 && j == 0)
    {
        if (mat[i+1][j] > mat[i][j+1])
        {
            mat[i][j] = mat[i+1][j] + v[i][j];
        }
        else
        {
            mat[i][j] = mat[i][j+1] + v[i][j];
        }
        return;
    }
    if (i+1 == n)
    {
        mat[i][j] = mat[i][j+1] + v[i][j];
        if (j-1 < 0)
        {
            func(i-1, j);
        }
        else
        {
            func(i-1, j);
            func(i, j-1);
        }
    }
    else if(j+1 == m)
    {
        mat[i][j] = mat[i+1][j] + v[i][j];
        if (i-1 < 0)
        {
            func(i, j-1);
        }
        else
        {
            func(i-1, j);
            func(i, j-1);
        }
    }
    else if (i-1 < 0)
    {
        if (mat[i+1][j] > mat[i][j+1])
        {
            mat[i][j] = mat[i+1][j] + v[i][j];
        }
        else
        {
            mat[i][j] = mat[i][j+1] + v[i][j];
        }
        func(i, j-1);
    }
    else if (j-1 < 0)
    {
        if (mat[i+1][j] > mat[i][j+1])
        {
            mat[i][j] = mat[i+1][j] + v[i][j];
        }
        else
        {
            mat[i][j] = mat[i][j+1] + v[i][j];
        }
        func(i-1, j);
    }
    else
    {
        if (mat[i+1][j] > mat[i][j+1])
        {
            mat[i][j] = mat[i+1][j] + v[i][j];
        }
        else
        {
            mat[i][j] = mat[i][j+1] + v[i][j];
        }
        func(i-1, j);
        func(i, j-1);
    }

}

void func2(int i, int j)
{
    if (i == n-1 && j == m-1){
            cout <<i<<" "<<j<<endl;
        return;
    }
    if (i+1 !=n && j+1 != n)
    {
        cout <<i<<" "<<j<<endl;
        if (mat[i+1][j] > mat[i][j+1])
        {
            func2(i+1, j);
        }
        else
        {
            func2(i, j+1);
        }
    }
    else if (i+1 == n)
    {cout <<i<<" "<<j<<endl;
        func2(i, j+1);
    }
    else if(j+1 == m)
    {cout <<i<<" "<<j<<endl;
        func2(i+1, j);
    }

}

int main()
{
    f1 >> n>> m;
    v.resize(n);
    mat.resize(n);

    for(int i = 0; i < n; i++)
    {
        v[i].resize(m);
        mat[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            f1 >>v[i][j];
            mat[i][j] = 0;
        }
    }

    func(n-1, m-1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j]<< " ";
        }
        cout << endl;
    }
    cout << "\n"<<mat[0][0]<<"\n";
    func2(0, 0);

    return 0;
}
