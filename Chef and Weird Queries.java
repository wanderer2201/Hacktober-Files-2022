/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		FastReader sc = new FastReader();
		int t = sc.nextInt();
		while(t-- > 0){
		    long y = sc.nextLong();
		    if(y <= 700){
		        int b = (int) Math.sqrt(y);
		        long ans = 0;
		        for(int i = 1;i <= b;i++){
		            ans += y - (i*i);
		        }
		        System.out.println(ans);
		    }else{
		        int a = (int) Math.sqrt(y - 700l);
		        int b = (int) Math.sqrt(y);
		        long ans = a * 700l;
		        for(int i = a+1;i <= b;i++){
		            ans += (y - ((long)i*i));
		        }
		        System.out.println(ans);
		    }
		}
	}
	
	static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
 
        long nextLong() { return Long.parseLong(next()); }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    
}
