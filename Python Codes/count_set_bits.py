def set_bit_counter(num):
    counter = 0
    while num:
        counter+=1
        num &= num-1
    return counter

print(set_bit_counter(1))   #001
print(set_bit_counter(2))   #010
print(set_bit_counter(3))   #011
print(set_bit_counter(4))   #100
print(set_bit_counter(5))   #101
print(set_bit_counter(6))   #110
print(set_bit_counter(7))   #111