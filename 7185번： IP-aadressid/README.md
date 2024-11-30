# 7185번: IP-aadressid - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7185)


<p>Matil on veebileht ning ta tahab täpselt teada, kes tema lehte külastavad. Külastajate jälgimiseks koostas Mati skripti, mis töötab järgmiselt:</p>

<ul>
<li>kõigi seni nähtud külastajate IP-aadresse hoitakse tekstifailis;</li>
<li>iga uue päringu (külastaja) saabumisel kontrollitakse programmi <code>grep</code> abil IP-aadressi esinemist tekstifailis (<code>grep</code> <em>uusIP</em> <em>fail</em>);</li>
<li>kui vastavusi ei leitud, lisatakse uus aadress faili lõppu ja saadetakse Matile teavitus;</li>
<li>muudel juhtudel ei tehta midagi.</li>
</ul>

<p>IP-aadress on sõne, mis koosneb neljast täisarvust vahemikus $0 \ldots 255$ ning punktidest nende vahel.</p>

<p>Programm <code>grep</code> on levinud töövahend regulaaravaldistega kirjeldatud mustrite otsimiseks teksti\-failidest. Antud juhul kasutab Mati programmi <code>grep</code> valesti, sest:</p>

<ul>
<li><code>grep</code> otsib alamsõnesid: otsitav muster ei pea algama tingimata rea alguses ega lõppema rea lõpus;</li>
<li>otsitavat mustrit tõlgendatakse regulaaravaldisena ning seetõttu võib otsitava IP-aadressi punktile vastata tekstifailis suvaline sümbol (kuid mitte vastupidi).</li>
</ul>

<p>On antud kõigi Mati skripti poolt töödeldud IP-aadresside loetelu (töötlemise järjekorras). Tuvastada, millised aadressid jättis Mati skript ekslikult faili lisamata.</p>



## 입력


<p>Tekstifaili esimesel real on üks täisarv: IP-aadresside arv $N$  ($1 \le N \le 1\,000\,000$). Järgmisel $N$ real on igaühel üks IP-aadress. Sisendis võib esineda korduvaid aadresse, erinevate aadresside koguarv üheski testis ei ole suurem kui $2\,000$.</p>



## 출력


<p>Tekstifaili esimesele reale väljastada lisamata jäänud aadresside arv $V$ ning järgmisele $V$ reale lisamata jäänud aadressid nende esimist korda sisendfailis esinemise järjekorras.</p>



## 소스코드

[소스코드 보기](IP-aadressid.cpp)