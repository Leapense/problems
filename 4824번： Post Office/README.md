# 4824번: Post Office - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4824)


<p>Other than postcards, the post office department of some country recognizes three classes of mailable items: letters, packets, and parcels. The three dimensions of a mailable item are called length, height and thickness, with length being the largest and thickness the smallest of the three dimensions.</p>

<p>A letter's length must be at least 125mm but not more than 290mm, its height at least 90mm but not more than 155mm, and its thickness at least 0.25mm but not more than 7mm. (The unit millimeter is abbreviated by mm.)</p>

<p>All three of a packet's dimensions must be greater than or equal to the corresponding minimum dimension for a letter, and at least one of its dimensions must exceed the corresponding maximum for a letter. Furthermore, a packet's length must be no more than 380mm, its height no more than 300mm, and its thickness no more than 50mm.</p>

<p>All three of a parcel's dimensions must be greater than or equal to the corresponding minimum dimension for a letter, and at least one of its dimensions must exceed the corresponding maximum for a packet. Furthermore, the parcel's combined length and girth may not exceed 2100mm. (The girth is the full perimeter measured around the parcel, perpendicular to the length.)</p>



## 입력


<p>The input will contain data for a number of problem instances. For each problem instance, the input will consist of the three dimensions (measured in mm) of an item, in any order. The length and width will be positive integers. The thickness will be either a positive integer or a positive floating point number. The input will be terminated by a line containing three zeros.</p>



## 출력


<p>For each problem instance, your program will classify the item as letter, packet, parcel or not mailable. This verdict will be displayed at the beginning of a new line, in lower case letters.</p>



## 소스코드

[소스코드 보기](Post%20Office.cpp)