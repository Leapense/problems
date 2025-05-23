# 30655번: Pique Esconde - <img src="https://static.solved.ac/tier_small/3.svg" style="height:20px" /> Bronze III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30655)


<p>João, que gosta de informática, procura pensar em como seria um programa para automatizar tudo que ele faz no seu dia a dia. Maria o desafiou a fazer um programa que fosse útil de algum jeito para quando eles brincarem de pique esconde.</p>

<p>João teve uma ideia muito boa de um programa, mas como ele ainda está em suas primeiras aulas de informática, ainda não descobriu como implementar essa ideia. Assim, você deve ajudá-lo. A ideia de João é numerar as crianças participando da brincadeira de 1 a n. O programa recebe como entrada o número total de crianças e também o número correspondente 'a criança que está procurando os demais participantes. Depois, o programa recebe uma lista com n − 2 números identificando as crianças que já foram encontradas e deve responder qual a criança que está faltando.</p>

<p>Sua tarefa é implementar esse programa e ajudar João a mostrar para Maria que a informática pode ser útil até nas mais simples tarefas.</p>



## 입력


<p>A entrada é composta por diferentes casos de teste. A primeira linha de cada caso de teste contém n, o número de crianças, e m, o número da criança que está procurando as demais, 2 ≤ n ≤ 1000 e 1 ≤ m ≤ n. As n − 2 linhas seguintes contém um inteiro cada representando as crianças que já foram encontradas.</p>

<p>A entrada termina com n = m = 0. Essa linha não deve ser processada.</p>



## 출력


<p>Para cada caso de teste, seu programa deve imprimir uma linha contendo o número da criança que ainda não foi encontrada.</p>



## 소스코드

[소스코드 보기](Pique%20Esconde.cpp)