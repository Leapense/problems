# 20847번: Födelsedagsmemorisering - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/20847)


<p>Krarkl vill lära sig alla sina $N$ kompisars födelsedagar utantill, så att han varje dag vet vem han ska gratta. Tyvärr så uppstår det ofta krockar, det vill säga flera kompisar som fyller år på samma dag. Det här gör Krarkl förvirrad, så han bestämmer sig för att för varje datum som har en krock bara komma ihåg födelsedagen för den kompis han tycker mest om. Givet en lista med födelsedagen för varje kompis och hur mycket Krarkl tycker om kompisen, skriv ut vilka kompisar Krarkl kommer minnas födelsedagen för.</p>



## 입력


<p>Den första raden i indata innehåller heltalet $N$ ($1 \leq N \leq 2\,000$), antalet kompisar.</p>

<p>Sedan följer $N$ rader, en för varje kompis. Den $i$:te raden består av en sträng med den $i$:te kompisens förnamn, $S_i$ ($S_i$ är mellan $1$ och $10$ tecken lång), ett heltal $C_i$ ($0 \leq C_i \leq 100\,000$) som säger hur mycket Krarkl gillar kompisen samt kompisens födelsedag på formatet <code>DD/MM</code> (där <code>DD</code> är en dag mellan <code>01</code> och <code>31</code> och <code>MM</code> är en månad mellan <code>01</code> och <code>12</code>). Ett högre värde på $C_i$ betyder att Krarkl gillar kompisen mer.</p>

<p>Födelsedagarna kommer att vara riktiga datum under 2020 (ett skottår), t.ex. <code>28/02</code> för den tjugoåttonde februari. Namnen kommer bestå av enbart små engelska bokstäver (<code>a-z</code>), med stor första bokstav (<code>A-Z</code>). Alla $C_i$ kommer att vara olika.</p>



## 출력


<p>Du ska skriva ut en rad med ett heltal $K$, antalet kompisar vars födelsedag Krarkl kommer minnas.</p>

<p>Den ska följas av $K$ rader med ett ord vardera, förnamnen på de utvalda kompisarna, <strong>i alfabetisk ordning</strong>.</p>



## 소스코드

[소스코드 보기](Födelsedagsmemorisering.cpp)