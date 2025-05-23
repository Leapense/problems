# 7219번: Kurjeris - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7219)


<p>Artėjant Kalėdoms, Bitlandijos siuntinių kompanija Bitzon turi neįprastai daug darbo.</p>

<p>Bitlandijoje yra N miestų, kuriuos jungia vienas bendras greitkelis. Į Rytus nuo pirmojo miesto įsikūręs kompanijos Bitzon sandėlis. Atstumas nuo Bitzon sandėlio iki pirmojo miesto yra m<sub>1</sub> laiko vienetų, nuo pirmojo iki antrojo miestų – m<sub>2</sub> laiko vienetų, ir taip toliau, kaip pavaizduota iliustracijoje:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/4f5cb26d-9d2f-498f-a239-d12c24f753ea/-/preview/" style="width: 479px; height: 68px;"></p>

<p>Į sandėlį kiekvieną dieną atveža krūvą siuntinių, kuriuos kurjeris turi išvežioti. Kiekvienam siuntiniui nurodytas adresas (miesto numeris) ir laikas, kada siuntinys turi būti pristatytas. Siuntinius kurjeris gali pristatyti anksčiau negu numatyta, bet būtinai ne vėliau nei nurodytu laiku.</p>

<p>Kurjeris išvyksta iš sandėlio ryte (laikysime šį momentą laiku 0), ir važinėja iš vieno miesto į kitą pristatinėdamas siuntinius.</p>

<p>Šiame uždavinyje laikysime, kad siuntinio pristatymas laiko neužima, tiktai važiavimas nuo vieno miesto iki kito.</p>

<p>Žinomas siuntinių sąrašas, kuriuos kurjeris turi pristatyti. Raskite:</p>

<ol>
<li>Ar kurjeris suspės pristatyti visus siuntinius nepavėluodamas.</li>
<li>Per kiek mažiausiai laiko kurjeris sugebės pristatyti visus siuntinius ir sugrįžti į sandėlį.</li>
</ol>



## 입력


<p>Pirmoje eilutėje įrašytas miestų skaičius N. Antroje eilutėje įrašyta N sveikųjų skaičių – atstumai m<sub>1</sub>, m<sub>2</sub>, . . . , m<sub>N</sub>. Trečioje eilutėje įrašytas siuntinių skaičius K.</p>

<p>Galiausiai seka K eilučių, aprašančių visus siuntinius. Kiekvienoje iš šių eilučių pateikta po du sveikuosius skaičius: miesto numeris a<sub>i</sub> (1 ≤ a<sub>i</sub> ≤ N), kur siuntinys turi būti pristatytas, ir vėliausias galimas pristatymo laikas t<sub>i</sub>.</p>

<p>Laikykite, kad kurjeris išvyksta iš sandėlio laiku 0. Į tą patį miestą gali būti pristatomas daugiau negu vienas siuntinys. Kurjeris siuntinius gali pristatyti bet kuria tvarka (bet nevėluodamas).</p>



## 출력


<p>Išveskite vienintelį sveiką skaičių – per kiek mažiausiai laiko įmanoma pristatyti visus siuntinius ir sugrįžti į sandėlį. Jeigu bent vieno siuntinio neįmanoma pristatyti laiku – išveskite −1.</p>



## 소스코드

[소스코드 보기](Kurjeris.cpp)