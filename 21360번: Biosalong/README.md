# 21360번: Biosalong - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21360)


<p>Axel och Beatrice ska gå på bio tillsammans. De vill sitta på samma rad och allra helst brevid varandra. Om det inte finns två lediga platser brevid varandra vill de ha två platser så nära varandra som möjligt.</p>

<p>För att hitta den bästa raden att sitta på ber de dig om hjälp. Givet en beskrivning av vilka stolar som är lediga på en viss rad, hitta det kortaste avståndet mellan två lediga stolar. Avståndet är antal stolar mellan de två lediga stolarna.</p>



## 입력


<p>Den första raden innehåller ett heltal $1 \le N \le 1\,000\,000$ -- antalet stolar i raden vi betraktar.</p>

<p>Den andra raden innehåller en sträng med $N$ tecken, där det $i$:te tecknet är '<code>#</code>' ifall den $i$:te stolen på raden är upptagen och '<code>.</code>' om stolen är ledig. Det är garanterat att minst två stolar är lediga, dvs minst två tecken är '<code>.</code>'.</p>



## 출력


<p>Skriv ut ett heltal -- det kortaste avståndet mellan två lediga stolar.</p>



## 소스코드

[소스코드 보기](Biosalong.cpp)