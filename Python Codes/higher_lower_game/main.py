
from art import logo,vs
from game_data import data
import random

print(logo)
random_b = random.choice(data)
is_winning = True
score = 0
while(is_winning):

    random_a = random_b
    print("Compare A : ",random_a["name"],",a",random_a["description"]," ,from",random_a["country"])

    print(vs)

    random_b = random.choice(data)
    print("Against B : ",random_b["name"],",a",random_b["description"]," ,from",random_b["country"])
    choice = input("Who has more follower type A or B ?")


    if random_a["follower_count"] > random_b["follower_count"]:
        winner ="A"
    else:
        winner ="B"

    if choice == winner:
        score +=1
        print("You win \n ")
    else:
        is_winning = False
        print("You Lost")
print("your score is ",score)