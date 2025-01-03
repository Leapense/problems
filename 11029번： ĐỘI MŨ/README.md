# 11029번: ĐỘI MŨ - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11029)


<p>Từ xưa đến nay, việc phân chia học sinh vào từng khoa của trường Hogwart được thực hiện bởi những chiếc mũ phép thuật. Trước kia, trường có 4 khoa. Tuy nhiên, sau khi tái cơ cấu lại trường, số khoa thay đổi thành p. Những chiếc mũ vẫn được sử dụng để phân chia học sinh.&nbsp;</p>

<p>Kế hoạch phân chia học sinh vào từng khoa được biểu diễn bằng dãy số a[1], a[2],..., a[k], trong đó a[i] là khoa mà học sinh i sẽ học.&nbsp;</p>

<p>Cách phân chia học sinh của chiếc mũ được mô tả như sau: Các khoa trong trường được đánh số từ 0 đến p – 1. Gọi next(x) là khoa kế tiếp của khoa x với next(x) = x+1 với x &lt; p -1 và next(p-1) = 0. Kế hoạch phân chia được bắt đầu bằng một dãy số có duy nhất 1 phần tử 0. Sau mỗi bước, dãy a với k phần tử sẽ trở thành dãy số mới có 2k phần từ a[1], a[2],..., a[k], next(a[1]), next(a[2]),..., next(a[k]).&nbsp;</p>

<p>Xét ví dụ về việc phân chia 9 học sinh vào 4 khoa. Chiếc mũ sẽ thực hiện theo kế hoạch: (0), (0, 1), (0, 1, 1, 2), (0, 1, 1, 2, 1, 2, 2, 3), (0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 0),... Độ dài của dãy cuối đủ cho 9 học sinh.&nbsp;</p>

<p>Cho các cặp số p, n. Nhiệm vụ của bạn là cho biết khoa nào trong số p khoa của trường mà học sinh thứ n sẽ vào học ở đó (học sinh được đánh số từ 1)</p>



## 입력


<p>Dòng đầu là số truy vấn Q (1 ≤ Q ≤ 310000). Q dòng tiếp, mỗi dòng là một cặp số p, n (1 ≤ n ≤ 10<sup>18</sup>, 2 ≤ p ≤ 10<sup>18</sup>)</p>



## 출력


<p>In ra Q dòng lần lượt là đáp án của Q truy vấn</p>



## 소스코드

[소스코드 보기](ĐỘI%20MŨ.cpp)