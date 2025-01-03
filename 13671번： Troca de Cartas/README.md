# 13671번: Troca de Cartas - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/13671)


<p>Alice e Beatriz colecionam cartas de Pokémon. As cartas são produzidas para um jogo que reproduz a batalha introduzida em um dos mais bem sucedidos jogos de videogame da história, mas Alice e Beatriz são muito pequenas para jogar, e estão interessadas apenas nas cartas propriamente ditas. Para facilitar, vamos considerar que cada carta possui um identificador único, que é um número inteiro.</p>

<p>Cada uma das duas meninas possui um conjunto de cartas e, como a maioria das garotas de sua idade, gostam de trocar entre si as cartas que têm. Elas obviamente não têm interesse emtrocar cartas idênticas, que ambas possuem, e não querem receber cartas repetidas na troca.Além disso, as cartas serão trocadas em uma única operação de troca: Alice dá para Beatriz um sub-conjunto com N cartas distintas e recebe de volta um outro sub-conjunto com N cartas distintas.</p>

<p>As meninas querem saber qual é o número máximo de cartas que podem ser trocadas. Por exemplo, se Alice tem o conjunto de cartas {1, 1, 2, 3, 5, 7, 8, 8, 9, 15} e Beatriz o conjunto {2, 2, 2, 3, 4, 6, 10, 11, 11}, elas podem trocar entre si no máximo quatro cartas. Escreva um programa que, dados os conjuntos de cartas que Alice e Beatriz possuem, determine o número máximo de cartas que podem ser trocadas.</p>



## 입력


<p>A entrada contém vários casos de teste. A primeira linha de um caso de teste contém dois números inteiros A e B, separados por um espaço em branco, indicando respectivamente o número de cartas que Alice e Beatriz possuem (1 ≤ A ≤ 10<sup>4</sup>&nbsp;e 1 ≤ B ≤ 10<sup>4</sup>). A segunda linha contém A números inteiros X<sub>i</sub>, separados entre si por um espaço em branco, cada número indicando uma carta do conjunto de Alice (1 ≤ X<sub>i</sub>&nbsp;≤ 10<sup>5</sup>). A terceira linha contém B números inteiros Y<sub>i</sub>, separados entre si por um espaço em branco, cada número indicando uma carta do conjunto de Beatriz (1 ≤ Y<sub>i&nbsp;</sub>≤ 10<sup>5</sup>). As cartas de Alice e Beatriz são apresentadas em ordem não decrescente.</p>

<p>O final da entrada é indicado por uma linha que contém apenas dois zeros, separados por um espaço em branco.</p>



## 출력


<p>Para cada caso de teste da entrada seu programa deve imprimir uma única linha, contendo um numero inteiro, indicando o número máximo de cartas que Alice e Beatriz podem trocar entre si.</p>



## 소스코드

[소스코드 보기](Troca%20de%20Cartas.py)