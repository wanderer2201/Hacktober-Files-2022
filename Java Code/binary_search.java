package com.company;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        BinarySearch ob = new BinarySearch();
        int n;
        Scanner sc=new Scanner(System.in);

        //Taking input from the user on the number of elements
        System.out.println("Enter the number of elements in the array");
        n=sc.nextInt();

        //creats an array in the memory of length 20
        int arr[]=new int[20];
        System.out.println("Enter the elements of the array");
        for(int i=0;i<n;i++){

            //reading array elements from the user
            arr[i]=sc.nextInt();

        }
        System.out.println("Array Elements are");
        for(int i=0;i<n;i++){

            //accessing array elements from the user
            System.out.println(arr[i]);
        }

        //choosing the element to be searched
        System.out.println("Enter the element you want to search");
        int x;
        x=sc.nextInt();
        int result = ob.binarySearch(arr, 0, n - 1, x);
        if (result == -1)
            System.out.println("Element not present");
        else
            System.out.println("Element found at index "
                    + result);

    }
}
// the binary search function
class BinarySearch {
// parameters include the array,the left and right ends and the elements you want to search
    int binarySearch(int arr[], int l, int r, int y) {
        if (r >= l) {
            int mid = l + (r - l) / 2; //calculating the middle element
            if (arr[mid] == y)        //if the middle element is equal to the element to be searched
                                      //you found the element
                return mid;

            if (arr[mid] > y)      //if the element is smaller
                                   //it is on the left of the middle element
                return binarySearch(arr, l, mid - 1, y);


            return binarySearch(arr, mid + 1, r, y);
        }


        return -1;
    }
}
