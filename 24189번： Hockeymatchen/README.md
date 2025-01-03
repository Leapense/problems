# 24189번: Hockeymatchen - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24189)


<p>Malin älskar att kolla på ishockey. Tyvärr hade hon alldeles för många läxor att göra förra kvällen och kunde inte kolla på direktsändningen av hennes favoritlags senaste match, så nu är hon nyfiken på vad som hände under matchen.</p>

<p>Vanligtvis går hon in på Kvällspapprets sportsidor för att ta reda på det, men tyvärr är en stor del av deras hemsida trasig (de behöver bättre programmerare, lika bra som PO-deltagare) och endast en viss del av statistiken går att utläsa. Malin är främst intresserad av tre olika frågor för varje lag: antalet mål de gjorde, antalet skott deras målvakt räddade, och det totala antalet skott de sköt på motståndarens mål. Givet en del av denna statistik för respektive lag, återkonstruera så mycket av statistiken som möjligt.</p>



## 입력


<p>Den första raden innehåller tre heltal: antalet räddningar det första lagets målvakt gjorde, antalet mål som gjordes av det första laget, samt antalet skott som det första laget sköt på motståndarens mål. Den andra raden innehåller motsvarande information för det andra laget.</p>

<p>Alla tal i statistiken som är kända är mellan $0$ och $10^9$. Om ett tal i statistiken saknas ersätts det med $-1$.</p>

<p>Det är garanterat att det finns minst ett sätt att ersätta alla $-1$ med tal så att den resulterande statistiken är korrekt.</p>



## 출력


<p>Skriv ut statistiken för de två lagen på samma format som i indatan. All saknad statistik som går att unikt bestämma utifrån övriga tal ska skrivas ut istället för $-1$. Om det inte går att unikt bestämma ett visst tal, skriv ut $-1$.</p>



## 소스코드

[소스코드 보기](Hockeymatchen.cpp)