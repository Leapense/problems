# 5992번: The Leisurely Stroll - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/5992)


<p>Bessie looks out the barn door at the beautiful spring day and thinks to herself, "I'd really like to enjoy my walk out to the pastures for the tender spring grass." She knows that once she leaves the barn, she will traverse a path for a while, take one of two choices that lead to other paths, follow one of them, take one of two other choices, and continue on until the path leads to a verdant pasture.</p>

<p>She decides to make the set of path choices that enables her to walk over the greatest number of cow paths on her way to breakfast. Given the description of these paths, determine how many cow paths she traverses, presuming that she commences choosing various paths as soon as she leaves the barn.</p>

<p>The farm has P (1 &lt;= P &lt;= 1,000) pastures that are lead to by P-1 choice-nodes (range 1..P-1) connected by paths. From the barn (which is node 1), only one set of path traversals exists to reach any choice-node or pasture.</p>

<p>Consider this set of paths (lines), pastures ('%'), and the highlighted ('#') route to a pasture on the right:</p>

<pre>                 %                             %
                /                             /
      2----%   7----8----%          2----%   7####8----%
     / \      /      \             # #      #      #
    1   5----6        9----%      1   5####6        9----%
     \   \    \        \           \   \    \        #
      \   %    %        %           \   %    %        %
       \                             \
        3-----%                       3-----%
         \                             \
          4----%                        4----%
           \                             \
            %                             %</pre>

<p>The pasture reached from choice-node 9 is one of two that enable Bessie to traverse seven different cowpaths on the way to breakfast. These are the 'furthest' pastures from node 1, the barn.</p>

<p>Three integers describe each node: Cn, D1, and D2. Cn is the nodenumber (1 &lt;= Cn &lt;= P-1); D1 and D2 are the destinations from that node (0 &lt;= D1 &lt;= P-1; 0 &lt;= D2 &lt;= P-1). If D1 is 0, the node leads to a pasture in that direction; D2 has the same property.</p>



## 입력


<ul>
<li>Line 1: A single integer: P</li>
<li>Lines 2..P: Line i+1 contains three space-separated integeres that describe a choice-node: Cn, D1, and D2</li>
</ul>

<p>&nbsp;</p>



## 출력


<ul>
<li>Line 1: A single integer that is the largest number of paths Bessie can traverse on the way to the furthest pasture.</li>
</ul>

<p>&nbsp;</p>



## 소스코드

[소스코드 보기](Main.java)