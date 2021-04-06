#include <iostream>
#include <algorithm>
#include <ctime>

struct SArray{
    int Arr[30];
    int count = 1;
};

SArray* Random(){
    srand(time(NULL));
    SArray *arr = new SArray();
    int n;
    do{
        n = rand()%31;
    } while(n<5);
    for(int i = 0; i<n; i++){
        arr->Arr[i] = rand()%31;
    }
    arr->count = n;
    return arr;
}

void Sorting(SArray* ptr){
    std::sort(ptr->Arr, ptr->Arr + ptr->count);
}

void PrintArray(SArray arr){
    for(int i=0; i<arr.count; i++){
        printf("%d  ",arr.Arr[i]);
    }
    printf("\n");
}

int main(){
    SArray *Array = Random();
    printf("Original Array\n");
    PrintArray(*Array);
    Sorting(Array);
    printf("\nSorted Array\n");
    PrintArray(*Array);
    std::cout << "\nEnd of program\n\n";
    delete(Array);
    return 0;
}