# 16860번: Are You Listening？ - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/16860)


<p>You’re a top government spy currently at a secret location behind enemy lines (ooooh....exciting!). You have a communication device that allows you to stay in contact with various other operatives that you work with. The broadcast range of the device is adjustable and ideally you would set it at its maximum value to be able to reach the largest number of operatives. Unfortunately, the enemy is not stupid and has a set of listening devices that can detect your signal. These listening devices each have a fixed range (which can vary from device to device), and in order to pinpoint your location the enemy must detect you on at least three of their listening devices. Therefore, you are safe as long as you set your broadcast range so that at most two listening devices can detect you. A listening device can detect you if your broadcast range and its listening range touch at more than one point.</p>

<p>An example situation is shown below. Your device and its broadcast area are shown in the grey circle, and four listening devices and their detecting areas are shown in the white circles. On the far left you have set your broadcast range so that none of the listening devices can detect you, but clearly you could increase your range. In the middle picture you’ve increased it so that two of the listening devices can detect you, but that’s fine. In the right picture, you’ve increased your range too much since now three of the listening devices can detect you.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/78a79b26-6228-4ab5-94cc-13e74ca9c533/-/preview/" style="width: 493px; height: 149px;"></p>

<p>Given your location and the locations and detection ranges of a set of listening devices, determine the maximum broadcast range for your communication device. Note that this range may be 0 if the broadcast device it already within the range of three listening devices.</p>



## 입력


<p>Input starts with a line containing three integers cx cy n where (cx, cy) is your location and 3 ≤ n ≤ 100 is the number of listening devices. The next n lines each contain three integers x y r, where (x, y) is the location of a listening device and 0 &lt; r ≤ 1 000 is the radius of its listening area. All coordinates are between −1 000 and 1 000. All n + 1 locations are distinct.</p>



## 출력


<p>Display the radius of the maximum broadcast area, rounding down to the nearest integer.</p>



## 소스코드

[소스코드 보기](Are%20You%20Listening？.cpp)