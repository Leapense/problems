# 8805번: Konduktor - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8805)


<p>Konduktor Konrad zajmuje się sprawdzaniem biletów w pociągach jednej z dwóch dużych spółek kolejowych.</p>

<p>W jego pociągu znajduje się&nbsp;<strong>N</strong>&nbsp;przedziałów ponumerowanych od 1 do&nbsp;<strong>N</strong>. Konrad odwiedza je, zaczynając od przedziału z numerem 1, w następującej kolejności: 1, 2, ... ,&nbsp;<strong>N</strong>-1,&nbsp;<strong>N</strong>,&nbsp;<strong>N</strong>-1, ... , 2, 1, 2, itd.&nbsp;</p>

<p>Znając&nbsp;<strong>N</strong>&nbsp;- liczbę przedziałów w pociągu oraz&nbsp;<strong>K</strong>&nbsp;- liczbę odwiedzonych przedziałów, oblicz ile razy Konrad odwiedził każdy z przedziałów.</p>



## 입력


<p>W pierwszej linii znajduje się jedna liczba naturalna&nbsp;<strong>Z</strong>&nbsp;( 1 &lt;=&nbsp;<strong>Z</strong>&nbsp;&lt;= 10 ) oznaczająca liczbę zestawów testowych. Następnie opisywane są kolejne zestawy.</p>

<p>W pierwszej i jedynej linii zestawu znajduje się para liczb naturalnych&nbsp;<strong>N</strong>&nbsp;( 1 &lt;=&nbsp;<strong>N</strong>&nbsp;&lt;= 10<sup>6</sup>&nbsp;)&nbsp;i&nbsp;<strong>K</strong>&nbsp;( 1 &lt;=&nbsp;<strong>K</strong>&nbsp;&lt;= 10<sup>9</sup>&nbsp;).</p>



## 출력


<p>Dla każdego zestawu testowego w osobnej linii należy wypisać oddzielone spacjami&nbsp;<strong>N</strong>&nbsp;liczb&nbsp;<strong>A</strong><sub><strong>i</strong></sub>, gdzie&nbsp;<strong>A</strong><sub><strong>i</strong></sub>&nbsp;oznacza liczbę kontroli biletów w&nbsp;<strong>i</strong>-tym przedziale.&nbsp;</p>



## 소스코드

[소스코드 보기](Konduktor.cpp)