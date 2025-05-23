# 24197번: Tabbtabbande - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24197)


<p>När man arbetar med en webbläsare så händer det ofta att man har väldigt många tabbar (flikar) öppna samtidigt.</p>

<p>Ett vanligt sätt att navigera mellan dem är att ctrl-tabba för att gå igenom dem i den ordning som de ligger. Det går även att ctrl-shift-tabba för att gå igenom dem i omvänd ordning. Tabbarna kan tänkas ligga cykliskt, så det går att ctrl-tabba från sista till första, och crtl-shift-tabba från första till sista tabben.&nbsp;</p>

<p>Just nu har du <em>n</em> tabbar öppna, numrerade från $1$ till $n$ i den ordning som de ligger. Från början har du tabb $1$ markerad. Givet en sekvens som beskriver vilka tabbar som ska användas och i vilken ordning, beräkna hur många gånger du minst måste trycka på tabb-tangenten för att besöka dem?</p>



## 입력


<p>Först kommer en rad med två positiva heltal mindre än $10$, $n$ och $m$. Sedan följer en ny rad med $m$ heltal som alla är mellan $1$ och $n$, inklusive. Två intilliggande tal kommer alltid vara olika.</p>



## 출력


<p>Skriv ut ett heltal, minsta antalet gånger tabbknappen måste tryckas på.</p>



## 소스코드

[소스코드 보기](Tabbtabbande.py)