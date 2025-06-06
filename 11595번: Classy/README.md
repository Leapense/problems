# 11595번: Classy - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11595)


<p>In his memoir So, Anyway. . . , comedian John Cleese writes of the class difference between his father (who was “middle-middle-middle-lower-middle class”) and his mother (who was “upper-upperlower-middle class”). These fine distinctions between classes tend to confuse American readers, so you are to write a program to sort a group of people by their classes to show the true distinctions.</p>

<p>There are three main classes: upper, middle, and lower. Obviously, upper class is the highest, and lower class is the lowest. But there can be distinctions within a class, so upper-upper is a higher class than middle-upper, which is higher than lower-upper. However, all of the upper classes (upper-upper, middle-upper, and lower-upper) are higher than any of the middle classes.</p>

<p>Within a class like middle-upper, there can be further distinctions as well, leading to classes like lower-middle-upper-middle-upper. When comparing classes, once you’ve reached the lowest level of detail, you should assume that all further classes are the equivalent to the middle level of the previous level of detail. So upper class and middle-upper class are equivalent, as are middlemiddle-lower-middle and lower-middle.</p>



## 입력


<p>The first line of input contains n (1 ≤ n ≤ 1,000), the number of names to follow. Each of the following n lines contains the name of a person (a sequence of 1 or more lowercase letters ‘z’–‘z’), a colon, a space, and then the class of the person. The class of the person will include one or more modifiers and then the word class. The colon, modifiers, and the word class will be separated from each other by single spaces. All modifiers are one of upper, middle, or lower. It is guaranteed that the input is well-formed. Additionally, no two people have the same name. Input lines are no longer than 256 characters.</p>



## 출력


<p>Print the n names, each on a single line, from highest to lowest class. If two people have equivalent classes, they should be listed in alphabetical order by name.</p>



## 소스코드

[소스코드 보기](Classy.py)