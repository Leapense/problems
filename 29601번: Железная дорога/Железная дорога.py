def determine_seat_type(input_data):
    wagon_type = input_data[0]
    seat_number = int(input_data[1:])

    if wagon_type == 'R':  # Плацкартный вагон
        if seat_number < 1 or seat_number > 54:
            return -1
        
        if seat_number <= 36:  # Купейные места
            coupe_number = (seat_number - 1) // 4 + 1
            is_coupe = 1  # Это купейное место
            is_upper = 1 if seat_number % 2 == 0 else -1  # Верхнее или нижнее
        else:  # Боковые места
            coupe_number = (54 - seat_number) // 2 + 1
            is_coupe = 0  # Это боковое место
            is_upper = 1 if seat_number % 2 == 0 else -1  # Верхнее или нижнее

        return f"{coupe_number} {is_coupe} {is_upper}"

    elif wagon_type == 'C':  # Купейный вагон
        if seat_number < 1 or seat_number > 36:
            return -1
        
        coupe_number = (seat_number - 1) // 4 + 1
        is_coupe = 1  # В купейном вагоне все места купейные
        is_upper = 1 if seat_number % 2 == 0 else -1  # Верхнее или нижнее

        return f"{coupe_number} {is_coupe} {is_upper}"

    else:
        return -1
    

input_data = input()
print(determine_seat_type(input_data))