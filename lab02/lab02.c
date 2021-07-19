#include <stdio.h>

int main() {
	//variavel de entrada
	int n; //inteiro que determina o número de elementos da sequência
	scanf("%i", &n); //scan do n
	
	//demais variaveis
	int seq_in[n]; //array que conterá os elementos da sequência de entrada
	int seq_aux[n]; //array auxiliar para as comparações de ordenação
	int seq_out[n]; //array que conterá os elementos da sequência de saída
	int i; //auxiliar de loop
	int max_num = 0; //maior número que o vetor pode ter com base em n
	int aux = 0; //auxiliar de comparação
	int base = 1; //variavel que determinara a base da divisão para pegarmos os caracteres
	int maior = 0; //auxiliar para encontrar o maior elemento (inicializada com 0)
	
	for (i = 0; i < n; i++){
		scanf("%i", &seq_in[i]);
	}
	
	max_num = n*n - 1; //atualizamos o maior número possível com base em n
	
	for (i = 0; i < n; i++){
		if (seq_in[i] > max_num || seq_in[i] < 0){ //se o maior número do vetor for maior que o limite estipulado e negativo => fim
			aux ++;
		}
	}
	
	if (aux > 0) { //se houve algum número que não passa nas condições de inicialização
		return 0; //finalizamos o programa
	}
	else{ //se não houver, podemos então caminhar para o cerne do nosso problema
		//primeiramente, vamos encontrar o maior elemento da nossa sequência
		for(i = 0; i < n; i++) {
			if(seq_in[i] > maior) {
				maior = seq_in[i];
			}
		}
		
		while((maior/base) > 0) {
			for (i = 0; i < n; i++) {
				seq_aux[i] = 0;
			}
			for(i = 0; i < n; i++) {
				seq_aux[(seq_in[i] / base) % 10]++;
			}
			for(i = 1; i < n; i++) {
				seq_aux[i] += seq_aux[i-1];
			}
			for(i = (n - 1); i >= 0; i--) {
				seq_out[--seq_aux[(seq_in[i] / base) % 10]] = seq_in[i];
			}
			for(i = 0; i < n; i++) {
				seq_in[i] = seq_out[i];
			}
			base *= 10;
		}
	}
	
	//printamos o resultado
	for (i = 0; i < n - 1; i++){
		printf("%i ", seq_out[i]);
	}
	printf("%i\n", seq_out[n-1]);
	
	return(0);
}