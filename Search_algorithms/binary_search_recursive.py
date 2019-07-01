def bsrch(x,key):
	low = 0
	high = len(x)-1
	if(low>high):
		return
	else:
		mid = (low + high)/2
		if(key==x[mid]):
			print("Found")
		elif(key>x[mid]):
			low = mid+1
			bsrch(x[low:high+1],key)
		elif(key<x[mid]):
			high = mid-1
			bsrch(x[low:high+1],key)
a = [1,2,3,4,5,6,7,8,66,75,88]
key = 5
bsrch(a,key)