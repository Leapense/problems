# 7176번: Geopeitus - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7176)


<p>Geopeituse mängus antakse aarete koordinaadid mõnikord valemina, kus mõned numbrid on asendatud tähtedega, näiteks <code>N58 24.1ab E26 44.3c</code>.</p>

<p>Kirjutada programm, mis väljastab kõik antud valemile ja muutujate võimalikele väärtustele vastavad koordinaadid.</p>



## 입력


<p>Tekstifaili esimesel real on valem, mis koosneb laius- ja pikkuskraadi esitusest, mis omakorda koosnevad ilmakaare tähisest (<code>N</code>, <code>S</code>, <code>E</code>, <code>W</code>) ning kraadide, minutite ja minuti murdosa näitudest näites antud vormingus. Valemi pikkus ei ületa 25~märki.</p>

<p>Faili teisel real on muutujate arv $N$ ($1 \le N \le 3$) ja järgmisel $N$ real igaühel ühe muutuja kirjeldus: muutuja nimi, võrdusmärk ja komadega eraldatud loetelu, mille elemendid on kas üksikud väärtused või väärtuste vahemikud. Muutuja nimi on alati üks väike ladina täht. Väärtused ja vahemike otspunktid võivad olla ühe- või kahekohalised arvud. Võib eeldada, et ühegi muutuja kirjeldus ei tekita korduvaid väärtusi.</p>



## 출력


<p>Tekstifaili väljastada kõik koordinaadid, mis on võimalik saada muutujate lubatud väärtustega asendamisel. Koordinaadid väljastada igaüks eraldi reale, ridade järjekord failis pole oluline.</p>



## 소스코드

[소스코드 보기](Geopeitus.cpp)