#include <iostream>

using namespace std;

void Print(int array[], int n){
	for(int i = 0; i < n; i++)
		cout << array[i] << " ";
		cout << endl;
}

void maxHeapify(int array[], int comprimento, int i){
	//cout << comprimento << endl;
	//cout << i << endl;
	int maior = i; //o maior valor eh a raiz
	int sonLeft = 2*i + 1; //filho da esquerda
	int sonRight = 2*i + 2; //filho da direita



	if(sonLeft < comprimento && array[sonLeft] > array[maior]){
		maior = sonLeft;
	}

	if(sonRight < comprimento && array[sonRight] > array[maior]){
		maior = sonRight;
	}

	if(maior != i){
		swap(array[i], array[maior]);
		maxHeapify(array, comprimento, maior);

	}

}

void buildMaxHeap(int array[], int comprimento){
	for(int i = (comprimento/2) - 1; i >= 0; i--){
		maxHeapify(array, comprimento, i);
	}
	//Print(array, comprimento);
}

void heapSort(int array[], int comprimento){
	buildMaxHeap(array, comprimento);
	for(int i = comprimento - 1; i >= 0; i--){
		swap(array[0], array[i]);
		maxHeapify(array, i, 0);
	}
}

int main(){
	int array[] = {3, 7, 1, 12, 5, 9, 10, 2, 0, 3, 4, 11, 6};
	int comprimento = sizeof(array)/sizeof(array[0]); //numero total de elementos do array
	//comprimento = (comprimento/2) - 1;
	//cout << comprimento << endl;
	heapSort(array, comprimento);
	cout << "Array ordenado" << endl;


	Print(array, comprimento);

	//return 0;
}