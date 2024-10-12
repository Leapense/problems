# 7184번: Mõttemeister - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7184)


<p>Mõttemeister on kahe mängija lauamäng. Esimene mängija mõtleb salajase 4-kohalise arvu ja teine hakkab seda ära arvama.</p>

<p>Igal käigul pakub arvaja 4-kohalise arvu. Esimene mängija vastab kahe arvuga $A$ ja $B$, kus $A$ näitab, mitu õiget numbrit oli pakutud arvus, ning $B$, mitu nendest paiknesid õigel kohal.</p>

<p>Seejärel teeb arvaja uue pakkumise ning mäng jätkub, kuni arvaja arvab salajase arvu ära või käikude arv ületab teatud piiri.</p>

<p>Näiteks olgu salajane arv 5247. Pakkumisele 1234 oleks vastus 2 (numbrid 2 ja 4 on õiged) ja 1 (number 2 on õige koha peal).</p>

<p>Kui pakkumises on korduvaid numbreid, siis loetakse iga numbrit õigeks ainult niimitu korda, kuimitu eksemplari on seda numbrit salajases arvus.</p>

<p>Kirjuta programm, mis etteantud pakkumiste ja vastuste põhjal leiab kõik võimalikud salajase arvu väärtused.</p>



## 입력


<p>Tekstifaili on täisarv $N$ ($1 \le N \le 10\,000$). Järgmisel $N$ real on igaühel ühe käigu kirjeldus: pakutud 4-kohaline arv, selle õigete numbrite arv $A$ ($0 \le A \le 4$) ja selles õigel kohal olevate numbrite arv $B$ ($0 \le B \le A$).</p>



## 출력


<p>Tekstifaili esimesele reale väljastada salajase arvu võimalike väärtuste arv $M$. Järgmisele $M$ reale väljastada salajase arvu võimalikud väärtused kasvavas järjekorras.</p>



## 소스코드

[소스코드 보기](Mõttemeister.cpp)