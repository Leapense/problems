# 21282번: Kulramen - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21282)


<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/9f712b98-1001-4f96-9d0b-3f3e65512d40/-/preview/" style="width: 387px; height: 100px;"></p>

<p style="text-align: center;">Figur 2.&nbsp;Så här kunde Simons kulram (med $R=4$) se ut innan han började äta upp kulorna. Då var det lätt att översätta ställningen till ett decimaltal.</p>

<p>Lille Simon har fått en kulram i present. Kulramen har $R$ rader och i varje rad fanns från början 9 kulor, så att man kunde representera $R$-siffriga decimaltal -- en siffra på varje rad. Om en rad hade $X$ kulor på vänstra sidan, sedan ett mellanrum och övriga kulor på höger sida representerade raden siffran X.</p>

<p>Tyvärr tyckte Simon att kulorna på ramen såg väldigt smaskiga ut, och åt helt enkelt upp några kulor. Det finns dock minst en kula kvar på varje rad.</p>

<p>Simon lärde sig snabbt att räkna på sin nya kulram. Han representerar talet där alla kulor är på högersidan som talet 0, och adderar sedan 1 precis som han hade gjort på en vanlig kulram, genom att flytta en kula från höger till vänster på den nedersta raden som har någon kula kvar på höger sida (låt oss kalla den <em>flyttningsraden</em>) samt flytta alla kulor på raderna nedanför flyttningsraden till höger sida (om inte flyttningsraden är den nedersta raden). Om 1 adderas när alla kulorna på <em>alla</em> rader redan är på vänster sida (så att det inte finns någon flyttningsrad) blir resultatet 0.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/d0e8f205-3e2c-4bfb-a39a-9fbab5749a08/-/preview/" style="width: 510px; height: 300px;"></p>

<p style="text-align: center;">Figur 3.&nbsp;Några exempel på hur Simon adderar 1 på den kulram som återfinns i de två första exemplen. Dubbelpilen markerar "flyttningsraden" vid de olika additionerna.</p>

<p>Simon håller på att räkna sandkornen i sin sandlåda och skulle behöva hjälp att skriva ett program som, givet ett visst utgångsläge på kulramen, räknar ut hur kulramen ser ut när han $N$ gånger har adderat 1.</p>



## 입력


<p>På första raden står antalet rader $R$. Därefter följer $R$ rader med vardera två heltal, antalet kulor till vänster respektive höger på varje rad (uppifrån och ned). Slutligen finns en rad med det positiva heltalet $N$.&nbsp;</p>



## 출력


<p>Programmet ska skriva ut $R$ rader med två tal på varje rad: antalet kulor till vänster respektive höger på varje rad efter additionerna.</p>



## 소스코드

[소스코드 보기](Kulramen.py)