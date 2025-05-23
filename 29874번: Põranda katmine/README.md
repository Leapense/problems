# 29874번: Põranda katmine - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/29874)


<p>Maaler Mati hakkab toa lage värvima ja tal on vaja põrand kinni katta, et värvitilgad seda ära ei määriks. Põranda katmiseks on tal kaks papptahvlit. Aga neid tahvleid on hiljem veel tarvis ja Mati ei taha neid lõigata ega kokku murda. Kui põranda saab katta ühe tahvliga, siis Mati teist tahvlit ei kasuta. Nii tuba kui tahvlid on ristküliku kujuga. Toa mõõtmed on $X \times Y$ cm, esimese tahvli mõõtmed $A_1 \times B_1$ cm ja teise omad $A_2 \times B_2$ cm.</p>

<p>Kontrollida, kas nende tahvlitega saab katta korraga kogu põranda. Tahvleid võib pöörata ja nad võivad ka osaliselt üksteist katta, aga ei saa ulatuda üle põranda ääre. Kui põranda katmine on võimalik, siis leida sobiv tahvlite paigutus XY-teljestikus, kus toa vastasnurkade koordinaadid on $(0, 0)$ ja $(X, Y)$. Kui lahendeid on mitu, siis esitada üks neist.</p>



## 입력


<p>Sisendi esimesel real on tühikuga eraldatud täisarvud $X$ ja $Y$: toa mõõtmed ($0 &lt; X, Y \le 500$). Teisel real on ühe tahvli mõõtmed $A_1$ ja $B_1$ ning kolmandal real teise tahvli mõõtmed $A_2$ ja $B_2$ samas vormingus ($0 &lt; A_1, B_1, A_2, B_2 \le 500$).</p>



## 출력


<p>Kui põrandat ei saa nõutud viisil katta, kirjutada väljundi ainsale reale '<code>EI SAA</code>'.</p>

<p>Kui programmi leitud lahend kasutab kahte tahvlit, siis kirjutada väljundi kahele reale kummalegi neli tühikutega eraldatud täisarvu. Esimesel real kirjeldada esimese tahvli asendit, andes koordinaattasandi suhtes vasakpoolse alumise nurga koordinaadid $X_{1,1}$ ja $Y_{1,1}$ ning parempoolse ülemise nurga koordinaadid $X_{1,2}$ ja $Y_{1,2}$. Teisel real anda teise tahvli nurkade koordinaadid $X_{2,1}$ ja $Y_{2,1}$ ning $X_{2,2}$ ja $Y_{2,2}$.</p>

<p>Kui lahend kasutab ainult esimest tahvlit, siis kirjutada väljundi esimesele reale selle nurkade koordinaadid ja teisele reale sümbol '<code>Z</code>'. Kui lahend kasutab ainult teist tahvlit, siis kirjutada väljundi esimesele reale sümbol '<code>Z</code>' ja teisele reale teise tahvli asendi kirjeldus.</p>



## 소스코드

[소스코드 보기](Põranda%20katmine.cpp)