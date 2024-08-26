import random


def bubblesort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n - i - 1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j + 1] = arr[j+1], arr[j]
                i+= 1

    return arr


def selectionsort(arr):
    n =len(arr)
    for i in range(n):
        min = i
        for j in range(i, n):
            if arr[min] > arr[j]:
                min = j
        arr[min],arr[i] = arr[i], arr[min]
    return arr

def insertionsort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(i,0,-1):
            if arr[j-1] > arr[j]:
                arr[j-1], arr[j] = arr[j], arr[j-1]
            else:
                break
    return arr

def quicksort(arr):
    if len(arr) <=1:
        return arr
    else:
        pivot = arr[0]
        lower = [x for x in arr[1:] if x <= pivot]
        greater = [x for x in arr[1:] if x > pivot]
        return quicksort(lower) + [pivot] + quicksort(greater)

def merge(left, right):
    i = j = 0
    result = []
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i+=1
        else:
            result.append(right[j])
            j+= 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result

def mergesort(arr):
    if len(arr) <= 1:
        return arr
    else:
        mid = len(arr) // 2
        left = mergesort(arr[:mid])
        right = mergesort(arr[mid:])
        return merge(left, right)


def heapsort(arr):
    pass


# Gerar um vetor com 1000 números aleatórios
# desordenado = [random.randint(0, 100) for _ in range(100)]
desordenado = list(range(1, 101))
random.shuffle(desordenado)
ord_bubble = bubblesort(list(desordenado))
ord_selection = selectionsort(list(desordenado))
ord_insertion = insertionsort(list(desordenado))
ord_quicksort = quicksort(list(desordenado))
ord_mergesort = mergesort(list(desordenado))
ord_heapsort = heapsort(list(desordenado))

print('bubble-sort:    ', ord_bubble)
print('selection-sort: ', ord_selection)
print('insertion-sort: ', ord_insertion )
print('quick-sort:     ', ord_quicksort)
print('mergesort:      ', ord_mergesort)
# print('heap-sort:      ', ord_heapsort)


def comparar_listas_ordenadas(*listas):
    # Compara todas as listas ordenadas
    # print([lista == listas[0] for lista in listas])    return  all([lista == listas[0] for lista in listas])
    return all([lista == listas[0] for lista in listas])


print(comparar_listas_ordenadas(ord_quicksort, ord_mergesort, ord_bubble, ord_selection))
