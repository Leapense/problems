# 29895번: Jõululaul - <img src="https://static.solved.ac/tier_small/3.svg" style="height:20px" /> Bronze III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/29895)


<p>Tänase teise advendi puhul meenutame paarisaja aasta vanust inglise jõululaulu:</p>

<p>Jõulu <strong>esimesel</strong> päeval mu kallim saatis mul' ühe faasani pirnipuu sees.</p>

<p>Jõulu <strong>teisel</strong> päeval mu kallim saatis mul' kaks turteltuvi ja faasani pirnipuu sees.</p>

<p>Jõulu <strong>kolmandal</strong> päeval mu kallim saatis mul' kolm kirjut kana, kaks turteltuvi ja faasani pirnipuu sees.</p>

<p>Jõulu <strong>neljandal</strong> päeval mu kallim saatis mul' neli laulvat lindu, kolm kirjut kana, kaks turteltuvi ja faasani pirnipuu sees.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/522d3983-b1c9-4104-9a31-faf2da133241/-/preview/" style="width: 850px; height: 222px;"></p>

<p>Programmiharjutuste võlumaal kestavad jõulud $N$ päeva ja on olemas $N$ erinevat kingitust; tähistame nad $A_1$, $A_2$, $\ldots$, $A_N$. Jõulu $k$-ndal päeval saadab kallim mulle ühe $A_1$, kaks $A_2$, kolm $A_3$, $\dots$ ja $k$ $A_k$-te.</p>

<p>Kirjutada programm, mis leiab, mitu igat liiki kingitust kallim mulle kokku saadab.</p>



## 입력


<p>Sisendi ainsal real on täisarv $N$, võlumaa jõulude kestus päevades ($1 \le N \le 100\,000$).</p>



## 출력


<p>Väljastada täpselt $N$ rida, igale reale üks täisarv; $k$-ndale reale väljastada pühade jooksul kingiks saadud $A_k$ koguarv.</p>



## 소스코드

[소스코드 보기](Jõululaul.py)