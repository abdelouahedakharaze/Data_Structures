/**
 * this is for ways of initializing arrays in C
 * 
 * 
 * 
*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int arr[4]={2}; /* when you set only some elements the rest is set to 0s */
    int length=sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
