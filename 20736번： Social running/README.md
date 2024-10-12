# 20736번: Social running - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/20736)


<p>You and a few friends are running together once a week around Lund. You all agree that it is boring and also dangerous to run on your own rather than running with others. Therefore you and your friends decide to minimize the distance that anyone needs to run on their own.</p>

<p>You are $N$ friends, who live in $N$ different locations numbered $0$ through $N-1$. Everyone will run exactly one lap going through all the locations in cyclic order (if you live in location $i$, you run $i\rightarrow i+1\pmod{N}\rightarrow\ldots\rightarrow N-1\rightarrow 0\rightarrow\ldots\rightarrow i-1\pmod{N}\rightarrow i$. Someone starts the run, then everyone joins the run as the group comes, runs exactly one lap and stops when the group comes back to their house.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/0fbc38ff-73d0-45d1-851c-0e8754b635d1/-/preview/" style="width: 150px; height: 153px;"></p>

<p>Given that an optimal person starts the run, what is the minimal total distance that anyone has to run on their own? In the above example, an optimal choice would be to start the run at location $3$. Then the first runner has to run the leg from 3 to 0 alone, and it is easily checked that your friend living in location 2 also will be running alone from 1 to 2, for a total solitary distance of $4$.</p>



## 입력


<p>The first line of the input contains the number of friends in the group, $N$ ($2\leq N\leq 10$). It is followed by $N$ lines where the $i$-th line contains a single integer, the distance from location $i$ to location $i+1\pmod{N}$. Each distance is between $1$ and $10^4$.</p>



## 출력


<p>The output consists of a single integer, the minimal total distance anyone has to run on their own, given that the optimal person starts the run.</p>



## 소스코드

[소스코드 보기](Social%20running.cpp)