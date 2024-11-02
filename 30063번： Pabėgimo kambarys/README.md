# 30063번: Pabėgimo kambarys - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30063)


<p>Norėdami atšvęsti Lietuvos informatikos olimpiadų trisdešimtmetį, Vertinimo komisijos nariai sugalvojo sau pramogą: pabėgimo kambarį. Pabėgimo kambarys – tai seka užuominų, kurių kiekviena yra pažymėta didžiąja lotyniška raide.</p>

<p>Užuominos yra atskleidžiamos po vieną, nuo pirmos iki paskutinės pateikta tvarka. Komisijos nariai iš kambario ištrūkti gali tuomet, kai iš surinktų užuominų pavyksta sudaryti žodį <code>RAKTAS</code>.</p>

<p>Įsivaizduokime pabėgimo kambarį, kurio užuominų seka yra tokia:</p>

<p style="text-align: center;"><code>RAUDONASNYKSTUKAS</code></p>

<p>Iš šio pabėgimo kambario komisija gali ištrūkti įveikusi $13$ užuominų:</p>

<p style="text-align: center;"><code><u>RA</u>UDON<u>A</u>SNY<u>KST</u>UKAS</code></p>

<p>Keturios paskutinės užuominos (pažymėtos pilkai) nėra būtinos, nes žodį <code>RAKTAS</code> pavyks sudaryti iš jau surinktų užuominų (raidės pabrauktos).</p>

<p>Parašykite programą, kuri rastų, kiek mažiausiai užuominų reikia atskleisti norint ištrūkti iš pabėgimo kambario.</p>



## 입력


<p>Pirmoje eilutėje pateiktas vienintelis skaičius – užuominų kiekis $N$.</p>

<p>Antroje eilutėje pateikta $N$ ilgio simbolių eilutė – užuominų seka. Užuominos žymimos didžiosiomis lotyniškomis raidėmis nuo <code>A</code> iki <code>Z</code>. Pašalinių simbolių nebus.</p>



## 출력


<p>Išveskite vieną sveikąjį skaičių – mažiausią reikalingų užuominų kiekį.</p>

<p>Pradiniai duomenys bus tokie, kad atsakymas visada egzistuos.</p>



## 소스코드

[소스코드 보기](Pabėgimo%20kambarys.cpp)