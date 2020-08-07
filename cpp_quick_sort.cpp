#include <iostream>

void quickSort(int array[], int size);
void realQuickSort(int array[], int begin, int end);
int partition(int array[], int lowest, int highest);
void swap(int arr[], int first, int second);

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
    quickSort(given_array,n);

    std::cout<<"Your array after sorting: "<<std::endl;
    for(int i = 0; i<n; i++){
        std::cout<<given_array[i]<<" ";
    }

    return 0;
}

void quickSort(int array[], int size){
    realQuickSort(array, 0, size-1);
}

void realQuickSort(int array[], int begin, int end){
    if (begin < end){
        int pivot = partition(array, begin, end);
        realQuickSort(array,begin,(pivot-1));
        realQuickSort(array,(pivot+1), end);
    }
}

int partition(int array[], int lowest, int highest){
    int pivot_value= array[highest];
    swap(array,lowest,highest);
    /*int temp= array[lowest];
    array[lowest] = array[highest];
    array[highest] = temp;*/
    int border = lowest;

    for(int i=lowest+1; i<highest+1; i++){
        if(array[i]< pivot_value){
            border++;
            swap(array,i,border);
            /*int temp1 = array[i];
            array[i]=array[border];
            array[border] = temp1;*/
        }
    }
    swap(array, lowest, border);
    /*int temp2 = array[border];
    array[border] = array[lowest];
    array[lowest] = temp2;*/
    return border;
}

void swap(int arr[], int first, int second){
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}