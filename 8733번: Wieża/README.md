# 8733번: Wieża - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8733)


<p>W Bajtocji wybudowano wysoką wieżę. Wejście na wieżę składa się z <em>n</em>&nbsp;schodków, a każdy schodek ma pewną wysokość.</p>

<p>Bajtocką wieżę chce odwiedzić <em>m</em>&nbsp;mieszkańców. Każda z osób posiada pewien wzrost, który pomaga w pokonywaniu kolejnych schodków. Aby mieszkaniec Bajtocji mógł wejść na pewien schodek, to musi być wyższy od wysokości schodka. Jeśli pewien schodek jest nie do przejścia przez mieszkańca, to zatrzymuje się on w danym miejscu na wieży - wyżej nie będzie mógł wejść.</p>

<p>Znając wysokości kolejnych schodków i osób zwiedzających wieżę chcielibyśmy wiedzieć, w którym miejscu zatrzyma się każdy mieszkaniec Bajtocji.</p>



## 입력


<p>Pierwszy wiersz wejścia zawiera dwie liczby całkowite <em>n</em>, <em>m</em>&nbsp;(1 ≤ <em>n</em>, <em>m</em>&nbsp;≤ 500 000), oznaczające odpowiednio liczbę schodków prowadzących na wieżę oraz liczbę mieszkańców chcących odwiedzić wieżę. Kolejny wiersz zawiera <em>n</em>&nbsp;liczb całkowitych <em>a</em><sub>1</sub>, <em>a</em><sub>2</sub>, ..., <em>a<sub>n</sub></em>&nbsp;(1 ≤ <em>a<sub>i</sub></em> ≤ 10<sup>9</sup>), gdzie&nbsp;<em>a<sub>i</sub></em>&nbsp;oznacza wysokość <em>i</em>-tego schodka. Pierwszy schodek znajduje się na samym dole wieży, a każdy kolejny wyżej od poprzednich. Następny wiersz wejścia zawiera <em>m</em>&nbsp;liczb całkowitych&nbsp;<em>b</em><sub>1</sub>, <em>b</em><sub>2</sub>, ..., <em>b<sub>m</sub></em>&nbsp;(1 ≤ <em>b<sub>i</sub></em> ≤ 10<sup>9</sup>), gdzie&nbsp;<em>b<sub>i</sub></em>&nbsp;oznacza wzrost <em>i</em>-tego mieszkańca.</p>



## 출력


<p>Pierwszy i jedyny wiersz wyjścia powinien zawierać <em>m</em>&nbsp;liczb całkowitych&nbsp;<em>w</em><sub>1</sub>, <em>w</em><sub>2</sub>, ..., <em>w<sub>m</sub></em>, gdzie <em>w<sub>i</sub></em>&nbsp;oznacza maksymalny numer schodka, na który może wejść <em>i</em>-ty mieszkaniec Bajocji.</p>



## 소스코드

[소스코드 보기](Wieża.cpp)