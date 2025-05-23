# 8662번: Szuflady - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8662)


<p>Michał ma w sypialni szafkę z <em>n</em>&nbsp;szufladami. Każda z nich jest wysunięta na pewną długość. Chłopiec chciałby mieć bezpośredni dostęp do każdej szuflady, tak aby nie musiał ich wysuwać za każdym razem.</p>

<p>Bezpośredni dostęp do danej szuflady jest wtedy, gdy każda szuflada powyżej niej jest mniej wysunięta. Michał postanowił, że będzie tylko wsuwał szuflady (czyli zmniejszał długość ich wysunięcia). Zastanawia się, ile minimalnie szuflad musi wsunąć, aby mieć bezpośredni dostęp do wszystkich z nich.</p>

<p>Zakładamy, że do szuflady, której wysunięcie jest równe 0, nie ma dostępu, oraz że wysunięcie szuflady musi być zawsze wartością całkowitą.</p>



## 입력


<p>Pierwszy wiersz standardowego wejścia zawiera jedną liczbę całkowitą <em>n</em>&nbsp;(1 ≤ <em>n</em> ≤ 10<sup>6</sup>), oznaczającą liczbę szuflad. Kolejny wiersz wejścia zawiera <em>n</em>&nbsp;liczb całkowitych <em>a</em><sub>1</sub>, <em>a</em><sub>2</sub>, ..., <em>a<sub>n</sub></em>&nbsp;(1 ≤ <em>a<sub>i</sub></em> ≤ 10<sup>9</sup>), gdzie&nbsp;<em>a<sub>i</sub></em>&nbsp;oznacza długość wysunięcia <em>i</em>-tej (licząc od góry szafki) szuflady.</p>



## 출력


<p>Pierwszy wiersz standardowego wyjścia powinien zawierać jedną liczbę całkowitą, równą minimalnej liczbie szuflad, jakie musi wsunąć Michał, aby był bezpośredni dostęp do wszystkich z nich. Jeśli nie jest to możliwe, wynikiem powinna być liczba -1.</p>



## 소스코드

[소스코드 보기](Szuflady.cpp)