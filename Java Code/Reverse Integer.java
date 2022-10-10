// Example 1:

// Input: x = 123
// Output: 321

// Example 2:

// Input: x = -123
// Output: -321
public int reverse(int x) {
    
    int sign = x > 0 ? 1 : - 1;
    x = Math.abs(x);
    int sum = 0;
    
    while(x > 0)
    {
        int tail = x % 10;
        if(sum > (Integer.MAX_VALUE - tail) / 10)   // Note if  sum* 10 + tail > Integer.MAX_VALUE 
            return 0;                               // we have to return 0;
        
        sum = sum* 10 + tail; 
        x /= 10;
    }
    return sign * sum;
}
