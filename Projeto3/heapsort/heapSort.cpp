#include <iostream>

using namespace std;

void maxHeapify(int array[], int i, int comprimento){
	int sonLeft = 2*i + 1; //filho da esquerda
	int sonRight = 2*i + 2; //filho da direita
	int maior = i; //o maior valor eh a raiz

	if(sonLeft < comprimento && array[sonLeft] > array[maior]){
		maior = sonLeft;
	}

	if(sonRight < comprimento && array[sonRight] > array[maior]){
		maior = sonRight;
	}

	if(maior != i){
		swap(array[i], array[maior]);
		maxHeapify(array, maior, comprimento);
	}

}

void buildMaxHeap(int array[], int comprimento){
	for(int i = ((comprimento/2)-1); i >= 0; i--){
		maxHeapify(array, i, comprimento);
	}
}

void heapSort(int array[], int comprimento){
	buildMaxHeap(array, comprimento);
	for(int i = comprimento - 1; i >= 0; i--){
		swap(array[0], array[i]);
		maxHeapify(array, 0, comprimento);
	}
}

int main(){
	int array[] = {2, 4, 15, 7, 1, 13, 0, 10, 5};
	int comprimento = sizeof(array)/sizeof(int); //numero total de elementos do array

	cout << comprimento << endl;
	heapSort(array, comprimento);
	cout << "Array ordenado" << endl;
	for(int i=comprimento-1; i >= 0; i--){
		cout << array[i] << endl;
	}

	return 0;
}