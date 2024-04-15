# Analysis of Sorting Algorithms Runtime
[![Status: Complete](https://img.shields.io/badge/Status-Complete-brightgreen.svg)](https://github.com/ManoelIvisson/execution_time_of_sorting_algorithms/tree/main) [![Language: C++](https://img.shields.io/badge/Language-C%2B%2B-orange.svg)](https://github.com/ManoelIvisson/execution_time_of_sorting_algorithms)
[![Medium Article](https://img.shields.io/badge/Medium-Article-blue.svg)](https://medium.com/@manoel.ivisson/analysis-of-sorting-algorithms-runtime-59625d1b9701)


## Introduction

This repository contains an analysis of the runtime performance of various sorting algorithms. The analysis is conducted through tests with arrays of different sizes, and the results are presented graphically 📊. Additionally, the computational complexity of each algorithm is validated using Big O notation. The sorting algorithms analyzed and compared are:

- Bubble Sort 🛁
- Selection Sort 🎯
- Insertion Sort 🧩
- Shell Sort 🐚
- Quick Sort ⚡
- Merge Sort 🔄

These algorithms vary in performance and usage scenarios, and this analysis aims to provide insights into their efficiency relative to each other.


# Table of Contents
1. [Introduction](#introduction)
2. [What is computational complexity?](#what-is-computational-complexity)
3. [What is Big O notation?](#what-is-big-o-notation)
4. [Sorting Algorithms Comparison]
    - [Bubble Sort Algorithm](#bubble-sort-algorithm)
    - [Selection Sort Algorithm](#selection-sort-algorithm)
    - [Insertion Sort Algorithm](#insertion-sort-algorithm)
    - [Shell Sort Algorithm](#shell-sort-algorithm)
    - [Quick Sort Algorithm](#quick-sort-algorithm)
    - [Merge Sort Algorithm](#merge-sort-algorithm)
5. [Conclusion](#conclusion)
6. [Authors](#authors)



## What is computational complexity?
Computational complexity analyzes an algorithm's efficiency based on its execution time and memory space. Big O notation quantifies this complexity, providing a standardized way to express an algorithm's performance 🧠.

## What is Big O notation?
Big O notation describes the asymptotic growth of an algorithm's execution time. It classifies the worst and best-case scenarios of an algorithm's complexity. The notations range from O(1) (constant time) to O(n!) (factorial).

- Sorting Algorithms Comparison

    In this table, we present a comparison of the complexities of sorting algorithms.

    | Sorter          | Complexity       |
    |-----------------|------------------|
    | Bubble Sort     | O(n^2)           |
    | Selection Sort  | O(n^2)           |
    | Insertion Sort  | O(n^2)           |
    | Shell Sort      | O(n log n)       |
    | Quick Sort      | O(n log n)       |
    | Merge Sort      | O(n log n)       |


# Bubble Sort Algorithm

Bubble Sort is a simple algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

## Algorithm Structure:
The Bubble Sort algorithm iterates over the array, comparing adjacent pairs of elements and swapping them if they are out of order. This process is repeated until no element needs to be swapped.


```cpp
// Algoritmo de ordenação: Bubble Sort
void ordenacaoBubble(vector<int> &vetor) {
    int tamanho = vetor.size();
    // Itera sobre o vetor
    for (int i = 0; i < tamanho - 1; ++i) {
        for (int j = 0; j < tamanho - i - 1; ++j) {
            // Compara elementos adjacentes e os troca se estiverem fora de ordem
            if (vetor[j] > vetor[j + 1]) {
                swap(vetor[j], vetor[j + 1]);
            }
        }
    }
}
```

## How It Works:
- For each element of the array, except the last one:
  - For each pair of adjacent elements:
    - If the current element is greater than the next element, swap them.
  - Repeat until no elements need to be swapped.

# Selection Sort Algorithm

Selection Sort sorts an array by repeatedly finding the minimum element from the unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

## Algorithm Structure:

The Selection Sort algorithm maintains two subarrays in the array: the sorted subarray and the unsorted subarray. Initially, the sorted subarray is empty, and the unsorted subarray is the entire array. The algorithm repeatedly finds the smallest element in the unsorted subarray and moves it to the end of the sorted subarray.

```cpp
// Algoritmo de ordenação: Selection Sort
void ordenacaoSelection(vector<int> &vetor) {
    int tamanho = vetor.size();
    // Itera sobre o vetor
    for (int i = 0; i < tamanho - 1; ++i) {
        int indiceMinimo = i;
        // Encontra o índice do menor elemento restante
        for (int j = i + 1; j < tamanho; ++j) {
            if (vetor[j] < vetor[indiceMinimo]) {
                indiceMinimo = j;
            }
        }
        // Troca o menor elemento encontrado com o primeiro elemento não ordenado
        if (indiceMinimo != i) {
            swap(vetor[indiceMinimo], vetor[i]);
        }
    }
}
```

## How It Works:

For each element in the array except the last one:
- Find the minimum element in the unsorted subarray.
- Swap the minimum element found with the first unsorted element.
- Increase the size of the sorted subarray and decrease the size of the unsorted subarray.

# Insertion Sort Algorithm

Insertion Sort builds the final sorted array one item at a time by repeatedly picking the smallest element from the unsorted part and inserting it into the sorted part.

## Algorithm Structure:

The Insertion Sort algorithm iterates over the array starting from the second element. For each element, it finds its correct position in the sorted subarray by shifting larger elements one position ahead to make room and inserting the element in the correct position.

```cpp
// Algoritmo de ordenação: Insertion Sort
void ordenacaoInsertion(vector<int> &vetor) {
    int tamanho = vetor.size();
    // Itera sobre o vetor a partir do segundo elemento
    for (int i = 1; i < tamanho; ++i) {
        int chave = vetor[i];
        int j = i - 1;
        // Move os elementos maiores que a chave uma posição à frente
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            --j;
        }
        vetor[j + 1] = chave;
    }
}
```

## How It Works:

For each element in the array except the first one:
- Store the current element in a variable called key.
- Initialize a variable j to point to the element before the current element.
- While j is greater than or equal to zero and the element at position j is greater than the key, move the element at position j one position ahead.
- Insert the key into the correct position after the loop ends.

# Shell Sort Algorithm
Shell Sort is an optimization over Insertion Sort that allows the exchange of items that are far apart, resulting in fewer movements of elements.

## Algorithm Structure:

The Shell Sort algorithm is an improvement of the insertion sort algorithm. It divides the array into several smaller subarrays and sorts them individually using the insertion sort method. The key difference is that Shell Sort uses a sequence of gaps (gaps) to determine which elements are compared and swapped.

```cpp
// Algoritmo de ordenação: Shell Sort
void ordenacaoShell(vector<int> &vetor) {
    int tamanho = vetor.size();
    // Define o tamanho do intervalo de comparação
    for (int intervalo = tamanho / 2; intervalo > 0; intervalo /= 2) {
        // Itera sobre o vetor com o intervalo atual
        for (int i = intervalo; i < tamanho; ++i) {
            int temporario = vetor[i];
            int j;
            // Move os elementos que são maiores que o elemento temporário
            // uma posição à frente do local de inserção
            for (j = i; j >= intervalo && vetor[j - intervalo] > temporario; j -= intervalo)
                vetor[j] = vetor[j - intervalo];
            vetor[j] = temporario;
        }
    }
}

// Função wrapper para chamar a ordenação Merge Sort com os parâmetros corretos
void wrapperOrdenacaoMerge(vector<int> &vetor) {
    ordenacaoMerge(vetor, 0, vetor.size() - 1);
}
```

## How It Works:

- Define the size of the initial gap based on the size of the array.
- For each gap, start a loop over the array.
- For each element in the gap, insert the element in the correct position within the gap using insertion sort.
- Repeat the process with a smaller gap until the gap is equal to 1, when Shell Sort becomes a simple insertion sort.

# Quick Sort Algorithm
Quick Sort is a fast sorting algorithm that divides the array into smaller sub-arrays and then recursively sorts them.

## Algorithm Structure:

The Quick Sort algorithm is a divide-and-conquer algorithm. It selects a 'pivot' element from the array and partitions the other elements into two subarrays based on whether they are less than or greater than the pivot. The subarrays are then sorted recursively.

```cpp
// Função recursiva para realizar a ordenação Quick Sort
void ordenacaoQuick(vector<int> &vetor, int inicio, int fim) {
    if (inicio < fim) {
        int indicePivo = particao(vetor, inicio, fim);
        // Chama a função recursivamente para os subvetores antes e depois do pivo
        ordenacaoQuick(vetor, inicio, indicePivo - 1);
        ordenacaoQuick(vetor, indicePivo + 1, fim);
    }
}
```

## How It Works:

1. Choose an element as the pivot (usually the last element of the array).
2. Rearrange the elements of the array so that elements smaller than the pivot are on the left and larger ones are on the right.
3. Recursively apply steps 1 and 2 to the subarrays to the left and right of the pivot, respectively.

# Merge Sort Algorithm
Merge Sort divides the array into two halves, sorts each half separately, and then merges the sorted halves.

## Algorithm Structure:
The Merge Sort algorithm is a divide-and-conquer algorithm. It recursively divides the array in half until each subarray has only one element. Then, it merges the sorted subarrays into a single array.

```cpp
// Função recursiva para realizar a ordenação Merge Sort
void ordenacaoMerge(vector<int> &vetor, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        // Chama a função recursivamente para os subvetores esquerdo e direito
        ordenacaoMerge(vetor, inicio, meio);
        ordenacaoMerge(vetor, meio + 1, fim);
        // Combina os subvetores ordenados
        merge(vetor, inicio, fim, meio);
    }
}
```

## How It Works:
1. Recursively divide the array in half until each subarray has only one element.
2. Merge the sorted subarrays into a single array, ensuring that elements are placed in the correct order.

## Tests Conducted and Results
Tests were conducted using C++ code developed by the authors. Arrays of random elements were sorted, and execution times were measured. Each algorithm was executed multiple times for accuracy.

## Analyzing the Results
The runtime results align with the expected complexities of the algorithms. Bubble, Selection, and Insertion Sort exhibit poorer performance compared to Quick, Merge, and Shell Sort.

## Conclusion
The tests confirm the expected complexities of the sorting algorithms analyzed. Further investigation is needed to refine the implementation of Quick Sort for accurate measurements. 📊

# Authors

| [<img loading="lazy" src="https://avatars.githubusercontent.com/u/121980133?v=4URL_DA_IMAGEM1" width=115><br><sub>Manoel ívisson</sub>](https://github.com/ManoelIvisson) |  [<img loading="lazy" src="https://avatars.githubusercontent.com/u/143226127?v=4" width=115><br><sub>Yago Cortez</sub>](https://github.com/Yagowc1)
| :--: | :--: |

The code used for the tests can be found in the [repository](https://github.com/ManoelIvisson/execution_time_of_sorting_algorithms/tree/main) in the file main.cpp.

