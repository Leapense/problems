# 7734번: Vista 0 - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7734)


<p>One day a large unnamed company in Prague decided to install a new operating system (made by another unnamed large company in USA) on all of their computers. Everybody was excited, because the company which made the OS was very famous and there were many advertisements of the OS, so it must be the best OS ever. Only the main network administrator didn’t share their enthusiasm. And his doubts had soon been fulfilled. While installing the new OS on the last computer, all of the other computers got frozen and they weren’t able to get controlled remotely. The poor administrator has now no other chance to wake them up than go physically to each of the computers and restart them manually.</p>

<p>Please help the poor administrator and recommend him an order in which he should visit the computers and return to the computer he started with (hopefully not to start another round of reboots there). You know the position of each computer given by two coordinates \(x\) and \(y\). All computers are in the plane and the distance between any pair of them is given by the Euclidean metric; i.e. the distance between computers with coordinates (\(x_1\), \(y_1\)) and (\(x_2\), \(y_2\)) is equal to \(\sqrt{(x_1-x_2)^2+(y_1-y_2)^2}\).</p>



## 입력


<p>The first line of the input contains one integer \(N\) (1 ≤ \(N\) ≤ 1 000 000), the number of computers. Then \(N\) lines follow and the \(i\)-th line contains two whole numbers&nbsp;\(x_i\), \(y_i\) (0 ≤ \(x_i\), \(y_i\)&nbsp;≤ 1 000 000) – the coordinates of the \(i\)-th computer. The computers are placed at distinct locations.</p>



## 출력


<p>The output should contain \(N\) + 1 lines containing the numbers of computers in the order of the recommended journey. The last computer must be the same as the first one. The circuit can start at any computer.</p>



## 소스코드

[소스코드 보기](Vista%200.cpp)