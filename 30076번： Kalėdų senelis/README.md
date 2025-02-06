# 30076번: Kalėdų senelis - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30076)


<p>Greitai Kalėdos. Elniai jau pakinkyti ir Kalėdų senelis beveik pasiruošęs traukti į kelionę, tik dovanos dar nesukrautos.</p>

<p>Nors rogėse telpa be galo daug dovanų, bet sunkias roges tempiantis kinkinys greitai pavargsta, todėl dovanų reikia krauti kiek galima mažiau.</p>

<p>Tai žinodami nykštukai Kalėdų senelio mašrute ant namų stogų įrengė dovanų slėptuves.</p>

<p>Kalėdų senelis gali pasikrauti dovanų savo trobelėje (t.y. pradiniame taške), o taip pat bet kurioje slėptuvėje.</p>

<p>Žinodami, kiek vaikų turi aplankyti Kalėdų senelis, patarkite, kiek dovanų jam reikia įkrauti į roges savo trobelėje bei kiekvienoje slėptuvėje, kad jų kiekis rogėse visada būtų kuo mažesnis.</p>

<p>Keliaudamas Kalėdų senelis:</p>

<ul>
<li>lanko vaikus namų numerių didėjimo tvarka, pradėdamas nuo pirmojo;</li>
<li>negali apgręžti rogių atgal iki neaplanko visų vaikų;</li>
<li>jei ant namo stogo yra įrengta slėptuvė, jis pirma joje pasipildo roges dovanų, o tuomet neša dovaną tame name gyvenančiam vaikui.</li>
</ul>

<p>Visi vaikai gyvena skirtinguose namuose ir kiekvienam jų atneš vieną dovaną.</p>



## 입력


<p>Pirmojoje eilutėje pateikti du sveikieji skaičiai:</p>

<ul>
<li>$N$ – vaikų skaičius;</li>
<li>$M$ – dovanų slėptuvių skaičius.</li>
</ul>

<p>Kitose $M$ eilučių pateikta po du skaičius:</p>

<ul>
<li>$K_i$ – ant kelinto vaiko namo stogo įrengta slėptuvė. Duomenys pateikti $K_i$ didėjimo tvarka;</li>
<li>$Z_i$ – dovanų skaičius šiame sandėlyje.</li>
</ul>

<p>Pradiniame taške yra Kalėdų senelio trobelė, joje yra be galo daug dovanų.</p>



## 출력


<p>Išveskite $M + 1$ skaičių skirtingose eilutėse. Pirmojoje eilutėje nurodykite, kiek dovanų reikia įsidėti prieš pradedant kelionę. Kitose $M$ eilučių išveskite, kiek dovanų reikia pasikrauti kiekvienoje slėptuvėje (rezultatai pateikiami ta tvarka, kokia slėptuvės pateiktos pradiniuose duomenyse).</p>



## 소스코드

[소스코드 보기](Main.java)