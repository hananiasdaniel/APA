#include <iostream>

using namespace std;

void swap(int *a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
}

int partition(int *array, int left, int right){
	int pivo = array[right];
	int i = left - 1;


	for(int j = left; j < right; j++){
		if(array[j] <= pivo){
			i = i + 1;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[right]);
	return (i + 1);

}

void quickSort(int *array, int left, int right){
	if(left < right){
		int pivo = partition(array, left, right);
		quickSort(array, left, pivo - 1);
		quickSort(array, pivo + 1, right);
	}
}

void merge(int array[], int inicio, int meio, int fim){
	int i, j, k;
	int n1 = meio - inicio + 1;
	int n2 = fim - meio; 

	int Aux1[n1];
	int Aux2[n2];

	for(i = 0; i < n1; i++){
		Aux1[i] = array[inicio+i];
	}
	for(j = 0; j < n2; j++){
		Aux2[j] = array[meio+1+j]; 
	}

	i=0;
	j=0;
	k=inicio;

	while(i < n1 && j < n2){
		if(Aux1[i] <= Aux2[j]){
			array[k] = Aux1[i];
			i++;
		}
		else{
			array[k] = Aux2[j];
			j++;
		}
		k++;
	}

	while(i < n1){
		array[k] = Aux1[i];
		i++;
		k++;
	}

	while(j < n2){
		array[k] < Aux2[j];
		j++;
		k++;
	}
}

void mergeSort(int array[], int inicio, int fim){
    if(inicio < fim){
        int meio = inicio+(fim-inicio)/2;
        mergeSort(array, inicio, meio);
        mergeSort(array, meio + 1, fim);
        merge(array, inicio, meio, fim);
    }

}

int main(){
	//int a[] = {10, 4, 2, 7, 6};
	int a[] = {-1, 70, 34, -8, 66, 10, 9, 3, 45, 51};
	//int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	//int a[] = {8, 7, 6, 5, 4, 3};
    int i;
    int tamanho = sizeof(a)/sizeof(a[0]);
    cout << "numeros antes da ordenacao" << endl;
    for(i = 0; i < tamanho; i++){
        cout << "[" << i+1 << "] - " << a[i] << endl;
    }

    //quickSort(a, 0, tamanho-1);
    mergeSort(a, 0, tamanho - 1);
    cout << endl;
    cout << "numeros ordenados" << endl;
    for(int i = 0; i < tamanho; i++){
        cout << "[" << i+1 << "] - " << a[i] << endl;
    }

    return 0;
}