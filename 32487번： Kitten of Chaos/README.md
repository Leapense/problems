# 32487번: Kitten of Chaos - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32487)


<p>Karen has a beautiful precious glass object on the shelf in her living room. Unfortunately, her cat Klaus does not like it when there is stuff on his favourite shelf. Everything that is not bolted or glued in place, he will gradually push over the edge while looking Karen straight in the eyes.</p>

<p>Now, Klaus' paw slowly executes his diabolical deed. His cute fluffy face radiates inadvertent innocence. Knowing that any intervention would only delay the inevitable, Karen wonders what will happen to the string her sister Kim wrote on the precious glass object. After all, it took Kim a whole week to gather all the <code>bdpq</code> letters that make up the string.</p>

<p>Can you describe to Karen what the string will look like from her point of view while it tumbles towards destruction?</p>

<p>While falling off the shelf, Karen's precious glass object is subject to the following transformations, described as seen when looking at the object from the front.</p>

<ul>
<li><code>h</code>: horizontal flip, e.g. <code>bbq</code> becomes <code>pdd</code></li>
<li><code>v</code>: vertical flip, e.g. <code>bbq</code> becomes <code>ppd</code></li>
<li><code>r</code>: 180-degree rotation, e.g. <code>bbq</code> becomes <code>bqq</code></li>
</ul>

<p>No flips along or rotations about any other axes are possible.</p>



## 입력


<p>The input consists of:</p>

<ul>
<li>One line with a string $s$ consisting of the letters <code>bdpq</code> ($1 \le |s| \le 5\cdot 10^5$), the string printed on the glass object as seen at the start of the fall.</li>
<li>One line with a string $t$ consisting of the letters <code>hvr</code>  ($1 \le |t| \le 5\cdot 10^5$) giving the sequence of transformations in the order that they occur during the fall.</li>
</ul>



## 출력


<p>Output the string that can be seen at the moment the glass object touches the ground and just before it shatters into pieces.</p>



## 소스코드

[소스코드 보기](Kitten%20of%20Chaos.cpp)