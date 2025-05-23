# 8592번: Tygrysy - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8592)


<p>Bajtockie tygrysy to niezwykłe zwierzęta, a ich nietypowe zwyczaje od zawsze fascynowały zoologów i matematyków. Ustalono niedawno, że dzielą się one na specyficzne gatunki. Tygrysa nazwiemy $k$-tygrysem, jeśli spotkawszy tygrysa mniejszego co najmniej $k$&nbsp;razy od siebie, zaatakuje go i zje, jednak nie odważy się tknąć żadnego większego tygrysa.</p>

<p>W bajtockim ZOO żyje $n$&nbsp;tygrysów. Niestety miejsce w ZOO jest ograniczone, dlatego też dyrektor stwierdził, że trzeba tak przydzielić zwierzęta do wybiegów, aby zająć ich jak najmniej. Oczywiście nie można przy tym dopuścić, by jakikolwiek tygrys został pożarty. Dyrektor ma wyraźne problemy z zakwaterowaniem tygrysów, zwrócił się więc do Ciebie po pomoc.</p>



## 입력


<p>Pierwszy wiersz standardowego wejścia zawiera jedną liczbę całkowitą $n$&nbsp;($1 ≤ n ≤ 500\,000$) - liczbę tygrysów w ZOO. Każdy z kolejnych $n$&nbsp;wierszy zawiera opis jednego tygrysa. Opis taki składa się z dwóch liczb całkowitych $r_i$&nbsp;oraz $k_i$&nbsp;($1 ≤ r_i ≤ 1\,000\,000\,000$, $2 ≤ k_i ≤ 1\,000\,000$), oddzielonych pojedynczym odstępem. Oznaczają one, że $i$-ty tygrys jest $k_i$-tygrysem i ma rozmiar $r_i$.</p>



## 출력


<p>Twój program powinien wypisać na standardowe wyjście dokładnie jedną liczbę całkowitą - najmniejszą liczbę wybiegów, do których można bezpiecznie przydzielić tygrysy.</p>



## 소스코드

[소스코드 보기](Tygrysy.cpp)