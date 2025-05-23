# 29835번: Palindroom - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/29835)


<p>Kevin sai informaatikaolümpiaadi eelvooru palindroomiülesande eest maksimumpunktid. Seda nähes andis õpetaja talle natuke raskema ülesande, milles uuritakse mitmesuguse pikkusega tekstilisi palindroome.</p>

<p>Sarnaselt arvujada juhtumiga nimetatakse teksti palindroomiks, kui see on sama eest tahapoole ja tagant ettepoole lugedes. Näiteks <code>ABBA</code> on palindroom (sest see on ka tagurpidi lugedes <code>ABBA</code>), aga <code>ABCD</code> ei ole (sest see on tagurpidi lugedes <code>DCBA</code>).</p>

<p>Kirjutada programm, mis leiab vähima võimaliku arvu täheasendustega viisi antud tekst palindroomiks muuta.</p>



## 입력


<p>Sisendi esimesel real on täisarv $N$ ($1 \le N \le 300$).</p>

<p>Teisel real on $N$ suurest ladina tähest (<code>A</code> $\ldots$ <code>Z</code>) koosnev tekst.</p>



## 출력


<p>Väljundi esimesele reale väljastada täisarv $K$, mis näitab, mitu tähte on minimaalselt vaja asendada, et sisendis antud tekstist saaks palindroom.</p>

<p>Teisele reale väljastada saadud palindroom. Kui minimaalse täheasenduste arvuga palindroome on mitu, väljastada neist (ladina tähestiku järgi) tähestikulises järjekorras esimene.</p>



## 소스코드

[소스코드 보기](Palindroom.cpp)