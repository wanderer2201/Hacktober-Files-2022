#include <bits/stdc++.h>
using namespace std;

// Function to print permutations of string
void permute(string a, int l, int r)
{
    // Base case
    if (l == r)
        cout << a << endl;
    else
    {
        // Making permutations
        for (int i = l; i <= r; i++)
        {

            swap(a[l], a[i]);

            // Recursive Call
            permute(a, l + 1, r);

            // Backtracking
            swap(a[l], a[i]);
        }
    }
}

// Driver Code
int main()
{
    string str = "ABCDEF";
    int n = str.size();
    permute(str, 0, n - 1);
    return 0;
}
