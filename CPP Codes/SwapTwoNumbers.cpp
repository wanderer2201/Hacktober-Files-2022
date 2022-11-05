// C++ Program to Swap Two Numbers
#include <iostream>
using namespace std;

int main(){
    int num1, num2, temp;
    
    // Asking for input
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    
    // Swapping using a third variable
    temp = num1;
    num1 = num2;
    num2 = temp;
    
    // Displaying output
    cout << "First number after swapping: " << num1 << endl;
    cout << "Second number after swapping: " << num2 << endl;
    
    return 0;
}
