#=====================================================================
#   23391번:    Escalator                   
#   @date:   2024-10-19              
#   @link:   https://www.acmicpc.net/problem/23391  
#   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
#   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
#=====================================================================

N = int(input())
people = [tuple(map(int, input().split())) for _ in range(N)]

escalator_empty_time = 0
escalator_direction = None
waiting_list = []

from collections import deque
waiting_list = deque()

for t_i, d_i in people:
    # Process waiting list if escalator is stopped and people are waiting
    while t_i >= escalator_empty_time and waiting_list:
        person_w = waiting_list.popleft()
        escalator_direction = person_w[1]
        boarding_time = escalator_empty_time
        escalator_empty_time += 10

        # Process any other waiting people who can board now
        # Check if any other waiting people have the same direction
        temp_waiting_list = deque()
        while waiting_list:
            next_person = waiting_list.popleft()
            if next_person[1] == escalator_direction:
                # They can board immediately
                escalator_empty_time = max(escalator_empty_time, next_person[0] + 10)
            else:
                temp_waiting_list.append(next_person)
        waiting_list = temp_waiting_list

    if t_i >= escalator_empty_time:
        if waiting_list:
            # There are still people waiting, process them first
            person_w = waiting_list.popleft()
            escalator_direction = person_w[1]
            boarding_time = t_i
            escalator_empty_time = t_i + 10
        else:
            # Escalator is stopped, person boards immediately
            escalator_direction = d_i
            boarding_time = t_i
            escalator_empty_time = t_i + 10
    else:
        # Escalator is moving
        if escalator_direction == d_i:
            # Person boards immediately
            boarding_time = t_i
            escalator_empty_time = max(escalator_empty_time, t_i + 10)
        else:
            # Person waits
            waiting_list.append((t_i, d_i))

# Process remaining waiting list after all people have been processed
while waiting_list:
    person_w = waiting_list.popleft()
    if escalator_empty_time >= person_w[0]:
        boarding_time = escalator_empty_time
    else:
        boarding_time = person_w[0]
        escalator_empty_time = boarding_time
    escalator_direction = person_w[1]
    escalator_empty_time += 10

print(escalator_empty_time)
