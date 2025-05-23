# 31559번: Cannonball - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31559)


<p>Bessie has mastered the art of turning into a cannonball and bouncing along a number line of length $N$ $(1 \leq N \leq 10^5)$ with locations numbered $1,2,\dots,N$ from left to right. She starts at some integer location $S$ $(1 \leq S \leq N)$ bouncing to the right with a starting power of $1$. If Bessie has power $k$, her next bounce will be at a distance $k$ forward from her current location.</p>

<p>Every integer location from $1$ to $N$ is either a target or a jump pad. Each target and jump pad has an integer value in the range $0$ to $N$ inclusive. A jump pad with a value of $v$ increases Bessie's power by $v$ and reverses her direction. A target with a value of $v$ will be broken if landed on with a power of at least $v$. Landing on a target does not change Bessie's power or direction. A target that is broken will remain broken and Bessie can still bounce on it, also without changing power or direction.</p>

<p>If Bessie bounces for an infinite amount of time or until she leaves the number line, how many targets will she break?</p>

<p>If Bessie starts on a target that she can break, she will immediately do so. Similarly, if Bessie starts on a jump pad, the pad's effects will be applied before her first jump.</p>



## 입력


<p>The first line of the input contains $N$ and $S$, where $N$ is the length of the number line and $S$ is Bessie's starting location.</p>

<p>The next $N$ lines describe each of the locations. The $i$th of these lines contains integers $q_i$ and $v_i$, where $q_i = 0$ if location $i$ is a jump pad and $q_i = 1$ if location $i$ is a target, and where $v_i$ is the value of location $i$.</p>



## 출력


Output one number representing the number of targets that will be broken.



## 소스코드

[소스코드 보기](Cannonball.py)