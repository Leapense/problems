# 9449번: Garage - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9449)


<p>Wow! What a lucky day! Your company has just won a social contract for building a garage complex. Almost all formalities are done: contract payment is already transferred to your account.</p>

<p>So now it is the right time to read the contract. Okay, there is a sandlot in the form of W × H rectangle and you have to place some garages there. Garages are w × h rectangles and their edges must be parallel to the corresponding edges of the sandlot (you may not rotate garages, even by 90<sup>◦</sup>). The coordinates of garages may be non-integer.</p>

<p>You know that the economy must be economical, so you decided to place as few garages as possible. Unfortunately, there is an opposite requirement in the contract: placing maximum possible number of garages.</p>

<p>Now let’s see how these requirements are checked. . . The plan is accepted if it is impossible to add a new garage without moving the other garages (the new garage must also have edges parallel to corresponding sandlot edges).</p>

<p style="text-align: center;"><img alt="" src="https://www.acmicpc.net/upload/images2/garage.png" style="height:111px; width:676px"></p>

<p>Time is money, find the minimal number of garages that must be ordered, so that you can place them on the sandlot and there is no place for an extra garage.</p>



## 입력


<p>The only line contains four integers: W, H, w, h — dimensions of sandlot and garage in meters. You may assume that 1 ≤ w ≤ W ≤ 30 000 and 1 ≤ h ≤ H ≤ 30 000.</p>



## 출력


<p>Output the optimal number of garages.</p>



## 소스코드

[소스코드 보기](Garage.cpp)