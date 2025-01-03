# 20840번: Volleybollmatchen - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/20840)


<p>Du har blivit inhyrd av PO-Volley (Påhittade Organisationen för Volleyboll), för att hålla koll på poängen i en volleybollmatch mellan de två lagen Algoritmikerna och Bäverbusarna.</p>

<p>I volleyboll spelar man bäst av $3$ set, det vill säga det laget som först vunnit $2$ set vinner matchen. I de två första setten gäller först till $25$, och ifall det blir ett tredje set spelar man då först till $15$. Man måste vinna med $2$ poäng, så det är alltså det lag som först har minst $25$ resp $15$ poäng, och som dessutom har $2$ poäng mer än motståndaren som vinner det settet. Givet vilket lag som vinner varje boll, skriv ut resultatet av matchen.</p>



## 입력


<p>Den första raden innehåller ett heltal $N$ ($1 \le N \le 200$). Därefter följer en $N$ tecken lång sträng bestående av "<code>A</code>" och "<code>B</code>", som beskriver en hel match. Den $i$:te bokstaven är "<code>A</code>" ifall Algoritmikerna vinner den $i$:te bollen, och "<code>B</code>" ifall lag Bäverbusarna vinner den $i$:te bollen.</p>

<p>Matchen kommer att vara fullständig, d.v.s. något av lagen kommer ha kommit upp i $2$ poäng i slutet, och inga extra bollar kommer ha spelats.</p>



## 출력


<p>Skriv ut en rad med två heltal. Det första talet ska vara antalet set Algoritmikerna vann och det andra talet ska vara antalet set Bäverbusarna vann.</p>



## 소스코드

[소스코드 보기](Volleybollmatchen.cpp)