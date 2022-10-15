#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int n = 0, temp = 0, rem = 0, count = 0, sum = 0;
    cout << "Enter a number: ";
    cin >> n;

    temp = n;

    /* First Count the number of digits in the given number */
    while (temp != 0)
    {
        temp /= 10;
        count++;
    }

    temp = n;
    while (temp != 0)
    {
        rem = temp % 10;
        sum += static_cast<int>(pow(rem, count));
        temp /= 10;
    }

    if (sum == n)
    {
        cout << n << " is an armstrong number";
    }
    else
    {
        cout << n << " is not an armstrong number";
    }

    return 0;
}
