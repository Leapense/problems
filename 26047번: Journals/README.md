# 26047번: Journals - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26047)


<p>There is a stack of journals on Cimrman’s desk. The journals are printed in Cimrman’s own printing house. Each journal front cover is charged slightly positively and the back cover is charged slightly negatively. Different charges of the front and back cover help the journals to stick better to each other when they are stacked in a single stack one upon another. When two adjacent journals in the stack are positioned in such a way that either their front covers or their back covers touch each other, the repulsion between the same charges in both covers makes the stack more prone to collapse.</p>

<p>Cimrman wants his stack to be arranged in such a way that no two adjacent journals in the stack produce the repulsion.</p>

<p>To set the stack into appropriate order he can repeat a single operation consisting of three moves. In the first move (which may be empty), Cimrman puts aside some number of journals from the top of the stack without changing their order. Next, he takes a pile of one or more journals from the new top of the stack, flips this pile over, and puts it back on the stack. Finally, he moves back onto the stack the journals removed from the stack in the first step. Again, no change of the journal order appears in this move.</p>

<p>Obviously, Cimrman wants to perform as few operations as possible. The number of journals moved or flipped in one operation is not important, the journals paper is light enough.</p>



## 입력


<p>The journals’ front and back covers are represented by signs plus or minus (’+’ or ’-’) in the input. The single line of input contains K (1 ≤ K ≤ 10<sup>5</sup>) plus signs and K minus signs without spaces between them. The input corresponds to the original orientation of the journals on the stack.</p>



## 출력


<p>Print the minimal number of operations to be performed to achieve a stack where no two adjacent journals produce the repulsion.</p>



## 소스코드

[소스코드 보기](Main.java)