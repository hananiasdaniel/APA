#include <iostream>
#include <stdio.h>

using namespace std;

void selectionSort(int tam, int *array){ //coloca os menores numeros na frente
	int menor = 0;						
	for(int i=0; i < tam; i++){			    //laço externo
		menor = i;
		for(int j=i+1; j < tam; j++){		//laço interno
			if(array[j] < array[i]){
				menor = j;
			}
		}
		int aux = array[i];
		array[i] = array[menor];
		array[menor] = aux;
	}
}

void insertionSort(int tam, int *array){
	for(int i=1; i < tam; i++){
		int num = array[i];
		int j = i-1;
		while((j >= 0) && (num < array[j])){
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = num;
	}
}

int main(){
	//int array[] = {-5, -2, 0, 4, 7, 15, 51, 77, 87, 92, 101}; //melhor caso
	//int array[] = {101, 92, 87, 77, 51, 15, 7, 4, 0, -2, -5}; //pior caso
	int array[] = {-2, -5, 0, 4, 51, 15, 77, 87, 101, 92}; //caso medio
	int i, j, tamanho=0;

	tamanho = sizeof(array)/sizeof(int);
	puts("");
	cout << "Numeros antes da ordenacao" << endl;
	for(i = 0; i < tamanho; i++){
		cout << "[" << i+1 << "]" << " - " << array[i] << endl; 
	}


	selectionSort(tamanho, array);
	//insertionSort(tamanho, array);

	cout << endl;
	cout << "Numeros ordenados" << endl;
	for(i = 0; i < tamanho; i++){
		cout << "[" << i+1 << "]" << " - " << array[i] << endl;  
	}

	return 0;
}