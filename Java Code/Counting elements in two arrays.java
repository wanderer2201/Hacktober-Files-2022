public static ArrayList<Integer> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n)

    {

       // add your code here

       ArrayList<Integer> list= new ArrayList<>();

       Arrays.sort(arr2);

       

       int i=0;

       

       while(i<m){

           int j=0;

           int count=0;

           while(j<n && arr2[j]<=arr1[i]){

               count++;

               j++;

           }

           

           list.add(count);

           i++;

       }

       

       return list;

    }
