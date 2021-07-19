# Instituto de Computação - Unicamp
# MC458 - Projeto e Análise de Algoritmos I
# Laboratório 01 - Subsequência Consecutiva Máxima

## Peso: 1

## Descrição
Seja x1, x2, ..., xn uma sequência de números reais (não necessariamente positivos). Projete um algoritmo O(n) para encontrar a subsequência xi, xi + 1, ..., xj (de elementos consecutivos) tal que o produto dos números nela seja o máximo dentre todas subsequências consecutivas. O produto da subsequência vazia é definido como 1.

## Entrada
A entrada consiste em 2 linhas. A primeira linha contém um inteiro positivo n, o tamanho da sequência de números reais. A segunda linha contém n números reais, os elementos xi da sequência.
Saída

Como saída o seu programa deverá imprimir o valor do produto da subsequência consecutiva máxima, com 6 casas decimais.

## Exemplos
### Teste 01
Entrada

`5`

`.494 -0.391 0.000 0.927 0.841`

Saída

`1.000000`


### Teste 02
Entrada

`5`

`-0.627 -7.142 0.000 6.278 -4.148`

Saída

`6.278000`


### Teste 03
Entrada

`5`

`.161 1.542 0.000 6.348 1.686`

Saída

`10.702728`


## Observações
O número máximo de submissões é 10;
O seu programa deve estar completamente contido em um único arquivo denominado `lab01.c`;
Para a realização dos testes do SuSy, a compilação dos programas desenvolvidos considerar o comando:`gcc -std=c99 -pedantic -Wall -o lab01 lab01.c`;
Idente corretamente o seu código e inclua comentários no decorrer do seu programa.
