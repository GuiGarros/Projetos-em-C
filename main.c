#include "Sorting.h"

/*
	Guilherme Marques Garros Brait		RA: 19264266
	Lucas Grass Beraldo					RA: 19246925
	Ramon Gazoni Larceda				RA: 20062162
	Renato Barba dos Santos				RA: 19246529
*/

int main()
{
	srand(time(NULL));

	// Variaveis

	struct timeval start, end;

	int N = 10, N_Heap;
	time_t timeSelection, timeInsertion, timeMerge, timeQuick, timeHeap;

	printf("\e[H\e[2J");
	printf("\nN\t\tSelectionSort\t\t\tInsertionSort\t\t\tMergeSort\t\t\tQuickSort\t\t\tHeapSort\n");
	printf("\t\t     (ms)\t\t\t      (ms)\t\t\t   (ms)\t\t\t\t   (ms)\t\t\t\t   (ms)\n");
	
	// Loop para o calculo e o print dos tempos de cada metodo de ordenacao

	for (int i = 0; i < 4; i++)
	{
		int *Vetor;
		Vetor = (int *)malloc(N * sizeof(int));

		random_numbers(Vetor, N);

		printf("\n%d", N);

		// Selection Sort

		gettimeofday(&start, NULL);
		SelectionSort(Vetor, N);
		gettimeofday(&end, NULL);
		verify(Vetor, N);
		timeSelection = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)) / 1000;

		Instantaneo(timeSelection);

		Shuffle(Vetor, N);

		// Insertion Sort

		gettimeofday(&start, NULL);
		InsertionSort(Vetor, N);
		gettimeofday(&end, NULL);
		verify(Vetor, N);
		timeInsertion = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)) / 1000;

		Instantaneo(timeInsertion);

		Shuffle(Vetor, N);

		// Merge Sort

		gettimeofday(&start, NULL);
		MergeSort(Vetor, 0, N - 1);
		gettimeofday(&end, NULL);
		verify(Vetor, N);
		timeMerge = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)) / 1000;

		Instantaneo(timeMerge);

		Shuffle(Vetor, N);

		// Quick Sort

		gettimeofday(&start, NULL);
		QuickSort(Vetor, N);
		gettimeofday(&end, NULL);
		verify(Vetor, N);
		timeQuick = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)) / 1000;

		Instantaneo(timeQuick);

		// Heap Sort

		free(Vetor);
		Vetor = (int *)malloc((N + 1) * sizeof(int));
		N_Heap = N + 1;
		Vetor[N_Heap] = Vetor[0];

		gettimeofday(&start, NULL);
		HeapSort(Vetor, N_Heap);
		gettimeofday(&end, NULL);
		delMax(Vetor, N);
		timeHeap = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)) / 1000;

		Instantaneo(timeHeap);

		N = N * 10;
	}

	printf("\n\n\n\n");
	return 0;
}