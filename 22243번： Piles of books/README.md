# 22243번: Piles of books - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/22243)


<p>A large number of books have arrived to the library of the Aglargond School of Magic and they need to be arranged on the shelves. On the library floor, tiled with equal square tiles, librarians marked a square‐shaped area (length of the side of this square is N square tiles) for temporary storage of the books. Books were either stacked on top of the other books or on the empty tiles in the marked area in such fashion that a stack of books is formed on some tiles. The youngest student got an assignment to enter information about every book into the catalogue and arrange the books to their shelves. After hearing this news he just stood beside the books and sighed burdened by the amount of work he had to do. Going alongside the edges of the marked area he looks in directions parallel to sides of the marked area and counts stacks of books visible. A stack is visible if there is no higher stack or stack with equal height between it and the student. Write a program&nbsp;that counts the number of stacks visible to the young magician while walking beside the books.</p>



## 입력


<p>The first line of input contains length of the side of the marked area, N (1&nbsp;≤&nbsp;N&nbsp;≤&nbsp;50). Each of the next N lines contains N non‐negative integers not greater than 1000 separated by single space character, representing heights of stacks (in cm) of books on each floor tile. If there are no books on a tile, height of the stack is 0.</p>



## 출력


<p>The output should contain the number of visible stacks.</p>



## 소스코드

[소스코드 보기](Piles%20of%20books.cpp)