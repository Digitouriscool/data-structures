#include <iostream>

using namespace std;

class LowerTriangular
{
    private:
        int n;
        int *A;
    public:
        LowerTriangular()
        {
            n = 2;
            A = new int[2 * (2 + 1) / 2];
        }
        LowerTriangular(int n)
        {
            this->n = n;
            A = new int[n * (n + 1) / 2];
        }
        ~LowerTriangular()
        {
            delete []A;
        }
        void Set(int i, int j, int x);
        int Get(int i, int j);
        void Display();
        int GetDimension() {return n;};
};

void LowerTriangular::Set(int i, int j, int x)
{
    if (i >= j)
        A[n * (j - 1) - (j - 2) * (j - 1) / 2 + i -j] = x;
}

int LowerTriangular::Get(int i, int j)
{
    if (i >= j) 
        return A[n * (j - 1) - (j - 2) * (j - 1) / 2 + i -j];
    else
        return 0;
}

void LowerTriangular::Display()
{
    for (int i = 1; i <= n; i++) 
    {
        for(int j = 1; j <= n; j++) 
        {
            if (i >= j)
                cout<<A[n * (j - 1) - (j - 2) * (j - 1) / 2 + i -j]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int main()
{   
    int d;
    cout<<"Enter Dimensions: ";
    cin>>d;


    LowerTriangular lm(d);
    
    int x;
    cout <<"Enter All Elements: ";
    for (int i = 1; i <= d; i++) {
        for (int j = 1; j <= d; j++) {
            cin>>x;
            lm.Set(i, j, x);
        }
    }
    cout<<endl;
    lm.Display();

    return 0;
}