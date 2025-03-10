# 8581번: Pieczątki - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8581)


<p>Bituś od dłuższego czasu bawił się, zamalowując pisakiem niektóre pola na papierze w kratkę. Uzyskane w ten sposób pikselowe obrazki wieszał nad łóżkiem i zapowiedział, że nie przestanie, póki będzie tam jeszcze wolne miejsce.</p>

<p>Jego mama uważała, że zabiera to chłopcu zbyt dużo czasu, więc postanowiła mu pomóc - przyniosła ze strychu pieczątki, którymi kiedyś sama się bawiła. Każda taka pieczątka, po przyciśnięciu do kartki, "zamalowywała" jakiś, zawsze taki sam, wzór z pól. Bitusiowi pieczątki spodobały się, ale nie jest pewien, czy wystarczą do wykonania jego nowego obrazka.</p>

<p>Wiedząc, jak ma wyglądać nowy obrazek oraz znając wzory odciskane przez pieczątki, określ, czy Bituś może go ukończyć bez używania pisaka. Bituś nie obraca pieczątek (patrz drugi test przykładowy). Pamiętaj, że obrazek nie zajmuje całej kartki, ale żadne pole, które nie należy do obrazka, nie powinno być zamalowane (patrz pierwsze dwa testy przykładowe).</p>



## 입력


<p>W pierwszym wierwszu standardowego wejścia znajdują się wymiary obrazka - dwie liczby: $W$&nbsp;i $S$&nbsp;($1 ≤ W, S ≤ 100$).</p>

<p>W kolejnych $W$&nbsp;wierszach znajduje się po $S$&nbsp;znaków "<code>#</code>" lub "<code>.</code>", informujących odpowiednio, że dane pole musi być odciśnięte co najmniej raz albo że musi być pozostawione puste.</p>

<p>W następnym wierszu znajduje się jedna liczba $P$&nbsp;($1 ≤ P ≤ 20$), oznaczająca liczbę pieczątek do dyspozycji Bitusia.</p>

<p>Opis każdej pieczątki jest podobny do opisu obrazka - składa się z dwóch liczb: $R$&nbsp;i $C$&nbsp;($1 ≤ R, C ≤ 10$), oznaczających wymiary pieczątki oraz $R$&nbsp;wierszy po $C$&nbsp;znaków "<code>#</code>" lub "<code>.</code>", oznaczających, że przyłożenie pieczątki w odpowiednim miejscu zamaluje wszystkie pola znajdujące się pod znakami "<code>#</code>", nie zmieniając stanu tych położonych pod znakami "<code>.</code>".</p>



## 출력


<p>Na standardowe wyjście należy wypisać jedno słowo - "<code>TAK</code>", jeśli podane pieczątki wystarczą do namalowania obrazka, "<code>NIE</code>", w przeciwnym wypadku.</p>



## 소스코드

[소스코드 보기](Pieczątki.cpp)