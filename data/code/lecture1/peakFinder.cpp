#include <bits/stdc++.h>

using namespace std;

// peak := [a,b,c] where, iff b >= a && b >= c , then b is a peak

//finds peak in 1d vector
int find_1dpeak(vector<int> v){
    int n = v.size();
    if(n==0)
        return -1;
    if(n==1)
        return v[0];
    //if(n==2)
    //   return *max_element(v.begin(), v.end());

    int mid = n / 2;

    //take left part
    if(v[mid] < v[mid-1]){ //ele_at_mid < ele_at_mid-1 => [5,4,3] 4:mid 
        vector<int> cp;
        copy(v.begin(), v.end()-mid, back_inserter(cp));
        return find_1dpeak(cp);
    }

    //take right part
    if(v[mid] < v[mid + 1]){ //ele_at_mid < ele_at_mid+1 => [4,5,6] 5:mid 
        vector<int> cp;
        copy(v.begin()+(mid), v.end(), back_inserter(cp));
        return find_1dpeak(cp);
    }
    return v[mid]; //satisfies the peak condition
}


//finds peak in 2s vector
int find_2dpeak(vector<int> v){
    return 0;
}

int main(){
    int n = 10;
    //read inputs
   
    vector<int> array = {10, 20, 30, 40, 50, 60};
    vector<int> array1 = {10, 30, 20, 40, 60, 50};

    //find 1d peak
    cout<<find_1dpeak(array)<<"\n";
    cout<<find_1dpeak(array1)<<"\n";

    //find 2d peak

    return 0;
}
