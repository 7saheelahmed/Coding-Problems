#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the arrayManipulation function below.
def arrayManipulation(n, queries):
    result = [0]*(n+1)
    ans = max_i= 0
    for query in queries:
        a , b , k = map(int , query)
        result[a-1]+=k;
        if(b<=len(result)):
            result[b]-=k;
    
    for i in result:
        ans+=i
        if(max_i<ans):
            max_i = ans
    return str(max_i)
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nm = input().split()

    n = int(nm[0])

    m = int(nm[1])

    queries = []

    for _ in range(m):
        queries.append(list(map(int, input().rstrip().split())))

    result = arrayManipulation(n, queries)

    fptr.write(result)
    #fptr.write(str(result) + '\n')

    fptr.close()
