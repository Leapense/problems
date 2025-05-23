# 11035번: SÀNG - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11035)


<p>Sàng của Eratosthenes là thuật toán nổi tiếng để tìm tất cả các số nguyên tố nhỏ hơn N. Thuật toán như sau:&nbsp;</p>

<ol>
<li>Ghi ra tất cả các số nguyên giữa 2 và N.&nbsp;</li>
<li>Tìm số nhỏ nhất chưa bị gạch và gọi nó là P (P là số nguyên tố).&nbsp;</li>
<li>Gạch bỏ P và tất cả các bội số của nó mà chưa bị gạch.&nbsp;</li>
<li>Nếu còn số chưa bị gạch bỏ, chuyển sang bước 2.&nbsp;</li>
</ol>

<p>Viết một chương trình, cho N và K, tìm số nguyên thứ K bị gạch.</p>



## 입력


<p>Gồm nhiều bộ test, mỗi bộ test nằm trên một dòng gồm các số nguyên N và K (2 ≤ K &lt; N ≤ 1000).&nbsp;</p>



## 출력


<p>Với mỗi test, in ra trên một dòng số thứ K bị gạch bỏ.</p>



## 소스코드

[소스코드 보기](SÀNG.cpp)