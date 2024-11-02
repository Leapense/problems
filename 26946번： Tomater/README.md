# 26946번: Tomater - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26946)


<p>Ett intressant faktum är att omogna tomater mognar snabbare om man lägger in några redan mogna tomater bland dem. I denna uppgift ska du simulera denna process och räkna ut hur många tomater som är mogna efter en viss tid.</p>

<p>Antag att $n$ tomater ligger i en lång rad och är numrerade från $1$ till $n$. Tre av dessa tomater, nummer $t_1$, $t_2$ och $t_3$, är redan mogna när simuleringen startar vid dag $0$. Varje dag mognar de tomater som ligger precis intill en redan mogen tomat. Efter dag $1$ har alltså grannarna till de tre första mogna tomaterna mognat, efter dag $2$ har även grannarna till de som mognade under dag $1$ mognat och så vidare.</p>

<p>Skriv ett program som givet antal tomater $n$, antalet dagar $d$, och numren $t_1$, $t_2$, $t_3$, beräknar hur många tomater som är mogna efter $d$ dagar.</p>



## 입력


<p>På första raden av indata står de två talen $n$ ($3 \le n \le 100$) och $d$ ($1 \le d \le 100$).</p>

<p>På den andra raden står numren $t_1$, $t_2$ och $t_3$, alla olika och i intervallet $1 \dots n$.</p>



## 출력


<p>Skriv ut ett enda tal: antalet mogna tomater efter $d$ dagar.</p>



## 소스코드

[소스코드 보기](Tomater.cpp)