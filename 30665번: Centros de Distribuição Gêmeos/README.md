# 30665번: Centros de Distribuição Gêmeos - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30665)


<p>A Empresa Rural Internacional (ERI) está buscando expandir seus negócios. Para isso, ela precisa encontrar uma nova cidade para instalar um novo centro de distribuição. Entretanto, como algum centro pode ficar inoperante, como aconteceu no último verão devido 'as chuvas, ela quer se certificar de que não ficará sem distribuir seus produtos caso alguma cidade fique incomunicável. Para isso, ao invés de instalar seu novo centro de distribuição em uma única cidade, ela escolherá duas cidades vizinhas, de forma a garantir que haja redundância, caso algum problema ocorra com uma das localidades.</p>

<p>Simonal, diretor de logística da ERI, conhece bem a região e seus possíveis clientes. Dada uma cidade, Simonal sabe a área de alcance de sua empresa, ou seja, as cidades alcançadas caso um novo centro de distribuição seja instalado nessa cidade. Naturalmente, a área de alcance de uma cidade sempre inclui ela mesma. A fim de que a redundância desejada seja satisfeita, as duas cidades candidatas a receber o novo centro de distribuição devem ter a mesma área de alcance.</p>

<p>Você, estagiário buscando um aumento de salário para comprar a mais nova expansão do seu MMORPG favorito, quer agradar o seu chefe, Dionísio Cabeço Fechantes, também conhecido como Dudu, e, usando os dados obtidos com Simonal, quer mostrar o quão bom você é em computação e contar de quantas formas distintas estas cidades podem ser escolhidas.</p>



## 입력


<p>A entrada é composta por diferentes casos de teste. A primeira linha de cada caso de teste contém n e m, n ≤ 1000 e m ≤ n(n−1)/2, onde n é o número de cidades da região. A seguir, m linhas, contendo dois inteiros distintos a e b cada, 1 ≤ a, b ≤ n, indicando que a faz parte da área de alcance de b e vice-versa.</p>

<p>A entrada termina com n = m = 0. Essa linha não deve ser processada.</p>



## 출력


<p>Para cada caso de teste, seu programa deve imprimir uma linha contendo o número de diferentes pares de cidades que podem receber novos centros.</p>



## 소스코드

[소스코드 보기](Centros%20de%20Distribuição%20Gêmeos.cpp)