#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>


using namespace std;

//W = capacidade maxima da mochila
//wt = vetor de peso de cada elemento
//val = vetor de valor(beneficios)
//n = numero de elementos

int mochila(int W, int wt[], int val[], int n){
	int memo[n+1][W+1];

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= W; j++){
			if(i == 0 || j == 0){
				memo[i][j] = 0;
			}
			else if(wt[i - 1] <= j){
					memo[i][j] = max(memo[i - 1][j], val[i - 1] + memo[i - 1][j - wt[i - 1]]);
				}else{
					memo[i][j] = memo[i - 1][j];
				}
		}
	}

	return memo[n][W];
}

int main(){
	int ordem[1000000];
	string test;
	cout << "Arquivo de teste: ";
	cin >> test;
	ifstream in(test.c_str());
	char num[10];
	int fim = 0;
	while(!in.eof()){ 
		in >> num;
		ordem[fim] = atoi(num);
		fim++;
	}

	int n_ele = ordem[0];
	int max = ordem[1];
	int pesos[n_ele];
	int valor[n_ele];
	int count = 0;

	for(int i = 2; i < 2*n_ele+2; i = i + 2){
		pesos[count] = ordem[i];
		valor[count] = ordem[i+1];
		count++;
	}

	cout << "Valor Otimo: " << mochila(max, pesos, valor, n_ele) << endl;
	return 0;

}