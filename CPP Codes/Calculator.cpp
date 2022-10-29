#include <iostream>
using namespace std;

int main()
{
    float n1,n2;
    cout<<"Enter Two Numbers"<<endl;
    cin>>n1>>n2;

    char op;
    cout<<"Enter Operation"<<endl;
    cin>>op;

    switch (op)
    {
    case '+':
        cout<<n1 + n2<<endl;
        break;
    case '-':
        cout<<n1-n2<<endl;
    case '*':
        cout<<n1 * n2<<endl;
    case '/':
        cout<<n1 / n2<<endl;   

    default:
        cout<<"Enter Another Operator"<<endl;
        break;
    }
}