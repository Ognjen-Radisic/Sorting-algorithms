def insertionSort(list1):
    for j in range(1,len(list1)):
        key = list1[j]
        i = j-1
        while i > -1 and list1[i] > key:
            swap(list1, i , i+1)
            i -= 1
    print(list1)

def swap(A, elem1,elem2):
    A[elem1], A[elem2] = A[elem2], A[elem1]
    return A