# Instituto de Computação - Unicamp
# MC458 - Projeto e Análise de Algoritmos I
# Laboratório 04 - Escalonamento para minimizar o tempo total de conclusão

## Peso: 1

## Descrição
Suponha que você receba um conjunto de tarefas S = {a1, a2, ..., an}, onde a tarefa ai requer pi unidades de tempo de processamento para ser concluída, uma vez iniciada. Você tem um computador para executar essas tarefas, e o computador pode executar apenas uma tarefa por vez. Seja ci o tempo de conclusão da tarefa ai, ou seja, o tempo em que a tarefa ai conclui o processamento. Seu objetivo é minimizar o tempo total de conclusão, ou seja, minimizar c1 + c2 + ... + cn.

Projete e implemente um algoritmo O(n log n) que escalona as tarefas de forma a minimizar o tempo total de conclusão. Cada tarefa deve ser executada de forma não preemptiva, ou seja, uma vez que a tarefa ai é iniciada, ela deve ser executada continuamente por pi unidades de tempo.

## Entrada
A entrada consiste em 2 linhas.
A primeira linha contém um inteiro positivo n < 1000, o tamanho do conjunto de tarefas.
A segunda linha contém n número inteiros, o tempo de processamento pi < 1000 de cada tarefa ai.

## Saída
Como saída o seu programa deverá imprimir 2 linhas.
A primeira linha deve conter um número inteiro, representando o tempo total de conclusão das tarefas no escalonamento ótimo.
A segunda linha deve conter n números inteiros, representando os índices das tarefas na ordem em que são executadas no escalonamento ótimo.
Em caso de empate, dê preferência para as tarefas de menor índice.

## Exemplos
### Teste 01
Entrada

`3`

`3 4 4`

Saída

`21`
`1 2 3`

Neste exemplo, temos 3 tarefas, a1, a2 e a3, com p1 = 3, p2 = 4 e p3 = 4.
Em um escalonamento ótimo, primeiro executamos a tarefa a1, depois a tarefa a2 e, por fim, a tarefa a3.
Então c1 = p1 = 3, c2 = c1 + p2 = 3 + 4 = 7, c3 = c2 + p3 = 7 + 4 = 11, e o tempo total de conclusão é c1 + c2 + c3 = 3 + 7 + 11 = 21.
Note que obteriamos um outro escalonamento ótimo executando a tarefa a3 antes da tarefa a2, porém damos preferência para a tarefa a2, que possui menor índice.

### Teste 02
Entrada

`5`

`5 5 4 8 6`

Saída

`75`
`3 1 2 5 4`

Neste exemplo, temos 5 tarefas, a1, a2, a3, a4 e a5, com p1 = 5, p2 = 5, p3 = 4, p4 = 8 e p5 = 6.
Em um escalonamento ótimo, primeiro executamos a tarefa a3, depois a tarefa a1, depois a tarefa a2, depois a tarefa a5 e, por fim, a tarefa a4.
Então c3 = p3 = 4, c1 = c3 + p1 = 4 + 5 = 9, c2 = c1 + p2 = 9 + 5 = 14, c5 = c2 + p5 = 14 + 6 = 20, c4 = c5 + p4 = 20 + 8 = 28, e o tempo total de conclusão é c1 + c2 + c3 + c4 + c5 = 9 + 14 + 4 + 28 + 20 = 75.
Note que obteriamos um outro escalonamento ótimo executando a tarefa a2 antes da tarefa a1, porém damos preferência para a tarefa a1, que possui menor índice.

## Observações
O número máximo de submissões é 10;
O seu programa deve estar completamente contido em um único arquivo denominado `lab04.c`;
Para a realização dos testes do SuSy, a compilação dos programas desenvolvidos considerar o comando:`gcc -std=c99 -pedantic -Wall -o lab04 lab04.c`;
Idente corretamente o seu código e inclua comentários no decorrer do seu programa.
