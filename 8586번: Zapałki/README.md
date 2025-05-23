# 8586번: Zapałki - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8586)


<p>Bajtek bawi się zapałkami. Na jednym z końców zapałki znajduje się główka pokryta masą ułatwiającą zapłon. Bajtek ułożył zapałki w linii prostej jedna obok drugiej, w taki sposób, że każdy koniec zapałki sąsiaduje z końcem pewnej innej zapałki, oprócz dwóch skrajnych zapałek, które sąsiadują tylko jednym końcem.</p>

<p align="center"><img alt="" src="https://upload.acmicpc.net/2d74a4f6-095f-4807-aba6-ceefb9679a08/-/preview/"></p>

<p align="center">Przykładowe ułożenie zapałek.</p>

<p>Bajtek chciałby podpalić pierwszą zapałkę (skrajną z lewej) tak aby wszystkie zapałki spaliły się. Pierwszą zapałkę zapali on przy użyciu zapalniczki, może więc to zrobić bez względu na jej ułożenie. Natomiast między kolejnymi zapałkami ogień przeniesie się tylko, jeśli co najmniej jedna z tych zapałek w miejscu połączenia będzie zwrócona główką. Zastanawiamy się, ile minimalnie zapałek musimy odwrócić, aby wszystkie zapałki spaliły się, jeśli podpalimy pierwszą zapałkę.</p>



## 입력


<p>Pierwszy wiersz standardowego wejścia zawiera jedną liczbę całkowitą $n$&nbsp;($1 ≤ n ≤ 1\,000\,000$) oznaczającą liczbę zapałek Bajtka. Drugi wiersz opisuje ułożenie kolejnych zapałek - zawiera ciąg $n$&nbsp;liczb całkowitych $x_1, x_2, \dots , x_n$, przy czym $x_i$&nbsp;oznacza zwrot $i$-tej zapałki w ciągu: $0$&nbsp;jeśli główka zapałki znajduje się z lewej strony, zaś $1$&nbsp;jeśli główka zapałki znajduje się z prawej strony.</p>



## 출력


<p>Pierwszy i jedyny wiersz standardowego wyjścia powinien zawierać jedną liczbę całkowitą równą minimalnej liczbie zapałek, jakie należy odwrócić.</p>



## 소스코드

[소스코드 보기](Zapałki.cpp)