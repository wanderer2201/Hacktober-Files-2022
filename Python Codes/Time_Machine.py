Chef and Time Machine


'''Chef spent N days working really hard! He planned loads of tasks: as many as Ai tasks to do on the ith day! Chef's work was brutal, so he only managed to finish Bi tasks on the ith day.
The good news is that Chef has a Time Machine!

The Time Machine has K white buttons and M black buttons. Each button has a positive integer printed on it. Now Chef goes through all N days consequently and presses buttons. Each day Chef can only press one button (either white or black). After using a button once, it becomes inactive.

Pressing a white button with integer x printed on it reduces the number of planned tasks on the day it was pressed by exactly x. Note that this white button can only be pressed if number of planned tasks on the day are greater than or equal to x.

Pressing a black button with integer x printed on it increases the number of completed tasks on the day it was pressed by exactly x. Note that this black button can only be pressed if after pressing it, number of completed tasks don't exceed the number of tasks.

Chef is interested in finding the minimum possible amount of total uncompleted tasks he will still be left with after N days using the Machine in the best way?

Be careful! Time is sensitive! Chef cannot make a day when he completed more tasks then planned, as this may result in a more-work-than-planned paradox, killing all lazy people on the planet!'''


'''
Input 
1
4 2 2 
5 7 6 1
3 3 1 1
6 3
1 4
Output
3
'''


for z in range(int(input())):
    n,k,m=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    a=[a[i]-b[i] for i in range(n)]
    w=list(map(int,input().split()))
    bl=list(map(int,input().split()))
    c=w+bl
    u=0
    c.sort(reverse=True)
    a.sort(reverse=True)
    i=0
    for j in c:
        if j<=a[i]:
            u+=j
            i+=1
    print(sum(a)-u)
