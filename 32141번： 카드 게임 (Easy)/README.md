# 32141번: 카드 게임 (Easy) - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32141)


<p>당신은 카드 게임을 하고 있다.</p>

<p>상대의 체력은 $H$이며, 당신은 다양한 공격력을 가진 카드를 총 $N$개 가지고 있다. 만약 어떤 카드를 사용하여 공격하면, 상대의 체력은 그 카드의 공격력만큼 줄어든다. 체력이 $0$ 이하가 되면 죽는다.</p>

<p>당신은 상대를 <strong>최대한 늦게</strong> 죽이기 위해 최대한 많은 카드를 사용하여 상대를 죽이려고 한다. 카드의 공격력이 오름차순으로 주어질 때, 최대 몇 개의 카드를 사용할 수 있는지 구하여라. 각 카드는 한 번만 사용할 수 있다.</p>



## 입력


<p>첫 번째 줄에 카드의 수 $N$과 상대의 체력 $H$가 공백으로 구분되어 주어진다.</p>

<p>두 번째 줄에 $N$개의 카드의 공격력 $d_i$가 오름차순으로 공백으로 구분되어 주어진다.</p>

<p>입력으로 주어지는 모든 수는 정수이다.</p>



## 출력


<p>첫 번째 줄에 상대를 죽이기 위해 사용할 수 있는 카드의 최대 개수를 출력하여라.</p>

<p>만약 모든 카드를 사용해도 죽일 수 없다면 $-1$을 출력하여라.</p>



## 소스코드

[소스코드 보기](카드%20게임%20(Easy).py)