# 33092번: Obstacle Course - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/33092)


<p>As a businessman and parkour enthusiast, Morgan owns an obstacle course consisting of $N$ road segments numbered from $1$ to $N$. These road segments are arranged sequentially such that road $1$ is adjacent to road $2$, road $2$ is adjacent to road $3$, ..., road $N - 1$ is adjacent to road $N$. Currently, each odd-numbered road segment has a height of a positive integer $A_i$, and each even-numbered road segment has a height of $0$. In Morgan’s course, anyone can start from any road segment, parkour towards one direction, and stop at any road segment as long as they can reach that road segment.</p>

<p>As a beginner athlete, Adrian thinks that Morgan’s obstacle course may be too hard due to the height difference between any two consecutive roads. Adrian enjoys doing parkour whenever the height difference between two consecutive roads is exactly $1$. If the next road segment has a difference of more than $1$ from the current road segment, then Adrian cannot climb or jump down to the next road segment and will stop his parkour activity. On the other hand, if the next road segment has the same height as the current road segment, then Adrian will lose interest and stop his parkour activity. He will also stop his parkour activity if he reaches the end of the obstacle course, i.e. road segment $N$ or road segment $1$.</p>

<p>As his friend, Morgan wants Adrian to be happy with the course. Adrian’s happiness is defined as the number of road segments that he parkoured before he lost interest and stops his parkour activity. Adrian will start from any road segment that will give him the largest happiness. Based on these facts, Morgan decided to change the heights of some (possibly none) <strong>even-numbered</strong> road segments such that Adrian’s largest happiness for the course is maximized. However, before he makes any changes, he asked you to determine the largest possible Adrian’s happiness that can be obtained after changing the height.</p>

<p>For example, let $A_{1..9} = [6, 0, 4, 0, 8, 0, 12, 0, 14]$. By changing $A$ into $[6, 5, 4, 5, 8, 11, 12, 13, 14]$, Adrian can do parkour from segment $1$ to $4$ or from segment $6$ to $9$, and his happiness will be $4$, which is also the largest happiness after that change. There are some other changes that can make Adrian’s largest happiness equal to $4$ as well, e.g. $[6, 5, 4, 3, 8, 7, 12, 12, 14]$, but no change can make Adrian’s largest happiness larger than $4$.</p>

<p>Help Morgan to determine the largest possible Adrian’s happiness in his new course.</p>



## 입력


<p>Input begins with an integer $N$ ($2 ≤ N ≤ 100\, 000$) representing the number of road segments. The next line contains $N$ integers $A_i$ ($A_i = 0$ if $i$ is even; $1 ≤ A_i ≤ 100\, 000$ if $i$ is odd) representing the height of segment $i$ from $1$ to $N$ respectively.</p>



## 출력


<p>Output an integer in a single line that represents the largest possible Adrian’s happiness in Morgan’s new course.</p>



## 소스코드

[소스코드 보기](Obstacle%20Course.py)