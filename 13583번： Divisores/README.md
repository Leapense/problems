# 13583번: Divisores - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/13583)


<p style="text-align:justify">Pense um número positivo&nbsp;<strong>N</strong>. Agora me diga um divisor&nbsp;<strong>A</strong>&nbsp;de&nbsp;<strong>N</strong>. Agora me dê um outro número&nbsp;<strong>B</strong>que não seja divisor de&nbsp;<strong>N</strong>. Agora um múltiplo&nbsp;<strong>C</strong>. E um não múltiplo&nbsp;<strong>D</strong>. O número que você pensou é...</p>

<p style="text-align:justify">Parece um truque de mágica, mas é matemática! Será que, conhecendo os números&nbsp;<strong>A</strong>,&nbsp;<strong>B</strong>,&nbsp;<strong>C</strong>&nbsp;e&nbsp;<strong>D</strong>, você consegue descobrir qual era o número original&nbsp;<strong>N</strong>? Note que pode existir mais de uma solução!</p>

<p style="text-align:justify">Neste problema, dados os valores de&nbsp;<strong>A</strong>,&nbsp;<strong>B</strong>,&nbsp;<strong>C</strong>&nbsp;e&nbsp;<strong>D</strong>, você deve escrever um programa que determine qual o menor número&nbsp;<strong>N</strong>&nbsp;que pode ter sido pensado ou concluir que não existe um valor possível.</p>



## 입력


<p>A entrada consiste de uma única linha que contém quatro números inteiros A, B, C, e D, como descrito acima</p>

<p>Restrições</p>

<ul>
<li>1 ≤ A,B,C,D ≤ 10<sup>9</sup></li>
</ul>



## 출력


<p>Seu programa deve produzir uma única linha. Caso exista pelo menos um número N para os quais A, B, C e D façam sentido, a linha deve conter o menor N possível. Caso contrário, a linha deve conter -1.</p>



## 소스코드

[소스코드 보기](Divisores.cpp)