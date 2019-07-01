with open('data.txt') as f:
	content = f.readlines()
# for removing the newline character in the list
for i in range(len(content)):
	content[i] = content[i][:-1]
content = list(dict.fromkeys(content))
key = '4'
low = 0
high = len(content)-1
while(low<=high):
	mid=(low+high)/2
	print(mid,content[mid])
	if(key==content[mid]):
		print("Found")
		break
	elif(key>content[mid]):
		low=mid+1
	elif(key<content[mid]):
		high=mid-1