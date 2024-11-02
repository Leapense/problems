# 8735번: Obwody - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8735)


<p>Jaś na urodziny dostał komplet magicznych elektrycznych kabelków. Każdy kabelek składa się z drutu oraz bateryjki. <em>i</em>-ty drut może wytrzymać napięcie <em>d<sub>i</sub></em>&nbsp;woltów, a&nbsp;<em>i</em>-ta bateryjka ma napięcie&nbsp;<em>b<sub>i</sub></em>&nbsp;woltów.</p>

<p>Jasio buduje z kabelków obwody: wybiera druty, skręca je razem tworząc grubszy drut i robi z niego kółko. W kółku napięcie jest sumą napięć wszystkich bateryjek, a skręcony drut może wytrzymać napięcie będące sumą napięć, które mogą wytrzymać poszczególne druty.</p>

<p>Jaś buduje obwód tak, aby zrobione kółko nie przepaliło się. Z ilu maksymalnie kabelków może się ono składać?</p>



## 입력


<p>W pierwszym wierszu wejścia znajduje się jedna liczba całkowita <em>n</em>&nbsp;(1 ≤ <em>n</em> ≤ 500 000), oznaczająca liczę drutów. W&nbsp;<em>n</em>&nbsp;następnych linijkach pary liczb <em>d<sub>i</sub></em>,&nbsp;<em>b<sub>i</sub></em>&nbsp;opisujące kolejne druty (0 ≤ <em>d<sub>i</sub></em>, <em>b<sub>i</sub></em> ≤ 10<sup>6</sup>).</p>



## 출력


<p>W jedynej linijce powinna znaleźć się liczba całkowita oznaczająca maksymalna liczbę drutów tworzących kółko.</p>



## 소스코드

[소스코드 보기](Obwody.cpp)