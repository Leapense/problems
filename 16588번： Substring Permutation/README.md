# 16588번: Substring Permutation - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/16588)


<p>Given two strings S and P, there are several ways to find whether P appears as a substring of S. The simplest one would be directly checking whether P is equal to any substring of S. As there can be O(|S|) substring of S of length |P|, this approach has O(|S| × |P|) time complexity. There is also a more sophisticated way by using knuth-morris-pratt (KMP) algorithm to solve this problem in O(|S| + |P|).</p>

<p>In this problem, you are challenged to a similar problem.</p>

<p>Given two strings S and P. Let Π(S) be the set containing all strings which are permutations of S, and Π(P) be the set containing all strings which are permutations of P. Determine whether there exists a string p ∈ Π(P) and a string s ∈ Π(S), such that p appears as a substring of s.</p>

<p>For example, let S = guru and P = rug. Then, Π(S) = {gruu, guru, guur, rguu, rugu, ruug, ugru,ugur, urgu, urug, uugr, uurg}, and Π(P) = {gru, gur, rgu, rug, ugr, urg}. Observe that the string rug in Π(P) appears as a substring of the string rugu in Π(S), i.e. [rug]u. In this example, you can also find another hp, si which satisfies the requirement, e.g., hgru, gruui, hgru, ugrui, hurg, uurgi, hgur, gurui, etc.</p>



## 입력


<p>Input contains two lines. The first line contains a string S (1 ≤ |S| ≤ 100000). The second line contains a string P (1 ≤ |P| ≤ |S| ≤ 100000). Both S and P contains only lowercase alphabetical character (a-z).</p>



## 출력


<p>Output in a line “YES” (without quotes) if there exists a string p ∈ Π(P) and a string s ∈ Π(S), such that p appears as a substring of s; otherwise, output “NO” (without quotes).</p>



## 소스코드

[소스코드 보기](Substring%20Permutation.cpp)