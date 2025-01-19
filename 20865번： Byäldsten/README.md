# 20865번: Byäldsten - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/20865)


<p>En gång för länge sedan fanns det en liten by som hette Stackköping. Invånarna i Stackköping hade flera speciella traditioner. En tradition var att den äldsta levande bybon i slutet av varje år måste hålla ett nyårstal. En annan tradition var att högst en ny person fick födas varje år, och enligt vissa experter var det detta som till slut ledde till Stackköpings undergång.</p>

<p>Vid en arkeologisk utgrävning hittades ett dokument som visar vilka årtal samtliga $n$ personer som någonsin levat i Stackköping föddes och dog. Du har kommit över dokumentet, och vill räkna ut hur många nyårstal varje person höll.</p>

<p>Nyårstalet är alltid det absolut sista som händer varje år, så ingen föds eller dör efter nyårstalet som sker samma år. Om ingen är vid liv vid nyår så hålls såklart inget tal alls. Annars hålls alltid ett tal, till och med om det bara är en person vid liv.</p>



## 입력


<p>Den första raden innehåller ett heltal $n$ ($1 \le n \le 10^5$): antalet personer. Följande $n$ rader innehåller två heltal $f_i$ och $d_i$ ($0 \le f_i &lt; d_i \le 10^9$): de årtal person nummer $i$ föddes respektive dog. Alla talen $f_i$ är olika.</p>



## 출력


<p>Skriv ut $n$ rader med ett heltal på varje, där det $i$:te talet är hur många nyårstal den $i$:te personen höll.</p>



## 소스코드

[소스코드 보기](Byäldsten.cpp)