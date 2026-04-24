#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    
    int n;
    cout<<"Enter Size"<<endl;
    cin>>n;
    int A[n];
    A[0] = 2;

    // A[0] = 12;
    // A[1] = 15;
    // A[2] = 25;

    for (int x:A)
    {
        cout<<x<<endl;
    }
    // for (int i = 0; i < 10; i ++)
    // {
    //     cout<<A[i]<<endl;
    // }

    // cout<<sizeof(A)<<endl;
    // cout<<A[2]<<endl;
    // printf("%d\n", A[3]);

    return 0;
}