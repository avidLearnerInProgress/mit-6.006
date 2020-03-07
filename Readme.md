# Notes

## Lecture 1

### Peak finder problem

#### 1-Dimensional version  

9 different positions : [1,2,3,4,5,6,7,8,9] <=> [a,b,c,d,e,f,g,h,i]
    
Given - a to i are numbers, position 2 is a peak if and only if (b >= a and b>= c)  
Problem - find peak if it exists  
Algorithm -  

a. Naive approach: Start from left
```
# if peak is somewhere in the middle, look at n/2 elements. Worst-case complexity -> Θ(n)  
# Theta because it gives lower and upper bound. Big-o only upper bound  
```

b. Binary search approach: Look at n/2th position
```
if(a[n/2] < a[n/2 - 1]):
    # look only for the left half from 1 .. (n/2 -1)

elif(a[n/2] < a[n/2  +1]):
    # look for right half from (n/2 + 1) .. n

else:
    #peak is at position n/2
```
    Time complexity
        T(N) = T(N/2) + Θ(1)  
        base_case := T(1) = Θ(1)  
        T(N) = Θ(1) + .... log N times ~ Θ(log N)  

![1d_version_naive_approach](./data/snapshots/1d_version_naive_approach.png)  

------

![1d_version_binary_search](./data/snapshots/1d_version_binary_search.png)  

#### 2-Dimensional version

Given - *n* rows and *m* columns. Element 'i' is a peak if and only if all its neighbors are less than the 'i'. where neighbors = { [i + 1][j], [i - 1][j], [i][j + 1], [i][j - 1] }  
Problem - find peak if it exists  
Algorithm -

a. Greedy ascent algorithm: Picks a direction and tries to find a direction following that peak

```
# Makes choices on where to start
# If next_ele in same direction > current: continue exploring
# Else: check for all the neighbors and if they are smaller, we have arrived at a peak
```

    Time complexity
    T(N) = Θ(NM)

b. Divide and conquer algorithm: Binary search coupled in 2-D version

```
Pick middle column j =  m / 2
Find global max on col j at (i,j)
Compare { (i, j-1), (i,j), (i, j+1) }
Pick left_cols if a[i][j-1] >= a[i][j]
Similarly, pick right_cols
If a[i][j] > a[i][j-1] && a[i][j+1], then you find the 2-D peak
```
    Time complexity
    T(N) = T(N, M/2) + Θ(N)
    base_case := T(N,1) = Θ(N)  
    T(N,M) = Θ(N) + .... log M times ~ Θ(N * log M)

![2d_version](./data/snapshots/2d_version.png)

------

![2d_version_optimised_approach](./data/snapshots/2d_version_optimised_approach.png)  
