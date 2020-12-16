#include "Sorting.h"

/* Auxiliar Functions */

/* Exchange para os metodos de ordenacao */

    void *EXG(int Vetor[], int i, int j)
{
    int aux;

    aux = Vetor[i];
    Vetor[i] = Vetor[j];
    Vetor[j] = aux;

    return Vetor;
}

/* Exchange para o Heap Sort */

void EXG_Heap(int *a, int *b)
{
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

/* Funcao para embaralhar o vetor */

void *Shuffle(int Vetor[], int len)
{
    int random;

    for (int i = 0; i < len; i++)
    {

        if (i != 0)
        {
            random = rand() % i;
            EXG(Vetor, i, random);
        }
    }
    return Vetor;
}

/* Funcao para gerar numeros aleatorios para o vetor */

void random_numbers(int Vetor[], int len)
{
    for (int i = 0; i < len; i++)
        Vetor[i] = rand() % 1000001;
}

/* Funcao para verificar se o vetor esta ordenado */

void verify(int Vetor[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        if (Vetor[i] > Vetor[i + 1])
        {
            printf("O vetor nao esta ordenado");
            break;
        }
    }
}

/* Funcao para verificar se o Heap Sort esta ordenado */

void verify_heap(int Vetor[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        if (Vetor[i] < Vetor[i + 1])
        {
            printf("O vetor nao esta ordenado");
            break;
        }
    }
}

/* Funcao para estetica do print */

void Instantaneo(long int timeMetodo)
{
	if (timeMetodo < 1)
		printf("\t\tInstantaneo");
	else 
        printf("\t\t%8ld", timeMetodo);
	printf("\t");
}



/* Selection Sort */
void *SelectionSort(int Vetor[], int len)
{
    int lo;

    for (int i = 0; i < len; i++)
    {
        lo = i;

        for (int j = i; j < len; j++)
            if (Vetor[lo] > Vetor[j])
                lo = j;

        EXG(Vetor, i, lo);
    }
    return Vetor;
}


/* Insertion Sort */
void *InsertionSort(int Vetor[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int pos = i;
        for (int j = i - 1; j >= 0; j--)
        {

            if (Vetor[pos] < Vetor[j])
            {
                Vetor = EXG(Vetor, pos, j);
                pos = j;
            }
        }
    }
    return Vetor;
}


/* Merge Sort */
void *merge(int Vetor[], int lo, int mid, int hi)
{
    int i = lo, j = mid + 1, k = 0;
    int *tempVetor = (int *)malloc((hi - lo + 1)* sizeof(int));

    while ((i <= mid) && (j <= hi))
        if (Vetor[i] < Vetor[j])
            tempVetor[k++] = Vetor[i++];
        else
            tempVetor[k++] = Vetor[j++];

    while (j <= hi)
        tempVetor[k++] = Vetor[j++];

    while (i <= mid)
        tempVetor[k++] = Vetor[i++];

    for (i = 0, k = lo; k <= hi; i++, k++)
        Vetor[k] = tempVetor[i];

    free(tempVetor);
    return Vetor;
}

void *MergeSort(int Vetor[], int lo, int hi)
{
    if (lo < hi)
    {
        int mid = (lo + hi) / 2;
        MergeSort(Vetor, lo, mid);
        MergeSort(Vetor, mid + 1, hi);

        if (Vetor[mid] > Vetor[mid + 1])
            merge(Vetor, lo, mid, hi);
    }
    return Vetor;
}


/* Quick Sort */
void *partition(int Vetor[], int lo, int hi)
{
    if (hi <= lo)
    {
        return Vetor;
    }

    int i = lo, j = hi, key = lo;

    while (i <= j)
    {
        if (Vetor[i] <= Vetor[key])
            i++;
        else if (Vetor[j] > Vetor[key])
            j--;
        else
            EXG(Vetor, i, j);
    }

    EXG(Vetor, j, key);

    partition(Vetor, lo, j - 1);
    partition(Vetor, j + 1, hi);

    return Vetor;
}

void *QuickSort(int Vetor[], int len)
{
    Shuffle(Vetor, len);

    partition(Vetor, 0, len - 1);
    return Vetor;
}


/* Heap Sort */
int less(int a, int b)
{
    return a <= b;
}

void *sink(int Vetor[], int k, int N)
{
    int *j;
    int i;

    if (2 * k == N && N % 2 == 0)
    {
        if (less(Vetor[k], Vetor[k * 2]))
        {
            EXG_Heap(&Vetor[k], &Vetor[k * 2]);
        }
    }
    else
    {
        if (less(Vetor[k * 2], Vetor[k * 2 + 1]))
        {
            j = &Vetor[k * 2 + 1];
            i = 2 * k + 1;
        }
        else
        {
            j = &Vetor[k * 2];
            i = 2 * k;
        }

        if (less(Vetor[k], *j))
        {
            EXG_Heap(&Vetor[k], j);
            if (2 * i <= N)
                sink(Vetor, i, N);
        }
    }
    return Vetor;
}

void delMax(int *v, int N) 
{

	int i;
	int vet[N];
	for(i=0; i<N; i++)
    {
		vet[i]=v[1];
		v[1] = v[N-i];
		sink(v, 1, N-i);
	}
	
	verify_heap(vet,N);
}

void *HeapSort(int Vetor[], int N)
{
    N = N - 1;
    int k = N / 2;

    while (k >= 1)
        sink(Vetor, k--, N);
    return Vetor;
}