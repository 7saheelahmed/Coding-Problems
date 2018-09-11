x = [1,3,5]

def num_ways_X(n):
    if n==0:
        return 1
    total = 0
    for i in x:
        if n-i>=0:
            total+=num_ways_X(n-i)
    
    return total

def num_ways_dp(n):
    if n==0:
        return 1
    temp = [0]*(n+1)
    temp[0] = 1
    i = 1
    while i<n+1:
        total=0
        for j in x:
            if i-j>=0:
                total+=temp[i-j]
        temp[i]=total        
        i+=1        
    return temp[n]
for i in range(1,40):
    print(num_ways_dp(i))
   
    