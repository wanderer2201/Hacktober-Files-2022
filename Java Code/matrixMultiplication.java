package com.company;
import java.util.Scanner;
public class Main {

    public static void main(String args[])
    {

        //declaring all the variables
        int a, b, p, q, sum = 0, c, d, k;

        Scanner in = new Scanner(System.in);
        System.out.println("Enter the number of rows and columns of first matrix");
        a = in.nextInt();
        b= in.nextInt();

        //the first matrix to be multiplied
        int first[][] = new int[a][b];

        System.out.println("Enter elements of first matrix");

        for (c = 0; c < a; c++)
            for (d = 0; d < b; d++)
                first[c][d] = in.nextInt();

        System.out.println("Enter the number of rows and columns of second matrix");
        p = in.nextInt();
        q = in.nextInt();
        //columns of first matrix should be equal to the rows of the second matrix

        if (b != p)
            System.out.println("The matrices can't be multiplied with each other.");
        else
        {
            //the second matrix too be multiplied
            int second[][] = new int[p][q];
            int multiply[][] = new int[a][q];

            System.out.println("Enter elements of second matrix");

            for (c = 0; c < p; c++)
                for (d = 0; d < q; d++)
                    second[c][d] = in.nextInt();

            for (c = 0; c < a; c++)
            {
                for (d = 0; d < q; d++)
                {
                    for (k = 0; k < p; k++)
                    {
                        //the result  of multiplication
                        sum = sum + first[c][k]*second[k][d];
                    }

                    multiply[c][d] = sum;
                    sum = 0;
                }
            }

            System.out.println("Product of the matrices:");

            for (c = 0; c < a; c++)
            {
                for (d = 0; d < q; d++)
                    System.out.print(multiply[c][d]+"\t");

                System.out.print("\n");
            }
        }
    }
}

