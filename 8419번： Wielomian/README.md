# 8419번: Wielomian - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8419)


<p>Dla danego wielomianu <em>W</em>&nbsp;oraz zadanej liczby <em>x</em>, wyznacz trzy ostatnie cyfry (cyfrę setek, dziesiątek i jedności) wartości wyrażenia <em>W</em>(<em>x</em>).</p>

<p>Napisz program, który:</p>

<ul>
<li>wczyta opis wielomianu <em>W</em>&nbsp;oraz liczbę <em>x</em>,</li>
<li>wyznaczy trzy ostatnie cyfry wartości wyrażenia <em>W</em>(<em>x</em>),</li>
<li>wypisze wynik.</li>
</ul>



## 입력


<p>Pierwszy wiersz zawiera dwie liczby całkowite <em>s</em>&nbsp;(1 ≤ <em>s</em> ≤ 20,000) oraz <em>x</em>&nbsp;(-1,000,000 ≤ <em>x</em> ≤ 1,000,000). Drugi wiersz zawiera <em>s</em>&nbsp;liczb całkowitych <em>w</em><sub>1</sub>,&nbsp;<em>w</em><sub>2</sub>, ...,&nbsp;<em>w<sub>s</sub></em>&nbsp;(-1,000,000 ≤ <em>w<sub>k</sub></em> ≤ 1,000,000), pooddzielanych pojedynczymi odstępami. Liczby te, to kolejne współczynniki wielomianu: <em>W</em>(<em>x</em>) = <em>w</em><sub>1</sub><em>x</em><sup><em>s</em>-1</sup> + <em>w</em><sub>2</sub><em>x</em><sup><em>s</em>-2</sup> + .. + <em>w</em><sub><em>s</em>-1</sub><em>x</em> + <em>w<sub>s</sub></em>.</p>



## 출력


<p>Twój program powinien wypisać słowo zbudowane z trzech ostatnich cyfr liczby równej wartości wyrażenia <em>W</em>(<em>x</em>), w kolejności od cyfry setek do cyfry jedności.</p>



## 소스코드

[소스코드 보기](Wielomian.cpp)