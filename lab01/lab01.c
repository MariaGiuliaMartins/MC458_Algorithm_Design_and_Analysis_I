#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

int main()
{
    //variáveis
    int n;                             //inteiro que determina o número de elementos da sequência
    double seq[MAX_SIZE];              //array que conterá os elementos da sequência
    int i = 0;                         //auxiliar de loop
    int aux1 = 0;                      //auxiliar de comparação
    double aux2 = 0;                   //auxiliar de comparação

    scanf("%i", &n);

    for(i = 0; i < n; i ++){
        scanf("%lf", &seq[i]);
    }

                                       		     							   ////////////////////////////////////////////
    for(i = 0; i < n; i ++){                     //                                        //
        if(abs(seq[i]) >= 0 && abs(seq[i]) <= 1){//se todos os elementos forem entre -1 e 1//
            aux1 ++;		                  //                                        //
        }			                  //                                        //
    }                                            //                                        //
                                                 //                                        //
    if(aux1 == n){                               //                                        //
        printf("1.000000\n");                    ////////////////////////////////////////////
    }
    else{                              //se eles não forem entre 0 e 1
        double maiorProd = seq[0];     //inicialmente, nosso maior produto é o primeiro
        double maior = seq[0];         //inicialmente, nosso maior elemento é o primeiro
        double menor = seq[0];         //inicialmente, nosso menor elemento é o primeiro

        for(i = 1; i < n; i ++){
            if(seq[i] < 0){            //se o nosso número da sequência for negativo
                aux2 = maior;          /////////////////////////////
                maior = menor;         //trocamos maior com menor///
                menor = aux2;          /////////////////////////////
            }

            if(seq[i] > maior*seq[i]){ ///////////////
                maior = seq[i];        //           //
            }                          //atualizamos//
            else{                      //  o maior  //
                maior = maior*seq[i];  //           //
            }                          ///////////////

            if(seq[i] < menor*seq[i]){ ///////////////
                menor = seq[i];        //           //
            }                          //atualizamos//
            else{                      //  o menor  //
                menor = menor*seq[i];  //           //
            }                          ///////////////

            if(maiorProd < maior){     /////////////////
                maiorProd = maior;     //maior produto//
            }                          /////////////////

        }
        
        if (abs(maiorProd) >= 0 && abs(maiorProd) <= 1) { //se o maior produto for entre -1 e 1
            printf("1.000000\n");
        }
        else{
            printf("%lf\n", maiorProd);    //imprimimos o resultado
        }
    }
    return 0;
}
