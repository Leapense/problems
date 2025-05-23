# 15045번: Ginástica - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/15045)


<p>Vinícius gosta muito de se exercitar na academia de ginástica. Ele fez um acordo com o seu treinador para ter programas de exercícios diferentes a cada vez que usar a bicicleta ergométrica. Um programa, na linguagem das academias, é uma sequência de níveis de dificuldade do exercício. Os programas de Vinícius para a bicicleta ergométrica devem ter a mesma duração em minutos e os níveis de dificuldade devem mudar a cada minuto, para um nível imediatamente acima ou um nível imediatamente abaixo. Os níveis de dificuldade não podem estar abaixo de um mínimo e nem acima de um máximo previamente estipulados.</p>

<p>Seu problema é calcular o número de programas diferentes que o treinador pode construir, obedecidas as restrições acima.</p>



## 입력


<p>A entrada consiste de uma única linha que contém três inteiros, T, M, N (1 ≤ T ≤ 50, 1 ≤ M &lt; N ≤ 10<sup>5</sup>) em que T é o número de minutos do exercício, M é o valor mínimo de dificuldade permitido e N é o valor máximo de dificuldade permitido.</p>



## 출력


<p>Seu programa deve produzir uma única linha com um inteiro representando o número de programas diferentes que o treinador pode construir. Como esse número pode ser grande, a resposta deve ser esse número módulo 10<sup>9</sup> + 7.</p>



## 소스코드

[소스코드 보기](Ginástica.py)