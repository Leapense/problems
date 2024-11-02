# 8722번: Kratki - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8722)


<p>Jaś ma wiele czystych białych kartek papieru. Kartki mają różne wielkości. Jaś postanowił przerobić pewną białą kartkę na kartkę w kratkę – czyli chciałby dorysować pewną liczbę pionowych kresek i pewną liczbę poziomych kresek (równoległych do boków kartki), które podzielą kartkę na małe prostokąty.</p>

<p>Jaś musi jednak zachować odstęp <em>d</em> milimetrów pomiędzy kolejnymi liniami, zaś odległość linii od dowolnego boku musi wynosić co najmniej 1 milimetr. Jaś chciałby wybrać taką kartkę, którą będzie mógł podzielić na jak największą liczbę prostokątów (prostokąty utworzone pomiędzy pierwszą linią a bokiem kartki również liczymy). Ze wszystkich kartek, które będzie mógł podzielić na taką samą liczbę prostokątów, chciałby wybrać kartkę o największej powierzchni. Znajdź tą powierzchnię.</p>



## 입력


<p>Pierwszy wiersz wejścia zawiera dwie liczby całkowite <em>n</em>, <em>d</em> (1 ≤ <em>n</em> ≤ 10<sup>6</sup>, 1 ≤ <em>d</em> ≤ 100), oznaczające odpowiednio liczbę białych kartek Jasia oraz minimalny odstęp pomiędzy liniami. Następnych <em>n</em> wierszy zawiera opisy kolejnych kartek papieru. Każdy z wierszy składa się z dwóch liczb całkowitych <em>a<sub>i</sub></em>, <em>b<sub>i</sub></em> (2 ≤ <em>a<sub>i</sub></em>, <em>b<sub>i</sub></em> ≤ 10<sup>4</sup>), oznaczających odpowiednio długość i szerokość <em>i</em>-tej kartki.</p>



## 출력


<p>Pierwszy i jedyny wiersz wyjścia powinien zawierać jedną liczbę oznaczającą powierzchnię kartki, którą powinien wybrać Jaś.</p>



## 소스코드

[소스코드 보기](Kratki.cpp)