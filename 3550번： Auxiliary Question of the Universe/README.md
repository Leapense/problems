# 3550번: Auxiliary Question of the Universe - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/3550)


<p>As you probably know, scientists already discovered the Ultimate question of life, the Universe, and everything, and it is "What do you get if you multiply six by nine?". Not satisfied by this, the scientists contracted a small Magrateyan company to construct a mini-computer to find out some more specific question (they named it <em>auxiliary</em>), which can theoretically shed more light on life, the Universe or something else.</p>

<p>This computer was built, but unluckily (although not unexpectedly) the result of computation was corrupted and partially lost. Finally the computer constructors managed to receive a string, which is a part of the correct question. After thorough analysis the constructors started to believe that the original result can be reconstructed from the string by adding some letters to it without the string letters being reordered or removed. Also they believe that the correct result is an arithmetic expression (as with the Ultimate question), but since the question is auxiliary, it contains no multiplication, only addition. More precisely, it should correspond to the following grammar:</p>

<pre>&lt;expression&gt; ::= &lt;term&gt; | &lt;term&gt; <code>+</code> &lt;expression&gt;
&lt;term&gt; ::= &lt;number&gt; | <code>(</code> &lt;expression&gt; <code>)
</code>&lt;number&gt; ::= <code>0</code> ... <code>9</code> [ &lt;number&gt; ]</pre>

<p>The constructors do not want to risk again, and they need your help to give just something to their clients. They ask you to reconstruct the question based on the corrupted computer answer which they managed to retrieve.&nbsp;</p>



## 입력


<p>The input file contains exactly one line --- the corrupted auxiliary question. It is a non-empty string which is at most 1000 symbols long. This string contains only symbols <code>+</code>, <code>(</code>, <code>)</code>, and <code>0</code>, ..., <code>9</code>.</p>



## 출력


<p>Output the reconstructed auxiliary question. It's guaranteed that there exists a correct question of less than 5000 symbols and your solution must also be shorter than that. If there is more than one solution, output any one.</p>



## 소스코드

[소스코드 보기](Auxiliary%20Question%20of%20the%20Universe.cpp)