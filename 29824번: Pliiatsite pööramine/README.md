# 29824번: Pliiatsite pööramine - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/29824)


<p>Pillel on karbis üksteise kõrval $N$ pliiatsit. Need on nummerdatud vasakult paremale $1, 2, \ldots, N$.</p>

<p>Pille tahab, et kõik pliiatsid oleks karbis samapidi. Võib aga juhtuda, et mõnel pliiatsil on teritatud ots üleval, mõnel all. Siis võib Pille ühe liigutusega mingi arvu kõrvuti olevaid pliiatseid ümber pöörata. Vajadusel võib ta selliseid liigutusi teha mitu tükki.</p>

<p>Pille tahab teada, milliseid pliiatseid ta peaks pöörama, et võimalikult väikese arvu liigutustega kõik pliiatsid samapidi saada. Vajadusel võib mõnda pliiatsit ka mitu korda edasi-tagasi pöörata.</p>



## 입력


<p>Sisendi esimesel real on pliiatsite arv $N$ ($1\le N\le 1\,000$). Teisel real on täpselt $N$ tähemärki. Täht \verb't' tähendab, et üleval on pliiatsi terav ots, täht \verb'n' aga, et üleval on nüri ots.</p>



## 출력


<p>Esimesele reale väljastada liigutuste arv $M$. Järgmisele $M$ reale väljastada igaühele $A$\verb'-'$B$, mis näitab, et ühe liigutusega tuleks ümber pöörata kõik pliiatsid alates pliiatsist number $A$ ja lõpetades pliiatsiga number $B$ (pliiatsid number $A$ ja $B$ mõlemad kaasa arvatud). Ei ole tähtis, kas pööramiste lõpuks on kõigil pliiatsitel teritatud otsad üleval või all. Oluline on ainult, et kõik pliiatsid on samapidi. Kui vähima liigutuste arvuga pööramisviise on mitu, väljastada ükskõik milline neist.</p>



## 소스코드

[소스코드 보기](Pliiatsite%20pööramine.py)