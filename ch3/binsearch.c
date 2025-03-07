/**************** binsearch.c ****************
 * Finds the location of an integer in a list.
 *********************************************
 */

 #include <stdio.h>

 int binsearch(int x, int v[], int n){
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high){
        mid = (low + high) / 2;
        if (x > v[mid])
            low = mid + 1;
        else
            high = mid;
    }

    if (v[low] == x)
        return low;

    return -1;
 }

int main(){
    int v[] = {1,4,7,14,32,50};
    int target = 14;
    int size = sizeof(v) / sizeof(v[0]);

    printf("The value %d is found in the array at position %d\n", target, binsearch(target, v, size));
    return 0;
}