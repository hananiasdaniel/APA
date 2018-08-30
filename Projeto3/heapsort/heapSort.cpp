#include <iostream>

using namespace std;

void maxHeapify(int array[], int comprimento, int i){
	int maior = i; //o maior valor eh a raiz
	int sonLeft = 2*i + 1; //filho da esquerda
	int sonRight = 2*i + 2; //filho da direita
	int aux = 0;


	if(sonLeft < comprimento && array[sonLeft] > array[maior]){
		maior = sonLeft;
	}

	if(sonRight < comprimento && array[sonRight] > array[maior]){
		maior = sonRight;
	}

	if(maior != i){
		swap(array[i], array[maior]);
		maxHeapify(array, i, maior);
	}

}

void buildMaxHeap(int array[], int comprimento){
	for(int i = (comprimento/2) - 1; i >= 0; i--){
		maxHeapify(array, comprimento, i);
	}
}

void heapSort(int array[], int comprimento){
	int aux = 0;
	buildMaxHeap(array, comprimento);
	for(int i = comprimento - 1; i >= 0; i--){
		swap(array[0], array[i]);
		maxHeapify(array, i, 0);
	}
}

void Print(int array[], int n){
	for(int i = 0; i < n; i++)
		cout << array[i] << " ";
		cout << endl;
}

int main(){
	int array[] = {2, 4, 15, 7, 1, 13};
	int comprimento = sizeof(array)/sizeof(array[0]); //numero total de elementos do array
	//comprimento = (comprimento/2) - 1;
	//cout << comprimento << endl;
	heapSort(array, comprimento);
	cout << "Array ordenado" << endl;
	

	Print(array, comprimento);

	//return 0;
}