# 10009번: Loteria 2 - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/10009)


<p>Przedsiębiorstwo Bajtocki Lotek specjalizuje się w przeprowadzaniu gier liczbowych i loterii pieniężnych, wśród których największą popularnością cieszy się loteria o nazwie&nbsp;<i>Gra w liczby</i>. Również Bajtazar postanowił spróbować szczęścia w grze.</p>

<p>Kupon do&nbsp;<i>Gry w liczby</i>&nbsp;zawiera <em>n</em>&nbsp;pozycji. Na każdej z nich można zakreślić jedną z liczb 1, ..., <em>k</em>. Poniższy rysunek przedstawia przykładowe wypełnienie kuponu dla <em>n</em> = 10&nbsp;i <em>k</em> = 3:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/3b69b4ce-4cfb-4fcd-8f72-0137bcdb0984/-/preview/" style="width: 451px; height: 140px;"></p>

<p>Losowanie zwycięzców przeprowadza się przy pomocy maszyny losującej, w której znajduje się po <em>n</em>&nbsp;kulek każdego z rodzajów 1, ..., <em>k</em>, co daje łącznie <em>nk</em>&nbsp;kulek. W górnej części maszyny jest rozmieszczonych równomiernie <em>n</em>&nbsp;otworów o średnicy mniejszej niż średnica kulki. W pewnym momencie losowania włączany jest mechanizm pneumatyczny, który powoduje, że do każdego z otworów przyssana zostaje jedna kulka. Wypisując kolejno liczby znajdujące się na wylosowanych kulkach, otrzymuje się ciąg złożony z&nbsp;<em>n</em>&nbsp;liczb, stanowiący wynik losowania. Szczęśliwi właściciele kuponów, na których zakreślono taki właśnie ciąg liczb, zdobywają nagrodę główną - milion bajtalarów do podziału. Na rysunku przedstawiono wynik losowania, przy którym powyższy kupon uzyskałby główną nagrodę.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/795ffc97-8ff6-4586-af9b-84fa416b3ed9/-/preview/" style="width: 545px; height: 88px;"></p>

<p>Bajtazar nabył kupon i zakreślił na nim&nbsp;<em>n</em>&nbsp;liczb. Zanim jednak zdążył złożyć swój kupon w kolekturze, w mediach pojawił się przeciek, że losowanie w&nbsp;<i>Grze w liczby</i>&nbsp;nie jest do końca uczciwe. Zbadano bowiem, że kulki tego samego rodzaju - czyli z tą samą liczbą - odpychają się i nigdy nie ustawią się przy sąsiednich otworach w trakcie losowania (np. układ kulek przedstawiony na powyższym rysunku nie byłby możliwy).</p>

<p>Bajtazar, dowiedziawszy się o tym, postanowił zmienić ciąg <em>n</em>&nbsp;liczb, który wskazał, tak aby żadne dwie kolejne liczby w ciągu nie były takie same. Żeby nie kusić losu, chciałby zmienić możliwie najmniej liczb w swoim ciągu. Pomóż Bajtazarowi ustalić, ile liczb musi zmienić.</p>



## 입력


<p>Pierwszy wiersz wejścia zawiera dwie liczby całkowite <em>n</em>&nbsp;oraz <em>k</em>&nbsp;(2 ≤ <em>n</em>, <em>k</em> ≤ 500 000). Drugi wiersz zawiera ciąg <em>n</em>&nbsp;liczb z zakresu {1, ..., <em>k</em>}. W ciągu tym występuje co najmniej jedna para sąsiadujących ze sobą takich samych liczb.</p>



## 출력


<p>Pierwszy i jedyny wiersz wyjścia powinien zawierać jedną liczbę całkowitą dodatnią - minimalną liczbę liczb w ciągu, które trzeba zmienić, tak aby żadne dwie takie same liczby nie występowały w nim obok siebie.</p>



## 소스코드

[소스코드 보기](Loteria%202.cpp)