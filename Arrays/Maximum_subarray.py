#Maximum sum subarray using Kadane's Algorithm

a = [1,-3,2,-5,7,6,-1,-4,11,-23]
sum_of = 0
max_of = 0
for i in a:
    if i+sum_of>0:
        sum_of+=i
    else:
        sum_of=0
    max_of = max(max_of,sum_of)
print(max_of)    