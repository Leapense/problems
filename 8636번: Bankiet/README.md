# 8636번: Bankiet - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8636)


<p>W restauracji Utalentowany Miś zaplanowano bankiet dla finalistów OIG. Goście zasiądą przy okrągłych stołach w ściśle określony sposób. Kierownik sali otrzymał listę gości wraz z informacją, kto ma siedzieć z lewej strony każdego z nich. Ile stołów musi przygotować na bankiet?</p>

<p>Opracuj program, który:</p>

<ul>
<li>wczyta ze standardowego wejścia informacje o rozmieszczeniu gości,</li>
<li>obliczy ile stołów trzeba przygotować,</li>
<li>wypisze wynik na standardowe wyjście.</li>
</ul>



## 입력


<p>W pierwszym wierszu zapisano liczbę gości $N$&nbsp;($1 ≤ N ≤ 30\,000$). Goście są ponumerowani kolejnymi liczbami naturalnymi od $1$&nbsp;do $N$. W drugim wierszu zapisano numer gościa siedzącego po lewej stronie pierwszego gościa. w trzecim wierszu zapisano numer gościa siedzącego po lewej stronie drugiego gościa itd. W $i$-tym wierszu zapisano numer gościa siedzącego po lewej stronie ($i-1$)-tego gościa. W $N+1$-szym wierszu zapisano numer gościa siedzącego po lewej stronie $N$-tego gościa.</p>



## 출력


<p>W pierwszym wierszu wypisz liczbę stolików potrzebnych do usadzenia wszystkich gości.</p>



## 소스코드

[소스코드 보기](Main.java)