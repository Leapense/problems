# 11236번: Carrot - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11236)


<p>เป็นที่ทราบกันโดยทั่วไปว่ากระต่ายชอบกินแครอทที่สุด ซึ่งไม่จริงเพราะกระต่ายชอบกินผักใบเขียวและหญ้ามากกว่า ดังนั้นส าหรับฝูงกระต่ายแล้วการกินแครอทจึงเป็นไปอย่างน่าเบื่อ ฝูงกระต่ายจึงคิดเกมหนึ่งขึ้นมาดังนี้</p>

<p>ในตอนเริ่มต้นมีแครอทอยู่ N ชิ้น กระต่ายในฝูงจะเข้าแถวตามล าดับความน่ารัก โดยกระต่ายแต่ละตัวจะต้องแบ่งแครอทออกเป็นกองกองละเท่าๆกัน และแครอทแต่ละกองจะต้องมีมากกว่าหนึ่งชิ้น ถ้าแบ่งได้ตั้งแต่สองกองขึ้นไปกระต่ายตัวนั้นจะกินแครอทเพียง 1 ชิ้น แต่ถ้าแบ่งไม่ส าเร็จจะต้องกินแครอทถึง 2 ชิ้น (ยกเว้นกรณีที่เหลือแครอทเพียงชิ้นเดียว) ในฝูงมีกระต่ายเยอะกว่าจ านวนแครอทมาก และกระต่ายทุกตัวแบ่งแครอทเก่งมาก (ถ้ามีวิธีแบ่งได้ กระต่ายทุกตัวจะสามารถแบ่งได้อย่างแน่นอน) ถามว่ามีกระต่ายกี่ตัวที่ต้องกินแครอท</p>



## 입력


<p>บรรทัดแรกเป็นจ านวนกรณีทดสอบ T ชุด (1 ≤ T ≤ 1 000 000)</p>

<p>ถัดมา T บรรทัดเป็นจ านวนแครอท N ชิ้น (1 ≤ N ≤ 10 000 000)</p>



## 출력


<p>ส าหรับแต่ละกรณีทดสอบ ให้แสดงค าตอบ 1 บรรทัด เป็นจ านวนเต็ม 1 จ านวน แสดงจ านวนกระต่ายที่ต้องกินแครอท</p>



## 소스코드

[소스코드 보기](Carrot.cpp)