# 26941번: Pyramidbygge - <img src="https://static.solved.ac/tier_small/3.svg" style="height:20px" /> Bronze III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26941)


<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/99987025-e52d-4f98-a15f-87a0caa1c4dd/-/preview/" style="width: 200px; height: 123px;"></p>

<p style="text-align: center;">Figure 1: Ett exempel på en pyramid av höjd 3 med 35 block.</p>

<p>När man ska inleda ett större projekt, exempelvis bygga en pyramid, är det bäst att tänka efter en gång extra. Du ska skriva ett program som beräknar hur hög pyramid man kan bygga om man har tillgång till ett visst antal stenblock.</p>

<p>Vi antar att pyramiden är kompakt, d.v.s. det finns inga hålrum inuti. Vidare byggs den enligt principen i figure 1. Varje lager är alltså kvadratiskt med en sidlängd som är två block mindre än det underliggande lagrets. Det översta lagret består alltid av ett ensamt block.</p>

<p>Det gör ingenting om det blir block över, men det får inte saknas ett enda block.</p>



## 입력


<p>Indata består av ett enda heltal $N$ ($1 \le N \le 100\,000\,000$): antal tillgängliga block.</p>



## 출력


<p>Programmet ska skriva ut en rad med ett heltal: höjden för den största pyramid som kan byggas med som högst $N$ block.</p>



## 소스코드

[소스코드 보기](Pyramidbygge.py)