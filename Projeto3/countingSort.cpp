#include <iostream>

using namespace std;

void countingSort(int in[], int out[], int intervalo, int tam){
	int aux[intervalo+1];
	for(int i = 0; i < intervalo+1; i++){
		aux[i] = 0;
	}

	for(int j = 0; j < tam; j++){
		aux[in[j]] = (aux[in[j]] + 1);
	}

	for(int i = 1; i <= intervalo+1; i++){
		aux[i] = (aux[i] + aux[i - 1]);
	}

	for(int j = tam-1; j >= 0; j--){
		out[aux[in[j]] - 1] = in[j];
		aux[in[j]] = (aux[in[j]] - 1);
	}
}

int main(){
	int test[] = {4, 6, 8, 9, 10, 1, 2, 3, 3, 7};
	int tamanho = sizeof(test)/sizeof(int);
	int saida[tamanho] = {0};

	countingSort(test, saida, 10, tamanho);
	cout << "COUNTING SORT" << endl;
	cout << "numeros ordenados" << endl;
	for(int i = 0; i < tamanho; i++){
		cout << "[" << i << "] - " << saida[i] << endl;
	}


	return 0;
}