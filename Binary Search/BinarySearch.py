import math
def binarySearch(arr , low , high , target , firstoccur):
    result = -1
    while low<=high:
        mid = math.floor(low+(high-low)/2)
        if arr[mid]==target:
            result = mid
            if firstoccur:
                high = mid-1
            else:
                low = mid+1
        elif target<=arr[mid]:
            high = mid-1;
        else:
            low = mid+1
    return result
    
arr = [2,3,3,3,3,3,5,5,5,5,6,7,7,7,7,8,9,9,9]
target = 2
firstoccur = True
first = binarySearch(arr,0,len(arr)-1,target ,firstoccur)
if first!=-1:
    last = binarySearch(arr,0,len(arr)-1,target ,False)
    print(last-first+1)
else:
    print('Nahi hai')