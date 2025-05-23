# 16390번: Sheba’s Amoebas - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/16390)


<p>After a successful Kickstarter campaign, Sheba Arriba has raised enough money for her mail-order biology supply company. “Sheba’s Amoebas” can ship Petri dishes already populated with a colony of those tiny one-celled organisms. However, Sheba needs to be able to verify the number of amoebas her company sends out. For each dish she has a black-and-white image that has been pre-processed to show each amoeba as a simple closed loop of black pixels. (A loop is a minimal set of black pixels in which each pixel is adjacent to exactly two other pixels in the set; adjacent means sharing an edge or corner of a pixel.) All black pixels in the image belong to some loop.</p>

<p>Sheba would like you to write a program that counts the closed loops in a rectangular array of black and white pixels. No two closed loops in the image touch or overlap. One particularly nasty species of cannibalistic amoeba is known to surround and engulf its neighbors; consequently there may be amoebas within amoebas. For instance, each of the images in Figure G.1 contains four amoebas.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/10d1900a-1988-4679-b9dc-e451888e3da5/-/preview/" style="width: 300px; height: 154px;"></p>

<p style="text-align: center;">Figure G.1: Two Petri dishes, each with four amoebas.</p>



## 입력


<p>The first line of input contains two integers m and n, (1 ≤ m, n ≤ 100). This is followed by m lines, each containing n characters. A ‘<code>#</code>’ denotes a black pixel, a ‘<code>.</code>’ denotes a white pixel. For every black pixel, exactly two of its eight neighbors are also black.</p>



## 출력


<p>Display a single integer representing the number of loops in the input.</p>



## 소스코드

[소스코드 보기](Sheba’s%20Amoebas.cpp)