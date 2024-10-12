# 29875번: Imeline masin - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/29875)


<p>Jukul on imeline masin, millel on neli tulukest: punane, roheline, sinine ja kollane. Korraga põleb täpselt üks tuluke. Kui masin tööle panna, siis põleb sellel alguses punane tuluke.</p>

<p>Masinal on lisaks kaks nuppu: $0$ ja $1$. Nuppe vajutades saab muuta, missugune tuluke põleb:</p>

<ul>
<li>Kui põleb punane tuluke ja vajutada ükskõik kumba nuppu, siis hakkab põlema roheline tuluke.</li>
<li>Kui põleb roheline tuluke ja vajutada nuppu $0$, siis hakkab põlema punane tuluke. Kui aga vajutada nuppu $1$, siis hakkab põlema sinine tuluke.</li>
<li>Kui põleb sinine tuluke ja vajutada nuppu $0$, siis hakkab põlema kollane tuluke. Kui aga vajutada nuppu $1$, siis jääb põlema sinine tuluke.</li>
<li>Kui põleb kollane tuluke ja vajutada nuppu $0$, siis jääb põlema kollane tuluke. Kui aga vajutada nuppu $1$, siis hakkab põlema punane tuluke.</li>
</ul>

<p>Juku kirjutas üles ühe nupuvajutuste jada. Tema õde Juta pillas selle paberi poriloiku ja nüüd on mõned sümbolid paberil arusaamatud. Aita Jutal leida kõik võimalused, mis tuluke võiks vajutustejada lõpuks põleda.</p>



## 입력


<p>Sisendi esimesel real on nupuvajutuste arv $N$ ($1 \le N \le 10^6$).</p>

<p>Teisel real on $N$ tühikutega eraldatud täisarvu, mis on igaüks $0$, $1$ või $-1$: nupuvajutuste jada. Arv $0$ tähendab, et vajutati nuppu $0$. Arv $1$ tähendab, et vajutati nuppu $1$. Arv $-1$ tähendab, et paber on selle koha pealt märjaks saanud ja Juta ei tea, mis nuppu vajutati: see võis olla $0$ või $1$.</p>



## 출력


<p>Väljastada neli rida: üks iga tulukese kohta.</p>

<p>Esimesele reale väljastada '<code>JAH</code>', kui vajutustejada lõpuks võib põleda punane tuluke, ja '<code>EI</code>', kui see pole võimalik.</p>

<p>Teisele, kolmandale ja neljandale reale väljastada, kas vajutustejada lõpuks võib põleda roheline, sinine või kollane tuluke.</p>



## 소스코드

[소스코드 보기](Imeline%20masin.py)