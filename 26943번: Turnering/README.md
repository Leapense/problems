# 26943번: Turnering - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26943)


<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/6bb1553b-b271-4e14-86f7-3013477fe85b/-/preview/"></p>

<p>Om man vill ordna t.ex. en bordshockeyturnering där alla möter alla kan man använda sig av ett praktiskt rotationsschema som kallas round robin. Det går till så att spelarna i den första omgången möter varandra enligt figuren ovan (vi antar att antalet spelare $n$ är jämnt). När första omgången är klar förflyttar sig alla spelare ett steg medurs, utom spelaren i det nedre vänstra hörnet som hoppas över (därav namnet, man förflyttar sig "runt" Robin, d.v.s. den sista spelaren). Med detta rotationsschema är man garanterad att alla har mött alla precis en gång efter $n-1$ omgångar.</p>

<p>Din uppgift är att skriva ett program som skriver ut vilka spelare som ska möta vilka en viss omgång.</p>



## 입력


<p>Indata består av två heltal: antal spelare i turneringen (ett jämnt tal $n$ mellan $2$ och $100$) och omgången (mellan $1$ och $n-1$).</p>



## 출력


<p>Programmet ska skriva ut $n/2$ rader som beskriver vilka som möter vilka, där varje rad är på formatet <code>a-b</code>. Ordningen på matcherna spelar ingen roll.</p>



## 소스코드

[소스코드 보기](Turnering.py)