# 7229번: Malkos - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7229)


<p>http://vip.latnet.lv/lio/ARHIVS/LIO04/ino17kopa.pdfaAdomas, besiruošdamas žiemai, nusipirko N malkų. Visos malkos yra vienodo skersmens, tačiau jos gali būti skirtingo ilgio. Adomas nori sukrauti visas malkas savo rūsyje.</p>

<p>Adomas malkas krauna tokiu būdu:</p>

<ol>
<li>Ant grindų paguldoma pirma malka.</li>
<li>Ant viršaus paguldoma kuo daugiau malkų, statmenai pirmajai. Ant L ilgio malkos galima sukrauti daugiausiai L kitų malkų.</li>
<li>Tuomet ant viršaus vėl guldoma viena malka, statmenai po ja esančioms. Ji turi būti ne ilgesnė negu po ja esančių malkų skaičius.</li>
<li>Ant viršaus vėl paguldoma kuo daugiau malkų, statmenai. Ir taip toliau.</li>
</ol>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/cb50894b-26ba-4f6b-bc20-b4f1b6594e6c/-/preview/" style="width: 251px; height: 203px;"></p>

<p style="text-align: center;">1 pav. Malkų krūvos pavyzdys.</p>

<p>Adomas nėra labai aukštas. Tad jis nori, kad malkų krūva būtų kuo žemesnė.</p>

<p>Jums žinomi visų malkų ilgiai. Raskite, koks yra mažiausias įmanomas malkų krūvos aukštis, jas kraunant nurodytu būdu.</p>



## 입력


<p>Pirmoje eilutėje įrašytas malkų skaičius N. Antroje eilutėje pateikiama N tarpais atskirtų sveikųjų skaičių L<sub>i</sub>, žyminčių malkų ilgius.</p>



## 출력


<p>Išveskite vienintelį skaičių – mažiausią įmanomą malkų krūvos aukštį.</p>



## 소스코드

[소스코드 보기](Malkos.cpp)