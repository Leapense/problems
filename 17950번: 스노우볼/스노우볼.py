import sys
h,x=map(int,sys.stdin.readline().split())
r=1000000007
ans=0
cnt=1

for _ in range(h):
    cnt*=x
    cnt%=r
    ans+=int(sys.stdin.readline())*cnt
    ans%=r

print(ans)