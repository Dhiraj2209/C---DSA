#include<stdio.h>

void rev(int arr[], int n);
void print(int arr[], int n);
    
int main(){
    int n;
    printf("size of array : ");
    scanf("%d", &n);
    
    int arr[n];

    for(int i = 0;i<n;i++){
        printf("%d index : ",i);
        scanf("%d", &arr[i]);
    }

    printf("Entered array is : ");
    for(int i =0;i<n;i++){
        printf("%d \t", arr[i]);
    }
    printf("\n");

    printf("Reversed array is : ");
    rev(arr,n);
    print(arr,n);

    return 0;
}

void rev(int arr[], int n){
    for(int i=0; i<n/2;i++){
        int firstval = arr[i];
        int secondval = arr[n-i-1];
        arr[i] = secondval;
        arr[n-i-1] = firstval;
    }

}
void print(int arr[], int n){
    for(int i =0;i<n;i++){
        printf("%d \t", arr[i]);
    }
}
