def quicksort(A):
    realquicksort(A, 0, len(A)-1)

def realquicksort(A, low, high):
    if low < high:
        pivot = partition(A, low, high)
        realquicksort(A,low,pivot-1)
        realquicksort(A, pivot+1, high)

def partition(A, lowest, highest):
    pivot_index = get_pivot(A, lowest, highest)
    pivot_value = A[pivot_index]

    #pomeramo pivot na prvo mesto(pivot value gets index ZERO)
    #kada ovo uradimo vrednost sa indeksom(pivot_index) nam vise nije bitna
    A[pivot_index], A[lowest] = A[lowest], A[pivot_index]
    border = lowest

    for i in range(lowest+1,highest+1):
        if A[i] < pivot_value:
            border +=1
            A[i], A[border] = A[border], A[i]
    A[lowest], A[border] = A[border], A[lowest]
    #border je poslednji element nakon pomeranja koji je manji od pivota
    #kad se for loop zavrsi samo zarotiramo VREDNOSTI sa pivot i border INDEKSIMA

    #vratimo index border gde se sada nalazi pivot i radimo quicksort, levo i desno od njega
    return(border)

#uzimamo prvu, poslednju i centralnu vrednost liste i vracamo index one vrednosti koja je srednja
def get_pivot(A, low, high):
    mid= (low+high) // 2
    pivot = high

    if A[low] <= A[mid] and A[low] >= A[high]:
        pivot = low
    elif A[mid] <= A[high] and A[mid] >= A[low]:
        pivot = mid
    return pivot