#include <iostream>

void insertionSort(int arr[], int size){
    for (int j = 1; j<size; j++){
        int key = arr[j];
        int i = j-1;
        while(i>-1 && arr[i]>key){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}

int main() {

    int n;
    std::cout<<"How many elements are there in your array? ";
    std::cin>>n;
    int given_array[n];
    std::cout<<"Enter "<< n <<" digits for your array" << std::endl;
    for(int i=0; i < n; i++){
        std::cin>>given_array[i];
    }

    std::cout<<"Array before sorting:"<<std::endl;
    for(int i=0; i < n; i++){
        std::cout<<given_array[i]<<" ";
    }
    std::cout<<"\n";

    insertionSort(given_array, n);

    std::cout<<"Array after sorting:"<<std::endl;
    for(int i=0; i < n; i++){
        std::cout<<given_array[i]<<" ";
    }  
}