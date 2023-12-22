#include<stdio.h>

int serch(int arr[], int target, int si, int ei){
    while(si <= ei){
        int mid = (si+ei)/2; // Finding mid index of the array

        if(arr[mid] == target){ //case 1
            return mid;
        }

        if(arr[si] <= arr[mid]){ // Mid on L1
            if(arr[si] <= target && target <= arr[mid]){
                return serch(arr, target, si, mid -1);
            }
            else {
                return serch(arr, target, mid+1, ei);
            }
        }
        else {
            if(arr[mid] <= target && target <= arr[ei]){
                return serch(arr, target, mid+1, ei);
            }
            else {
                return serch(arr, target, si, mid-1);
            }
        }
    }
    return -1;
}

void main(){
    int arr[] = {9,10,96,-8,-2,0,1,5,8};
    int target;
    printf("Enter target Element : ");
    scanf("%d", &target);

    if((serch(arr, target, 0, (sizeof(arr) / sizeof(arr[0])) - 1) ) == -1){
        printf("%d is not Found in Array.");
    }else{
        printf("%d found at index %d",target, (serch(arr, target, 0, (sizeof(arr) / sizeof(arr[0])) - 1) ));
    }
}