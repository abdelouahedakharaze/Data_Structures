/**
 * this is for ways of initializing arrays in C
 * 
 * 
 * 
*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr0[]={1,2,3,4,5,5};
    int arr1[3];     /* for this one the elements will have garbage values , 
                        if the result is 0s its just a coincidence   */
    int arr2[4]={2}; /* when you set only some elements the rest is set to 0s */


    int length0=sizeof(arr0)/sizeof(arr0[0]);
    int length1=sizeof(arr1)/sizeof(arr1[0]);
    int length2=sizeof(arr2)/sizeof(arr2[0]);


    printf("\n%s\n","printing the values of array arr0 ::");
    for (int i = 0; i < length0; i++) {
        printf("%d ", arr0[i]);
    }

    printf("\n%s\n","printing the values of array arr1 ::");
    for (int i = 0; i < length1; i++) {
        printf("%d ", arr1[i]);
    }

    printf("\n%s\n","printing the values of array arr2 ::");
    for (int i = 0; i < length2; i++) {
        printf("%d ", arr2[i]);
    }

    

    return 0;
}
