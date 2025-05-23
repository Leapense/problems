# 8587번: Monety - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8587)


<p>Bajtazar jest niezwykle dumny ze swojej kolekcji rzadkich monet. Zbierał je przez wiele lat, dbając o to, by żadne dwie nie były do siebie podobne. Obecnie ma $n$&nbsp;monet ponumerowanych tak, że $i$-ta moneta ma rozmiar dokładnie $i$.</p>

<p>Jako że kolekcja Bajtazara ostatnio się powiększyła, był on zmuszony kupić nowy klaser. Jest w nim dokładnie $n$&nbsp;przegród na monety, każda o określonym rozmiarze. Oczywiście żadnej monety nie można włożyć do zbyt małej przegrody. Nic nie stoi jednak na przeszkodzie, by włożyć ją do przegrody większej.</p>

<p>Bajtazar zastanawia się teraz do których przegród włożyć poszczególne monety. Po sprawdzeniu wielu kombinacji zaintrygowało go również pytanie, na ile sposobów może zapełnić klaser. Ponieważ liczba ta może być bardzo duża, Bajtazarowi wystarczy jej reszta z dzielenia przez $10^9+7$. Napisz program, który zaspokoi jego ciekawość.</p>



## 입력


<p>Pierwszy wiersz standardowego wejścia zawiera jedną liczbę całkowitą: $n$&nbsp;($1 ≤ n ≤ 1\,000\,000$). W następnym wierszu znajduje się $n$&nbsp;liczb całkowitych $a_i$&nbsp;($1 ≤ a_i ≤ n$) pooddzielanych pojedynczymi odstępami. Liczba $a_i$&nbsp;mówi, jaką największą monetę można włożyć do $i$-tej przegrody.</p>



## 출력


<p>Twój program powinien wypisać na standardowe wyjście jedną liczbę całkowitą - resztę z dzielenia liczby sposobów zapełnienia klasera przez $10^9+7$.</p>



## 소스코드

[소스코드 보기](Monety.cpp)