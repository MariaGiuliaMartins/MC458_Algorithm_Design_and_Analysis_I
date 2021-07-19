#include <stdio.h>
//gcc -std=c99 -pedantic -Wall -o lab04 lab04.c

//struct para carregar as informacoes de entrada
typedef struct{
	int num; //numero da tarefa
	int indice; //indice da tarefa
}tarefa;


//função merge usada no mergeSort
void merge(tarefa vetor[], int inicio, int meio, int fim){
	int com1 = inicio;
	int com2 = meio + 1;
	int comAux = 0;
	tarefa vetAux[fim - inicio + 1];
	
	while((com1 <= meio) && (com2 <= fim)){
		if(vetor[com1].num <= vetor[com2].num){
			vetAux[comAux].num = vetor[com1].num;
			vetAux[comAux].indice = vetor[com1].indice;
			com1++;
		}else{
			vetAux[comAux].num = vetor[com2].num;
			vetAux[comAux].indice = vetor[com2].indice;
			com2++;
		}
		comAux++;
	}
	
	while(com1 <= meio){ //se houver elementos na primeira metade
		vetAux[comAux].num = vetor[com1].num;
		vetAux[comAux].indice = vetor[com1].indice;
		comAux++;
		com1++;
	}
	
	while(com2 <= fim){ //se houver elementos na 2a metade
		vetAux[comAux].num = vetor[com2].num;
		vetAux[comAux].indice = vetor[com2].indice;
		comAux++;
		com2++;
	}
	
	for(comAux = inicio; comAux <= fim; comAux++){ //movendo os elementos para o vetor original
		vetor[comAux].num = vetAux[comAux - inicio].num;
		vetor[comAux].indice = vetAux[comAux - inicio].indice;
	}
}


//função mergesort para mantermos nosso programa em nlogn
void mergeSort(tarefa vetor[], int inicio, int fim){
	if(inicio < fim){
		int meio = (inicio + fim) / 2;
		mergeSort(vetor, inicio, meio);
		mergeSort(vetor, meio + 1, fim);
		merge(vetor, inicio, meio, fim);
	}
}

int main(){
	//variavel de entrada
	int n = 0; //inteiro que representa o tamanho do conjunto de tarefas
	scanf("%i", &n); //scan do n
	
	//demais variaveis
	tarefa seq_in[n]; //sequencia de entrada dos dados
	int i = 0; //auxiliar de loop
	int saida[n]; //vetor de saida auxiliar que conterá os valores referentes a c_i do enunciado
	int aux; //auxiliar de soma para calculo final
	int soma = 0; //variavel que conterá a saída desejada
	
	//vamos zerar todos os elementos de saida[n]
	for(i = 0; i < n; i++){
		saida[i] = 0;
	}
	
	//agora vamos preencher nossa struct de tarefas
	for(i = 0; i < n; i++){
		scanf("%i", &seq_in[i].num);
		seq_in[i].indice = i+1;
	}
		
	//ordenando nossa struct de tarefas
	mergeSort(seq_in, 0, n-1);
	
	//vamos preencher o vetor de saida
	saida[0] = seq_in[0].num;
	for(i = 0; i < n-1; i++){
		//até o último elemento, somamos um com a soma anterior
		aux = seq_in[i+1].num;
		saida[i+1] = saida[i] + aux;
	}
	
	//realizamos então a soma de todos os elementos do vetor saida
	soma = saida[0];
	for(i = 1; i < n; i++){
		soma = soma + saida[i];
	}
	
	printf("%i\n", soma); //printamos a saída
	
	//print dos indices da saída
	for(i = 0; i < n-1; i++){
		printf("%i ", seq_in[i].indice);
	}
	printf("%i\n", seq_in[n-1].indice);
	
	return 0;
}