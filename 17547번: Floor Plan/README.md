# 17547번: Floor Plan - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/17547)


<p>You are an architect and you have just been appointed to build a new swimming hall. The organisation behind these plans has acquired funding for a swimming pool and surrounding building as large as they want, but unfortunately they could not find anyone willing to pay for the floor surrounding the pool. They decided to pay for the floor tiles out of their own pocket. Because this has already cost them an arm and a leg, they want you to use all the floor tiles in your proposed plan.</p>

<p>Being an architect, you care for aesthetics. You see it as absolutely vital that both the swimming pool and the surrounding building are perfect squares. This raises an interesting problem: how can you make sure that the square shapes are guaranteed, while still using all the floor tiles the organisation bought?</p>

<p>Given the number of tiles n, find the length of the side of the building m and and the length of the side of the pool k such that n = m<sup>2</sup> − k<sup>2</sup>, or print impossible if no suitable m and k exist.</p>



## 입력


<ul>
<li>One line containing a single integer 1 ≤ n ≤ 10<sup>9</sup>.</li>
</ul>



## 출력


<p>Print two non-negative integers m, k such that n = m<sup>2</sup> − k<sup>2</sup>, or print impossible if no such integers exist. If there are multiple valid solutions, you may output any one of them.</p>



## 소스코드

[소스코드 보기](Floor%20Plan.cpp)