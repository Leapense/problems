# 26911번: Limousinen - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26911)


<p>I Taipei har IOI satt igång med ett intensivt schema av föreläsningar, lekar, förberedelser, matpauser, sömnpauser och tävlingar. Men arrangörerna har lämnat en timme fri för alla att göra vad de vill. Detta är ett problem som lagledarna inte alls förberett de tävlande på. Förvirring och kaos uppstår i de tävlandes hjärnor, och när fritidstimmen är slut så är de $N$ tävlande utspridda vid olika korsningar i storstaden och har inte en aning om hur de ska hitta tillbaka. Lyckligtvis hade tävlingsledningen installerat ett chip i varje tävlandes väska som gör att de kan se exakt vid vilken gatukorsning som varje vilsen tävlande befinner sig.</p>

<p>Limousinföraren Simon har fått i uppdrag att plocka upp de tävlande och köra dem, en i taget, till tävlingsarenan. Han vill naturligtvis undsätta dem i en ordning som gör att han hinner skjutsa tillbaka så många som möjligt innan nästa föreläsning börjar (vilket sker om $T$ minuter). Taipei kan modelleras som ett oändligt regelbundet rutnät där heltalskoordinater är korsningar och det finns lodräta och horisontella vägar. Det tar exakt 1 minut att köra från en korsning till en närliggande korsning.</p>

<p>Simon börjar vid tävlingsarenan på adressen $(0, 0)$, kör till den första personen och hämtar upp den och kör sedan hem personen till arenan. Därefter kör han till nästa person, o.s.v. Han fortsätter så tills tiden tar slut, och han kan alltså bara skjutsa en i taget. Om han väljer ordningen han hämtar upp de tävlande i optimalt, hur många hinner han hämta upp och skjutsa tillbaka inom $T$ minuter?</p>



## 입력


<p>På första raden i indata står två heltal $N$ ($1 \leq N \leq 100\,000$), antalet tävlande som ska plockas upp, och $T$ ($1 \leq T \leq 10^9$), hur lång tid Simon har på sig i minuter.</p>

<p>Sedan följer $N$ rader (en rad per tävlande). Varje rad består av två heltal $-10^8 \leq x, y \leq 10^8$, $x$- och $y$-koordinater för personens nuvarande position.</p>



## 출력


<p>Skriv ut hur många tävlande som Simon hinner köra hem innan tiden är slut, givet att han väljer ordningen optimalt.</p>



## 소스코드

[소스코드 보기](Limousinen.py)