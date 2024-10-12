# 7201번: Intressid - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7201)


<p>Vana-aasta õhtul andis Juhan endale lubaduse, et kohe järgmise aasta alguses avab ta kogumishoiuse, kuhu hakkab iga kuu lõpus kandma $D$ eurot. Juhani netopalk ehk reaalselt kätte saadav kuupalk on $P$ eurot. Pank pakub hoiuse eest intresse $N$ protsenti aastas. Nüüd tahab Juhan teada, mitu aastat peab ta raha koguma, et saaks hakata panga poolt makstavatest intressidest elama.</p>

<p>Pank maksab intresse korra aastas aasta viimasel päeval. Kui intressidest äraelamiseks ei piisa, kannab Juhan talle välja makstud intressid hoiusele juba samal päeval. Juhan suudab intressidest ära elada alles siis, kui need ületavad tema aastased kulud. Näiteks, kui Juhan teenib $500$ eurot kuus, millest $200$ eurot paneb ta igas kuus kõrvale, vajab ta äraelamiseks vähemalt $3600$ eurot aastas.</p>

<p>Raha eest, mis oli hoiusel juba aasta alguses, maksab pank intressi $N$ protsenti. Aasta jooksul lisanduvate summade eest maksab pank intressi raha hoiusel hoidmise täiskuude kaupa (detsembris hoiusele lisatud raha eest intressi ei maksta, novembris lisatud raha eest makstakse ühe kuu intressid j.n.e). Ühe kuu jooksul hoiustamise intressim äär $M$ arvutatakse valemiga $((1 + \frac{N}{100})^\frac{1}{12} - 1) \cdot 100\%$. K kuu intressimäär arvutatakse valemiga $((1 + \frac{M}{100})^K - 1) \cdot 100\%$. Aasta intresside kogusumma ümardatakse sendi täpsuseni ning makstakse Juhanile välja.</p>



## 입력


<p>Tekstifaili ainsal real on kolm tühikutega eraldatud reaalarvu $P$, $D$ ja $N$ ($P ≤ 10^6$, $0 &lt; D &lt; P$, $0 &lt; N \le 100$). Kõik arvud on antud täpsusega kuni $2$ kohta pärast koma.</p>



## 출력


<p>Tekstifaili ainsale reale väljastada üks täisarv: aastate arv, mille jooksul peab Juhan veel t¨o¨ol käima.</p>



## 소스코드

[소스코드 보기](Intressid.cpp)