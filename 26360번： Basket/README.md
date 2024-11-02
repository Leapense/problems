# 26360번: Basket - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26360)


<p>Perica programira simulaciju koju će košarkaški suci koristiti za online učenje pravila košarkaške igre. Jedna od situacija koja se pojavljuje tijekom igre opisana je na sljedeći način:</p>

<ul>
<li>igrač ekipe koja je u napadu šutira, tj. baca loptu prema košu. Ako igrač pogodi koš, sudac njegovoj ekipi dodjeljuje X poena. Ako igrač ne pogodi, ekipa ne dobija poene za taj šut.</li>
<li>dodatno, igrač u trenutku upućivanja lopte prema košu može biti nepropisno zaustavljen od strane protivničkog igrača. Ako se to dogodi, sudac prvo sačeka hoće li igrač pogoditi koš i onda donese dodatnu odluku:
<ul>
<li>igrač je pogodio koš - sudac igraču dodjeljuje još jedno dodatno bacanje u koš;</li>
<li>igrač nije pogodio koš - sudac igraču dodijeljuje još X dodatnih bacanja.</li>
</ul>
</li>
</ul>

<p>Igrač svako dodatno bacanje može pogoditi ili promašiti. Za svako pogođeno bacanje sudac ekipi dodjeljuje jedan poen.</p>

<p>Za testiranje simulacije, Perica je pripremio jednu probnu situaciju. Napiši program koji će ispisati koliko je poena imala ekipa nakon odigrane situacije.</p>



## 입력


<p>U prvom je retku prirodan broj X (2 ≤ X ≤ 10), broj iz teksta zadatka.</p>

<p>U drugom je retku cijeli broj 0 ili 1. Nula – igrač je promašio; jedan – igrač je pogodio šut za X poena.</p>

<p>U trećem je retku cijeli broj 0 ili 1. Jedan – igrač je prilikom izvođenja šuta za X poena nepropisno zaustavljen; nula – igrač nije nepropisno zaustavljen.</p>

<p>Ovisno o vrijednostima u drugom i trećem retku slijedi nula, jedan ili X redaka nula ili jedinica. Jedinica označava da je igrač pogodio dodatno bacanje, a nula da igrač nije pogodio dodatno bacanje.</p>



## 출력


<p>U jedini redak ispiši broj poena iz teksta zadatka.</p>



## 소스코드

[소스코드 보기](Basket.cpp)