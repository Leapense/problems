# 27047번: Cow Laundry - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/27047)


<p>The cows have erected clothes lines with N (1 ≤ N ≤ 1000) wires upon which they can dry their clothes after washing them.  Having no opposable thumbs, they have thoroughly botched the job.  Consider this clothes line arrangement with four wires:</p>

<pre>   Wire slot: 1   2    3    4
              ---------------   &lt;-- the holder of the wires
              \    \  /    /
               \    \/    /
                \   /\   /       
                 \ /  \ /       &lt;-- actual clothes lines
                  /    \
                 / \  / \
                /   \/   \
               /    /\    \
              /    /  \    \
              ---------------   &lt;-- the holder of the wires
   Wire slot: 1   2    3    4</pre>

<p>The wires cross!  This is, of course, unacceptable.</p>

<p>The cows want to unscramble the clothes lines with a minimum of hassle.  Even their bovine minds can handle the notion of "swap these two lines".  Since the cows have short arms they are limited to swapping adjacent pairs of wire endpoints on either the top or bottom holder. In the diagram above, it requires four such swaps in order to get a proper arrangement for the clothes line:</p>

<pre>              1   2   3   4
              -------------   &lt;-- the holder of the wires
              |   |   |   |
              |   |   |   |
              |   |   |   |
              |   |   |   |
              |   |   |   |
              |   |   |   |
              |   |   |   |
              |   |   |   |
              |   |   |   |
              -------------   &lt;-- the holder of the wires
              1   2   3   4</pre>

<p>Help the cows unscramble their clothes lines.  Find the smallest number of swaps that will get the clothes line into a proper arrangement.</p>

<p>You are supplied with clothes line descriptions that use integers to describe the current ordering of the clothesline. The lines are uniquely numbered 1..N according to no apparent scheme.  You are given the order of the wires as they appear in the N connecting slots of the top wire holder and also the order of the wires as they appear on the bottom wire holder.</p>



## 입력


<ul>
<li>Line 1: A single integer: N</li>
<li>Lines 2..N+1: Each line contains two integers in the range 1..N. The first integer is the wire ID of the wire in the top wire holder; the second integer is the wire ID of the wire in the bottom holder. Line 2 describes the wires connected to top slot 1 and bottom slot 1, respectively; line 3 describes the wires connected to top and bottom slot 2, respectively; and so on.</li>
</ul>



## 출력


<ul>
<li>Line 1: A single integer specifying the minimum number of adjacent swaps required to straighten out the clothes lines.</li>
</ul>



## 소스코드

[소스코드 보기](Cow%20Laundry.py)