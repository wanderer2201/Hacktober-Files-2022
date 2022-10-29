# Codechef Ques Who dares to be a millionaire

# Chef is going to participate in a new quiz show: "Who dares to be a millionaire?"
# According to the rules of the game, contestants must answer N questions. The quiz being famous for its difficulty, each question has 26 candidate answers, but only one of which is correct. Answers are denoted by capital Latin letters from A to Z. Chef knows all the questions that can be asked, and for each of them he knows the answer candidate he will choose (some of them can be incorrect). For each question, we'll tell you Chef's answer to it.

# The game goes on as follows. First, all the questions are shuffled randomly. Then, a contestant is asked these questions one-by-one in the new shuffled order. If the contestant answers any question incorrectly, the game is over. Total winnings of the contestant are calculated as follows. Let X denote the number of questions answered correctly by the contestant. Depending on this value, the winnings are determined: W0 dollars is the amount won for X = 0, W1 dollars is for X = 1, and so on till X = N. Note that the game was invented by a twisted mind, and so a case where Wi ≥ Wi + 1 for some 0 ≤ i ≤ N − 1 is possible.
# Chef is interested in finding the maximum possible winnings that he can a mass.


for i in range(int(input())):
    n = int(input())
    s1 = list(input())
    s2 = list(input())
    arr = list(map(int, input().split()))
    a = b = 0
    for j in range(n):
        if s1[j] == s2[j]:
            a += 1
    if a == n:print(arr[n])
    else:print(max(arr[:a+1]))
    