#include <iostream>

void mergeSort (int array[], int size){
    if(size>1){

        int mid = size/2;

        //left array
        int L[mid];
        for (int i =0; i<mid; i++){
            L[i] = array[i];
        }
        int size_L = sizeof(L)/sizeof(int);

        int number_of_ele; //number of elements in right array
        if(size%2 == 0){
            number_of_ele = mid;
        }
        else{
            number_of_ele = mid+1;
        }
        //right array
        int R[number_of_ele];
        for (int i =mid, j = 0; i<size; i++,j++){
            R[j] = array[i];
        }
        
        int size_R = sizeof(R)/sizeof(int);
        
        mergeSort(L, size_L);
        mergeSort(R, size_R);
        
        int i = 0;
        int j = 0;
        int k = 0;

        while(i<size_L && j<size_R){
            if(L[i]<R[j]){
                array[k] = L[i];
                i++;
                k++;
            }
            else{
                array[k] = R[j];
                j++;
                k++;
            }
        }
        while(i< size_L){
            array[k]= L[i];
            i++;
            k++;
        }
        while(j< size_R){
            array[k]= R[j];
            j++;
            k++;
        }
    }
}

int main(){

    int n;
    std::cout<<"How many elements are there in your array? ";
    std::cin>>n;
    int given_array[n];

    std::cout<<"Type in elements of your array: "<<std::endl;
    for(int i =0; i<n; i++){
        std::cin>>given_array[i];
    }

    std::cout<<"Your array before sorting: "<<std::endl;
    for(int i = 0; i<n; i++){
        std::cout<<given_array[i]<<" ";
    }

    std::cout<<"\n";
    mergeSort(given_array, n);

    std::cout<<"Your array after sorting: "<<std::endl;
    for(int i = 0; i<n; i++){
        std::cout<<given_array[i]<<" ";
    }

    return 0;
}