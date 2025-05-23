# 30071번: Badmintonas - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30071)


<p>Bitlandijos badmintono komanda Bitai žaidžia finalines rungtynes prieš Baitlandijos komandą Baitus. Kadangi Baitai žaidžia namuose, jie savąją komandos sudėtį paskelbė iš anksto.</p>

<p>Kiekvieną komandą sudaro trys poros žaidėjų:</p>

<ul>
<li>Kiekvienas žaidėjas turi savo <em>stiprumo</em> indeksą $s_i$;</li>
<li>Jei žaidėjai $i$ ir $j$ sudaro porą, tai <em>poros stiprumo indeksas</em> $P = s_i + s_j$;</li>
<li>Jei dvi poros žaidžia tarpusavyje, laimi ta, kurios stiprumo indeksas didesnis.</li>
</ul>

<p>Bitai, pasinaudodami paskelbta informacija, nori sudaryti komandą taip, kad nugalėtų Baitus. Kiekviena Bitų pora sužaidžia su kiekviena Baitų pora, iš viso vyksta $9$ rungtynės. Ar įmanoma Bitams laimėti?</p>

<p>Sudarykite $3$ komandas iš Bitų žaidėjų taip, kad šie laimėtų kuo daugiau rungtynių. Duomenys pateikti tokie, kad lygiosios neįmanomos.</p>



## 입력


<p>Pirmoje eilutėje pateikti Baitų <strong>žaidėjų porų</strong> stiprumo indeksai $B_1$, $B_2$, $B_3$. Tolimesnėse šešiose eilutėse – Bitų <strong>atskirų žaidėjų</strong> stiprumo indeksai $S_i$.</p>



## 출력


<p>Išveskite sveikąjį skaičių $M$, nurodantį, kiek žaidimų pavyks laimėti Bitams. Tolimesnėse trijose eilutėse išveskite bet kokią galimą komandos sudėtį, nurodydami žaidėjų stiprumo indeksus, kuri pasieks geriausią rezultatą.</p>



## 소스코드

[소스코드 보기](Main.java)