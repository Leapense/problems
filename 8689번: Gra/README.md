# 8689번: Gra - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8689)


<p>Kolejny deszczowy dzień. Paweł i Gaweł znów byli zmuszeni do pozostania w domu. W związku z brakiem zajęć postanowili wymyślić jakąś grę.</p>

<p>Paweł wpadł na genialny pomysł. Na kartce papieru narysował <em>n</em>&nbsp;pól. Na każdym polu znajdowały się dwie liczby - pierwsza z nich była numerem pola (liczba naturalna od 1&nbsp;do&nbsp;<em>n</em>, pola miały parami różne numery), a druga jego wartością (liczba całkowita od -1 000&nbsp;do 1 000). Na polu numer 1&nbsp;umieścił pionek. Zadaniem gracza było wykonywanie kolejnych ruchów, polegających na rzucie sześcienna kostką (z numerami od 1&nbsp;do 6&nbsp;napisanymi na ściankach) oraz przesuwaniu pionka o wskazaną liczbę oczek. Gra kończyła się, kiedy pionek stanął na pole o numerze <em>n</em>. Wynikiem, jaki uzyskał gracz, była suma wartości pól na jakich stał pionek.</p>

<p>Po rozegraniu kilku partii Paweł i Gaweł otrzymali kilka różnych wyników, jednak nie wiedzieli czy któryś z nich był największym możliwym do uzyskania. Zadzwonili więc do Ciebie, utalentowanego informatyka, abyś napisał program, który dla danej planszy obliczy maksymalny możliwy do uzyskania wynik.</p>



## 입력


<p>Pierwszy wiersz standardowego wejścia zawiera jedną liczbę całkowitą <em>n</em>&nbsp;(1 ≤ <em>n</em> ≤ 10<sup>6</sup>) oznaczającą liczbę pól na planszy. Drugi wiersz zawiera&nbsp;<em>n</em>&nbsp;liczb całkowitych <em>w</em><sub>1</sub>,&nbsp;<em>w</em><sub>2</sub>, ...,&nbsp;<em>w<sub>i</sub></em>&nbsp;(-1 000 ≤ <em>w<sub>i</sub></em> ≤ 1 000), gdzie&nbsp;<em>w<sub>i</sub></em>&nbsp;oznacza wartość <em>i</em>-tego pola.</p>



## 출력


<p>Pierwszy i jedyny wiersz standardowego wyjścia powinien zawierać jedną liczbę całkowitą, oznaczającą maksymalny możliwy do uzyskania wynik na danej planszy.</p>



## 소스코드

[소스코드 보기](Gra.cpp)