# 8673번: Krany - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8673)


<p>W pewnym zakładzie przemysłowym znajduje się <em>n</em>&nbsp;kranów, z których może lać się woda. Przy każdym kranie znajduje się wskaźnik, oznaczający temperaturę wody, dla danego kranu. Woda leje się z kranu, jeśli ustawiona temperatura wody jest większa od zera. Woda z każdego kranu leje się z równą prędkością i trafia do wspólnego zbiornika.</p>

<p>Znając temperatury przy każdym kranie, chcielibyśmy wiedzieć, ile minimalnie kranów musimy zakręcić, aby temperatura wody w zbiorniku była równa lub większa od wartości <em>w</em>.</p>

<p>Zakładamy, że temperatura w zbiorniku jest średnią temperaturą wszystkich kranów, z których leci woda. Temperatura się nie zmienia na skutek oddziaływania temperatury powietrza.</p>



## 입력


<p>Pierwszy wiersz standardowego wejścia zawiera dwie liczby całkowite <em>n</em>, <em>w</em>&nbsp;(1 ≤ i ≤ 10<sup>6</sup>, 1 ≤ <em>w</em> ≤ 100), oznaczające odpowiednio liczbę kranów oraz wartość temperatury, którą chcemy uzyskać. W kolejnym wierszu znajduje się <em>n</em>&nbsp;liczb całkowitych <em>t</em><sub>1</sub>, <em>t</em><sub>2</sub>, ..., <em>t<sub>n</sub></em>&nbsp;(-100 ≤ <em>t<sub>i</sub></em> ≤ 100), gdzie&nbsp;<em>t<sub>i</sub></em>&nbsp;oznacza temperaturę wody, ustawioną dla <em>i</em>-tego kranu.</p>



## 출력


<p>W pierwszym i jedynym wierszu wyjścia powinna znajdować się jedna liczba całkowita, równa minimalnej liczbie kranów, jakie powinniśmy zakręcić, aby temperatura w zbiorniku wynosiła co najmniej <em>w</em>&nbsp;stopni lub jedno słowo 'NIE', jeśli nie jest możliwe uzyskanie takiej temperatury.</p>



## 소스코드

[소스코드 보기](Krany.cpp)