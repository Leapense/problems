# 33651번: Vandalism - <img src="https://static.solved.ac/tier_small/2.svg" style="height:20px" /> Bronze IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/33651)


<p>In recent weeks, the United Association against Property Crime (UAPC) sign has been repeatedly vandalized. Vandals remove some of the letters from <code>UAPC</code> to form an acronym of their choosing. For example, last month, the Unauthorized Art Collective (UAC) removed the letter <code>P</code>.</p>

<p>The UAPC is tired of manually determining which letters have been lost and need replacement. They have tasked you with creating an algorithm to automatically identify the missing letters.</p>



## 입력


<p>The first line of input contains a string $s$ of length at most $3$. It is guaranteed that $s$ is non-empty and can be obtained by removing some characters from <code>UAPC</code>, while preserving the order of the remaining letters. It is guaranteed that at least one character has been removed.</p>



## 출력


<p>Output a string consisting of the characters removed from <code>UAPC</code> to obtain $s$, listed in the order they appear in <code>UAPC</code>.</p>



## 소스코드

[소스코드 보기](Vandalism.py)