def push(data):
    N.append(data)
def pop(data):
    N.pop()
def peek(data):
    return data[-1]
def isempty(data):
    if(len(data)==0):
        return True
    else:
        return False
def isfull(data):
    if(len(data)==N):
        return True
    else:
        return False
stack = []
N = int(input("Enter the max number of items in the stack: "))
for i in range(N-3):
    x = input("Enter data : ")
    stack.append(x)
print(stack)