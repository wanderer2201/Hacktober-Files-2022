#include <bits/stdc++.h>
#include<deque>
using namespace std;

int main(){
    vector<int> arr = {-10,9,2,1,3,4,0,3};
    deque<int> q; //Remember : We will be adding the indices to the deque not the elements.
    int k = 3;
    vector <int> MaximumOfEachWindow;
    //for first k elements
    for(int i=0;i<k;i++){
        while(!q.empty() && arr[i]>=arr[q.back()/*remember we are dealing with indices in q*/]){
            /*so the above line means, if the current element is greater than 
            the last index pushed to the deque*/
            q.pop_back();
            /*remove every element from the deque*/
        }
        /* add the index of the newly discovered maximum element*/
        q.push_back(i);
    }
    //push this to our answer but remember dont do q.front() as we are dealing with indices.
    MaximumOfEachWindow.push_back(arr[q.front()]);
    //for k -> n
    for(int i=k;i<arr.size();i++){
        /*first we need to remove the previous windows elements(indices)*/
        while(!q.empty() && q.front()<=i-k)
            q.pop_back();
        /*similarily to previous steps we'll do it for the next window k*/
        while(!q.empty() && arr[i]>=arr[q.back()]){
            q.pop_back();
        }
        /*push the maximum element(index) of the window*/
        q.push_back(i);
        //push all the maximums discovered but remember we are dealing with indices in deque.
        MaximumOfEachWindow.push_back(arr[q.front()]);
    }

    for(auto int each: MaximumOfEachWindow){
        cout << each;
    }


}
