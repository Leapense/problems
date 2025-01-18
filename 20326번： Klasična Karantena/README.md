# 20326번: Klasična Karantena - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/20326)


<p>Uslijed globalne pandemije <em>COVID-19</em>, nacionalni je stožer civilne zaštite donio novi niz smjernica i uputa s ciljem prevencije daljnjeg širenja zaraze među populacijom. Jedna od smjernica odnosi se na obavezno nošenje zaštitnih maski u svim ugostiteljskim objektima, što uključuje i gostionice, odnosno birtije.</p>

<p>Na vratima jedne lokalne birtije odmah je osvanuo natpis <strong>OBAVEZNO NOŠENJE MASKI!!!</strong>. Međutim, budući da se radi samo o smjernicama, vlasnici birtije ne mogu natjerati svoje posjetitelje da nose maske. Primijetili su da se u birtiji trenutno nalazi a ljudi koji nose maske i b ljudi koji ne nose maske, te im je također poznato da će tijekom večeri u birtiju doći još n ljudi. Duboko razumijevanje ljudske prirode uz dobro poznavanje vlastitih mušterija omogućilo je vlasnicima da s nevjerojatnom prezinošću zaključe kako će i-ti novopridošli gost staviti masku ako i samo ako je birtija prije njegovog ulaska prazna ili se u birtiji nalazi barem p<sub>i</sub>% ljudi koji nose maske.</p>

<p>Nažalost, vlasnici birtije ne znaju kojim će redoslijedom gosti dolaziti u birtiju, ali znaju da nitko neće otići. Stoga ih zanima koji je najmanji, a koji najveći broj ljudi koji će u birtiji nositi maske nakon što uđe svih n gostiju.</p>



## 입력


<p>U prvom se retku nalaze dva cijela broja a i b (0 ≤ a, b ≤ 10<sup>9</sup>) iz teksta zadatka.</p>

<p>U drugom se retku nalazi prirodan broj n (1 ≤ n ≤ 500 000) iz teksta zadatka.</p>

<p>U i-tom od sljedećih n redaka nalazi se realan broj p<sub>i</sub> (0 ≤ p<sub>i</sub> ≤ 100) iz teksta zadatka. Svaki od brojeva p<sub>i</sub> bit će zapisan na dvije decimale te će slijediti znak '<code>%</code>' (ASCII 37).</p>



## 출력


<p>U jednom je retku potrebno ispisati dva cijela broja koji redom označavaju najmanji i najveći broj ljudi koji će u birtiji nositi maske nakon što uđe svih n gostiju.</p>



## 소스코드

[소스코드 보기](Klasična%20Karantena.cpp)