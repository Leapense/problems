# 13653번: Estacionamento - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/13653)


<p>Um estacionamento utiliza um terreno em que os veículos têm que ser guardados em fila única, um atrás do outro. A tarifa tem o valor fixo de R\$ 10,00 por veiculo estacionado, cobrada na entrada, independente de seu porte e tempo de permanência. Como o estacionamento é muito concorrido, nem todos os veículos que chegam ao estacionamento conseguem lugar para estacionar.<br>
<br>
Quando um veículo chega ao estacionamento, o atendente primeiro determina se há vaga para esse veículo. Para isso, ele percorre a pé o estacionamento, do início ao fim, procurando um espaço que esteja vago e tenha comprimento maior ou igual ao comprimento do veículo. Para economizar seu tempo e energia, o atendente escolhe o primeiro espaço adequado que encontrar; isto é, o espaço mais próximo do início.<br>
<br>
Uma vez encontrada a vaga para o veículo, o atendente volta para a entrada do estacionamento, pega o veículo e o estaciona no começo do espaço encontrado. Se o atendente não encontrar um espaço adequado, o veículo não entra no estacionamento e a tarifa não é cobrada. Depois de estacionado, o veículo não é movido até o momento em que sai do estacionamento.<br>
<br>
O dono do estacionamento está preocupado em saber se os atendentes têm cobrado corretamente a tarifa dos veículos estacionados e pediu para você escrever um programa que, dada a lista de chegadas e saídas de veículos no estacionamento, determina o faturamento total esperado.</p>



## 입력


<p>A entrada é composta por diversos casos de teste. A primeira linha de um caso de teste contém dois números inteiros C (1 ≤ C ≤ 1000) e N (1 ≤ N ≤ 10000) que indicam respectivamente o comprimento em metros do estacionamento e o número total de eventos ocorridos (chegadas e saídas de veículos). Cada uma das N linhas seguintes descreve uma chegada ou saída. Para uma chegada de veículo, a linha contém a letra 'C', seguida de dois inteiros P (1000 ≤ P ≤ 9999) e Q (1 ≤ Q ≤ 1000), todos separados por um espaço em branco. P indica a placa do veículo e Q o seu comprimento. Para uma saída de veículo, a linha contém a letra 'S' seguida de um inteiro P , separados por um espaço em branco, onde P indica a placa do veículo. As ações são dadas na ordem cronológica, ou seja, na ordem em que acontecem.</p>

<p>No início de cada caso de teste o estacionamento está vazio. No arquivo de entrada, um veículo sai do estacionamento somente se está realmente estacionado, e a placa de um veículo que chega ao estacionamento nunca é igual a placa de um veículo já estacionado.</p>



## 출력


<p>Para cada caso de teste seu programa deve imprimir uma linha contendo um número inteiro representando o faturamento do estacionamento, em reais.</p>



## 소스코드

[소스코드 보기](Estacionamento.py)