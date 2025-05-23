# 30282번: Paskaitos - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30282)


<p>Artūras šiemet baigė mokyklą ir labai džiaugiasi įstojęs į prestižinį universitetą. Pirmas darbas, kurį turėjo atlikti Artūras nuvykęs į universitetą – išsirinkti 10 pasirenkamųjų dalykų, kuriuos jis studijuos universitete pirmą semestrą.</p>

<p>Artūras pasirinko dešimt dalykų, tačiau vėliau susimąstė, ar nesidubliuos paskaitų laikai, t. y. ar neišsirinko jis tokių dalykų, kurių paskaitos vyksta tuo pačiu metu.</p>

<p>Jei tuo pačiu metu viena paskaita baigiasi, o kita prasideda (sutampa pabaigos ir pradžios laikas), tokios paskaitos laikomos nesidubliuojančiomis.</p>

<p>Padėkite Artūrui išsiaiškinti, ar jis galės lankyti visus pasirinktus dalykus.</p>



## 입력


<p>Pradinius duomenis sudaro 10 eilučių su informacija apie Artūro pasirinktus studijuoti dalykus.</p>

<p>Kiekvienoje eilutėje yra pateikiami penki skaičiai: savaitės dienos numeris s (1 – pirmadienis, 2 – antradienis, ..., 5 – penktadienis), paskaitos pradžios laikas (valanda h<sub>pr</sub> ir minutės m<sub>pr</sub>) ir pabaigos laikas (valanda h<sub>pb</sub> ir minutės m<sub>pb</sub>).</p>



## 출력


<p>Jeigu Artūras galės lankyti visas paskaitas, tuomet išveskite žodį <code>TAIP</code> bei bendrą paskaitų trukmę valandomis ir minutėmis.</p>

<p>Jeigu kurių nors pasirinktų paskaitų laikai dubliuosis, tuomet išveskite žodį <code>NE</code> bei dviejų dalykų, kurių užsiėmimai dubliuosis, numerius. Laikykite, kad pasirinkti dalykai sunumeruoti nuo 1 iki 10.</p>

<p>Jei galimi keli atsakymo variantai, išveskite bet kurį.</p>



## 소스코드

[소스코드 보기](Paskaitos.cpp)