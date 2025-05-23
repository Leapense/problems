# 20841번: Skolavslutningen - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/20841)


<p>Skolledningen har stött på ett problem med den kommande skolavslutningen, ett problem som de hoppas att du kan hjälpa dem att lösa. Under skolavslutningen kommer eleverna stå uppställda i $N$ rader med $M$ elever i varje. Ledningen vill att avslutningen ska vara så färgglad som möjligt och kommer därför att dela ut hattar i olika färger till eleverna.</p>

<p>För att uppställningen ska se fin ut är det viktigt att alla elever i samma kolumn har samma hattfärg. För att ingen ska känna sig utanför är det också viktigt att alla elever i samma klass har samma hattfärg. Rad och kolumn för varje elev är redan bestämt, men inte hattfärg. Ledningen behöver din hjälp med att tilldela hattfärger till eleverna så att avslutningen blir så färgglad som möjligt.</p>

<p>Skriv ett program som, givet hur eleverna kommer vara uppställda på avslutningen, beräknar det maximala antalet unika hattfärger som kan tilldelas eleverna.</p>



## 입력


<p>Den första raden innehåller tre heltal $N$, $M$ ($1 \leq N, M \leq 700$) och $K$ ($1 \leq K \leq 26$) -- antalet rader, antalet kolumner och antalet klasser.</p>

<p>De följande $N$ raderna har $M$ tecken i varje och beskriver hur eleverna kommer vara uppställda på avslutningen. Tecknet på rad $i$, kolumn $j$ är en stor bokstav mellan <code>A</code> och den $K$:e bokstaven i alfabetet -- den klass som eleven på rad $i$, kolumn $j$ går i. Det finns garanterat minst en elev från varje klass.</p>



## 출력


<p>Skriv ut ett heltal -- det maximala antalet unika hattfärger som kan tilldelas eleverna så att alla elever i samma kolumn, respektive samma klass, har samma hattfärg.</p>



## 소스코드

[소스코드 보기](Skolavslutningen.cpp)