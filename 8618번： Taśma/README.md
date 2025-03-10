# 8618번: Taśma - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8618)


<p>Jaś przypadkowo znalazł w domu bardzo długą taśmę. Bez chwili namysłu napisał na taśmie pewien ciąg liczb całkowitych dodatnich. Teraz chciałby znaleźć w tym ciągu dwie najdalej od siebie położone różne liczby. Zakładamy, że odległość między sąsiednimi liczbami to 1, między liczbami posiadającymi wspólnego sąsiada to 2 itd.</p>



## 입력


<p>Pierwszy wiersz standardowego wejścia zawiera jedną liczbę całkowitą $m$&nbsp;($1 ≤ m ≤ 10$), oznaczającą liczbę przypadków testowych do rozważenia. Każdy przypadek testowy jest opisany w dwóch wierszach. Pierwszy z nich zawiera jedną liczbę całkowitą $n$&nbsp;($1 ≤ n ≤ 100\,000$), oznaczającą długość sekwencji liczb zapisanej przez Jasia na taśmie. Drugi wiersz zawiera ciąg $n$&nbsp;liczb całkowitych $a_i$&nbsp;($1 ≤ a_i ≤ 1\,000\,000\,000$), pooddzielanych pojedynczymi odstępami.</p>



## 출력


<p>Twój program powinien wypisać na standardowe wyjście $m$&nbsp;wierszy, po jednym dla każdego przypadku testowego. Jeżeli w ciągu odpowiadającym $i$-temu przypadkowi testowemu nie ma żadnej pary różnych liczb, to $i$-ty wiersz powinien zawierać jedno słowo "<code>BRAK</code>". W przeciwnym przypadku w $i$-tym wierszu powinna znajdować się jedna liczba całkowita, równa odległości między najdalszą parą różnych liczb w ciągu.</p>



## 소스코드

[소스코드 보기](Taśma.cpp)