# 7245번: Kurjeris - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7245)


<p>Bitlandijos maisto pristatymo įmonėje „Unter Valgyt” dirba N kurjerių. Visi kurjeriai pradeda darbą tuo pačiu laiku – ryte (Bitlandijos laiku t = 0 minučių). Dienos metu gaunami užsakymai, apie kiekvieną kurių yra žinoma:</p>

<ul>
<li>Užsakymo gavimo laikas (minutėmis);</li>
<li>Vertė, kiek kurjeris uždirbs už jo įvykdymą;</li>
<li>Laikus, kiek užtruktų kiekvienas kurjeris įvykdyti užsakymą (minutėmis). To paties užsakymo įvykdymo laikai yra skirtingi visiems kurjeriams.</li>
</ul>

<p>Užsakymas yra priskiriamas laisvam kurjeriui (tuo metu nevykdančiam jokio užsakymo), kuris jį įvykdytų greičiausiai. Jei tuo metu visi kurjeriai yra užimti, užsakymas dingsta, nes klientas kreipiasi į kitą įmonę.</p>

<p>Kurjeriai baigia dirbti, kai įvykdo visus per dieną gautus užsakymus.</p>

<p>Suskaičiuokite, kiek kiekvienas kurjeris uždirbs per dieną.</p>



## 입력


<p>Pirmoje eilutėje yra pateikti du skaičiai: kurjerių (N) ir užsakymų (M) skaičius. Kitose M eilučių duota užsakymų informacija:</p>

<ul>
<li>t – užsakymo gavimo laikas minutėmis nuo darbo dienos pradžios. Visų užsakymų laikai yra skirtingi ir pateikti didėjimo tvarka.</li>
<li>v – užsakymo vertė, kurią kurjeris uždirbs jį įvykdęs.</li>
<li>z<sub>1</sub>, z<sub>2</sub>, z<sub>3</sub>, ...z<sub>n</sub> – laikai, kurie reiškia, kad i-asis kurjeris įvykdyti šį užsakymą užtruks z<sub>i</sub> minučių. Visi vieno užsakymo laikai yra skirtingi.</li>
</ul>



## 출력


<p>Vienoje eilutėje pateikite N skaičių – kiek uždirbs kiekvienas kurjeris tą dieną.</p>



## 소스코드

[소스코드 보기](Kurjeris.py)