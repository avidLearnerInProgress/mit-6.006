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


int findGlobalMax(vector<vector<int>> v, int column){

    if(column > v.size() || column < 0) return -1; //edge-case

    int max = -1, index = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i][column] > max){
            max = v[i][column];
            index = i;    
        }
    }
    return index;
}

/*globalMax -> index_of_max 
row_wise_check := 1 <= index_of_max < row_of_vector.size()
col_wise_check := 1 <= column < col_of_vector.size()
*/
bool isValid(vector<vector<int>> v, int column, int globalMax){
    return ((globalMax >= 1) && (globalMax < v.size()-1) && (column >= 1) && (column < v[globalMax].size()-1));
}

//finds peak in 2s vector
int find_2dpeak(vector<vector<int> > v, int &l, int &h){
    
    auto sz = v.size();
    if(sz == 0) return -1;

    int mid = l + (h - l)/ 2;
    
    //got the col_mid, now find the global_max from the range of columns..
    int globalMax = findGlobalMax(v, mid);
    if(isValid(v, mid, globalMax)){
        if((v[globalMax][mid] >= v[globalMax - 1][mid])
        && (v[globalMax][mid] >= v[globalMax + 1][mid]) 
        && (v[globalMax][mid] >= v[globalMax][mid - 1])
        && (v[globalMax][mid] >= v[globalMax][mid + 1]))
            return v[globalMax][mid];
    }
    else if(mid > 0 && v[globalMax][mid] < v[globalMax][mid-1]){
        h = mid;
        return find_2dpeak(v, l, h);
    }
    else if(mid < v[globalMax].size() && v[globalMax][mid + 1] > v[globalMax][mid]){
        l = mid;
        return find_2dpeak(v, l, h);
    }

    return v[globalMax][mid];
}

int main(){
    int n = 10;
    //read inputs
   
    vector<int> array = {10, 20, 30, 40, 50, 60};
    vector<int> array1 = {10, 30, 20, 40, 60, 50};

    vector<vector<int>> array2 = {
                                    {30, 20, 10, 40, 50},
                                    {60, 120, 55, 65, 70},
                                    {25, 35, 45, 75, 85},
                                    {0, 1, 2, 3, 4}
                                };
    //find 1d peak
    cout<<find_1dpeak(array)<<"\n";
    cout<<find_1dpeak(array1)<<"\n";

    //find 2d peak
    int l = 0, r = array2.size();
    cout<<find_2dpeak(array2, l, r)<<"\n";

    return 0;
}
