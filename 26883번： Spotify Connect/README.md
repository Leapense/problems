# 26883번: Spotify Connect - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26883)


<p>Spotify har precis lanserat den nya funktionen Spotify Connect, som möjliggör för en användare att fjärrstyra sin uppspelning från mobiltelefonen. Det medför en mängd nya tekniska utmaningar, och en av dem är hur loggningen av uppspelningsdata görs. För att kunna rapportera till skivbolagen så måste man nämligen veta exakt hur länge en användare har lyssnat på musik.</p>

<p>Du kommer att få loggdata för <code>play</code> och <code>paus</code>-tryckningarna för en användare. Användaren använder både sin laptop för att styra musiken, men fjärrstyr också ibland med mobiltelefonen via Spotify Connect. Loggarna innehåller både datorns och mobilens <code>play</code> och <code>paus</code>-tryckningar. När användaren trycker på mobilen så är det exakt $100$ millisekunder delay tills laptopen (där musiken spelas upp ifrån) reagerar. Ditt uppdrag är att avgöra exakt hur många millisekunder totalt som laptopen spelade upp musik. Innan första kommandot utförs så är spelaren i pausat läge.</p>



## 입력


<p>Den första raden innehåller heltalet $1 \le N &lt; 1000$, antalet loggrader.</p>

<p>De efterföljande $N$ raderna innehåller en lista med loggar. Loggarna kommer i den ordning knapptryckningar sker med en tidsstämpel i millisekunder, enhet (<code>laptop</code> eller <code>mobile</code>) och kommando (<code>play</code> eller <code>paus</code>). Den sista loggen kommer alltid vara ett <code>paus</code>-kommnado. Dessutom kommer två loggar aldrig ha samma tidsstämpel eller ligga exakt 100 millisekunder ifrån varandra.</p>

<p>För att göra indatat extra lättläst så är loggradernas fält alignerade. Tidsstämpeln fylls ut med nollor vänsterifrån så att talet alltid blir 7 tecken långt, och mobil stavas istället mobile, alltså med lika många tecken som i laptop. Se indataexemplet.</p>



## 출력


<p>Ditt program ska skriva ut ett heltal - antalet millisekunder användaren lyssnat på musik.</p>



## 소스코드

[소스코드 보기](Spotify%20Connect.cpp)