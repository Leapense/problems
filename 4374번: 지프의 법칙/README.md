# 4374번: 지프의 법칙 - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4374)


<p>
하버드 대학교의 언어학자 조지 킹슬리 지프(George Kingsley Zpif, 1902–1950)는 어떤 책에서 k번째로 많이 나온 단어의 출현 빈도는 1/k에 비례한다는 것을 발견했다.</p>

<p>
어떤 영어 책의 본문이 주어졌을 때, n번 등장하는 단어를 모두 찾는 프로그램을 작성하시오. 단어는 문자의 연속이다. 단어는 문자가 아닌 것으로 구분되어 있다. 대소문자는 구분하지 않는다. 단어는 영어 단어 사전에 나오는 단어만 주어진다.</p>



## 입력


<p>
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 n이 주어진다. 그 다음 줄부터 "EndOfText"가 니오는 바로 전 줄까지가 책의 본문 내용이다. 본문은 10000 단어를 넘지 않는다. "EndOfText"는 테스트 케이스를 구분하기 위한 단어이고, 본문에는 등장하지 않는다.</p>



## 출력


<p>
각 테스트 케이스에 대해서, n번 등장하는 단어를 사전순으로 한 줄에 하나씩 알파벳 소문자로 출력한다. 만약, 그러한 단어가 없을 때는 "There is no such word."를 출력한다.</p>

<p>
각 테스트 케이스의 사이에는 빈 줄을 출력해서 테스트 케이스를 구분해야 한다.</p>



## 소스코드

[소스코드 보기](지프의%20법칙.cpp)