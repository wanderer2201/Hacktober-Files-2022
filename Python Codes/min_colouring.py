# Input 
# 2
# 2 2
# 1 1
# 2 2
# 2 3
# 1 1
# 1 2
# Output
# 1 4
# 4 2
# 1 2 1
# 2 1 2
for z in range(int(input())):
   n,m=list(map(int,input().split()))
   x1,y1=list(map(int,input().split()))
   x2,y2=list(map(int,input().split()))
   board=[[0 for _ in range(m+1)] for _ in range(n+1)]
   board[x1][y1]=1
   board[x2][y2]=2
   chesslike=(x1+y1)&1 != (x2+y2)&1
   for i in range(1,n+1):
       for j in range(1,m+1):
           if (i==x1 and j==y1) or (i==x2 and j==y2):
               continue
           elif (i+j)&1 ==(x1+y1)&1:
               board[i][j]=1
           else:
               if chesslike:
                   board[i][j]=2
               else:
                   board[i][j]=3
   for i in range(1,n+1):
       for j in range(1,m+1):
            print(board[i][j],end=' ')
       print()