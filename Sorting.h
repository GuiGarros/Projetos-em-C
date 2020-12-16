#ifndef __SORTING_H_
#define __SORTING_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void *EXG(int Vetor[], int i, int j);

void EXG_Heap(int *a, int *b);

void *Shuffle(int Vetor[], int len);

void random_numbers(int Vetor[], int len);

void verify(int Vetor[], int len);

void verify(int Vetor[], int len);

void Instantaneo(long int timeMetodo);

void *SelectionSort(int Vetor[], int len);

void *InsertionSort(int Vetor[], int len);

void *merge(int Vetor[], int lo, int mid, int hi);

void *MergeSort(int Vetor[], int lo, int hi);

void *partition(int Vetor[], int lo, int hi);

void *QuickSort(int Vetor[], int len);

int less(int a, int b);

void *sink(int Vetor[], int k, int N);

void delMax(int *v, int N);

void *HeapSort(int Vetor[], int N);

#endif
