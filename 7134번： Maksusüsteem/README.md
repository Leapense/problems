# 7134번: Maksusüsteem - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7134)


<p>Umeerikas otsustati hiljuti minna üle astmelisele tulumaksusüsteemile, mis koonseb $N$ maksu\-kategooriast (nummerdatud $1 \ldots N$). Igal kategoorial on maksustatava sissetuleku maht $C_i$ ja maksuprotsent $P_i$. Maksude maksmine käib järgmise süsteemiga: isik maksab oma aastasest sissetulekust esimese $C_1$ euro pealt $P_1$ protsenti, järgmise $C_2$ euro pealt $P_2$ protsenti jne. On teada, et $C_N = \infty$, ehk kogu sissetulek on maksustatud.</p>

<p>Kirjutada programm, mis arvutab $M$ kliendile nende sissetulekutele vastavad maksusummad.</p>



## 입력


<p>Tekstifaili esimesel real on maksukategooriate arv $N$ ($1 \le N \le 10^5$). Teisel real on $N - 1$ täisarvu $C_i$ ($1 \le C_i \le 10^9$), kusjuures $C_N = \infty$ pole sisendis antud. Kolmandal real on $N$ täisarvu $P_i$ ($0 \le P_i \le 100$). Neljandal real on klientide arv $M$ ($1 \le M \le 10^5$). Järgmisel $M$ real on täisarvud $S_i$ ($0 \le S_i \le 10^9$), igaüks eraldi real.</p>



## 출력


<p>Tekstifaili väljastada täpselt $M$ rida, $i.$ reale sissetuleku $S_i$ pealt makstav maksusumma. Summades väljastada täpselt kaks kohta pärast koma.</p>



## 소스코드

[소스코드 보기](Maksusüsteem.cpp)