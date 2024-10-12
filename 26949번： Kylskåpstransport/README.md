# 26949번: Kylskåpstransport - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26949)


<p>En fabrik som tillverkar kylskåp ska leverera ett större parti med $n, 1 \le n \le 1000$ kylar till en stormarknad. Till sitt förfogande har fabriken två bilar.</p>

<ul>
<li>bil $A$ kostar $p_a$ kr/resa, $500 \le p_a \le 2000$ och kan lasta $k_a, 10 \le k_a \le 50$, kylskåp åt gången.</li>
<li>bil $B$ kostar $p_b$ kr/resa, $500 \le p_b \le 2000$ och kan lasta $k_b, 10 \le k_b \le 50$, kylskåp åt gången.</li>
</ul>

<p>Din uppgift är nu att skriva ett program som tar emot uppgifter om de fem variablerna ovan och som med hjälp av dessa bestämmer hur många turer varje bil ska köra för att minimera <em>den totala transportkostnaden</em>.</p>



## 입력


<p>Indata består av de fem heltalen $p_a$, $k_a$, $p_b$, $k_b$ och $n$ på en rad, separerade med ett blanksteg.</p>



## 출력


<p>Utdatan ska bestå av tre heltal: antalet turer bil $A$ ska köra, antalet turer bil $B$ ska köra, samt den totala kostnaden i kronor. För alla givna testfall garanteras det att svaret är unikt.</p>



## 소스코드

[소스코드 보기](Kylskåpstransport.py)