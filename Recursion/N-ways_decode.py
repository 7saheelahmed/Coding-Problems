''' If 'a' = 1, 'b'=2,'c'=3 then given a string of numbers how many ways to decode it. '''

def helper_dp(data,k,memo):
    if k==0:            #if string is empty then 1
        return 1
    
    s = len(data)-k
    if data[s]=='0':    #if first letter of string is 0 then 0
        return 0
    if memo[k]!=None:       #if the decoded message exist in list at kth position return it otherwise continue.
        return memo[k]
    
    result = helper_dp(data,k-1,memo)  # recursive call 
    if k>=2 and int(data[s:s+2])<=26:    # if first two digits are greater than 10 and less than 26 then add it. 
        result+=helper_dp(data,k-2,memo)
    
    memo[k]=result  # store the result in the lookup table.
    return result



def num_ways_dp(arr):
    memo = [None]*(len(arr)+1)          #creating a lookup table
    return helper_dp(arr,len(arr),memo)
    
    
print(num_ways_dp('111111111111111'))    