# 24190번: Ljusshow - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24190)


<p>Din vän håller på att designa en ljusshow för avslutningsceremonin i årets Programmeringsolympiadsfinal. Salen där ceremonin hålls kan ses som ett rutnät med $R$ rader och $C$ kolumner. Utmed de fyra sidorna är olika lampor monterade, vilka kan lysa med en av tre olika färger: rött, blått eller grönt. Under ceremonin är tanken att lamporna skiftar i olika mönster.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/a43c546a-dee6-41e0-9ad5-18ef5766aad3/-/preview/" style="width: 400px; height: 347px;"></p>

<p>En lampa lyser upp samtliga rutor längs med samma kolumn eller rad som den är monterad. Om en viss ruta lyses upp av minst en lampa av varje färg kommer ljuset i rutan att uppfattas som ett otrevligt bländande vitt. Din vän har redan designat ett utkast till ljusshowen, och undrar nu om vissa av de valda ljuskonfigurationerna orsakar att för många rutor blir vita. För att kunna avgöra om en konfiguration är okej eller inte har du fått i uppgift att skriva ett program som läser in vilken färg samtliga lampor ska lysa med, och beräknar antalet rutor som kommer lysa vitt.</p>



## 입력


<p>Den första raden innehåller två heltal: $R$ ($1 \le R \le 10^6$) och $C$ ($1 \le C \le 10^6$), antalet rader och kolumner i den rutnätsformade salen.</p>

<p>De fyra nästa raderna innehåller en textsträng vardera och beskriver vilka färger alla lampor har. Den första raden beskriver de $C$ lamporna i toppen av rutnätet som skiner nedåt i ordning vänster till höger, den andra de $R$ lamporna i rutnätet till höger om rutnätet som skiner till vänster i ordning uppifrån och ned, den tredje de $C$ lamporna under rutnätet som skiner uppåt i ordning vänster till höger, den fjärde de $R$ lamporna i rutnätet till vänster om rutnätet som till höger i ordning uppifrån och ned.</p>

<p>Färgen på en lampa beskrivs med hjälp av tecknen <code>RGB</code> beroende på om lampan lyser rött, grönt eller blått.</p>



## 출력


<p>Skriv ut ett heltal -- antalet rutor i salen som lyser vitt. <strong>Not: svaret ryms inte nödvändigtvis i ett 32-bitars heltal.</strong></p>



## 소스코드

[소스코드 보기](Ljusshow.py)