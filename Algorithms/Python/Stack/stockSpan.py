class Stack():
    def __init__(self):
        self.items = []
    def push (self,item):
        self.items.append(item)
    def pop(self):
        return self.items.pop()
    def is_empty(self):
        return len(self.items) == 0
    def peek(self):
        if not self.is_empty():
            return self.items[-1]
    def get_stack(self):
        return self.items

#Stock spam [100, 80, 60,70, 60, 75, 85]
############[1,1,1,2,1,4,6]
# find cons0cutive smaller or equal
##############output = [1,2,1,1,3,4,7] input=[1, 3, 0, 0, 1, 2, 4]
def StockSpam(arr):
    n = len(arr)
    stack = Stack()
    ans =[]
    for i in range(len(arr)):
        if stack.is_empty():
            ans.append(i-(-1))
        elif not stack.is_empty() and arr[stack.peek()]>arr[i]:
            ans.append(i-stack.peek())
        elif not stack.is_empty() and arr[stack.peek()]<=arr[i]:
            while  not stack.is_empty() and arr[stack.peek()]<=arr[i]:
                stack.pop()
            if stack.is_empty():
                ans.append(i-(-1))
            else:
                ans.append(i-stack.peek())
        stack.push(i)
    return ans
