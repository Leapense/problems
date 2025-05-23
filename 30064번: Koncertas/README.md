# 30064번: Koncertas - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30064)


<p>Muzikos mylėtojai renkasi į koncertą. Iš viso koncertų salėje yra $N$ sėdimų vietų ir jos visos išpirktos. Kiekvienas klausytojas turi po bilietą su pažymėta vieta. Laikysime, kad klausytojo numeris yra $X$, jeigu jis turi bilietą su pažymėta vieta $X$. Taigi pirmasis klausytojas turėtų sėdėti vietoje $1$, antrasis – vietoje $2$, ir taip toliau.</p>

<p>Tačiau atėję į koncertų salę klausytojai susėdo nežiūrėdami į paskirtas vietas.</p>

<p>Paskutinysis vėluodamas atbėgo pats didžiausias muzikos mylėtojas nr. $1$, kuris turėjo sėdėti vietoje $1$. Kadangi tai pati geriausia vieta, jeigu ji bus užimta, jis paprašys ten sėdinčio klausytojo ją atlaisvinti. Tokiu atveju, šis klausytojas susigėdęs eis į sau paskirtą vietą (klausytojas $X$ eis į vietą $X$), o jeigu ji bus užimta – paprašys ją atlaisvinti. Šitaip persėdimas tęsis tol, kol galų gale visi klausytojai vėl susės.</p>

<p>Jums žinoma, kur yra atsisėdęs kiekvienas muzikos mylėtojas bei kuri viena vieta yra laisva prieš pasirodant klausytojui nr. $14, Raskite, kiek iš viso klausytojų turės persėsti.</p>



## 입력


<p>Pirmoje eilutėje įrašytas skaičius $N$. Antroje eilutėje įrašyta $N$ skaičių, atskirtų tarpais: tai numeriai klausytojų atsisėdusių vietose $1, 2, \dots , N$. Lygiai vienas iš šių skaičių bus lygus $0$, kuris žymi jog ši viena vieta yra laisva.</p>



## 출력


<p>Išveskite vieną skaičių – kiek klausytojų iš viso turės persėsti, klausytojui nr. $1$ pareikalavus savo vietos.</p>



## 소스코드

[소스코드 보기](Koncertas.cpp)