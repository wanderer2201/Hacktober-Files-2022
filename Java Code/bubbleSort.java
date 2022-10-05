package com.company;
import java.util.Scanner;


public class Main{
    public static void main(String[] args){
       
        //Taking user input
        
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of elements:");
        int n=sc.nextInt();
        int arr[]=new int[n];
        
        //Typing the elements of the array
        System.out.println("Enter elements of the array:");
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }

       //sorting the array
        bubbleSort(arr);
        System.out.println("The sorted array is:");
        for(int i=0;i<n;i++){
            System.out.println(arr[i]);

        }


    }

    static void bubbleSort(int[] arr){
        //run steps for n-1 times
        for(int i=0;i<arr.length;i++){
            //for each step max item will come at the last index
            for(int j=1;j<arr.length-i;j++){
                //swap if the item is smaller than the previous item
                if(arr[j]<arr[j-1]){
                    //swap
                    int temp=arr[j];
                    arr[j]=arr[j-1];
                    arr[j-1]=temp;
                }
            }


        }

    }

}

