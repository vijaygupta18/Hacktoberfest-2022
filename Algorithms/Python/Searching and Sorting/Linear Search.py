"""
FOR - UnorderedLinearSearch

Case			    Best Case		Worst Case		Average Case

item is present		    1			    n			    n/2

item is not present	    n			    n			    n
"""

def UnorderedLinearSearch(alist, item):
    pos = 0
    found = False

    while pos < len(alist) and not found:
        if alist[pos] == item:
            found = True
        else:
            pos = pos+1

    return found

testlist = [1, 2, 32, 8, 17, 19, 42, 13, 0]
print(UnorderedLinearSearch(testlist, 3))
print(UnorderedLinearSearch(testlist, 13))



print("--------------")

"""
FOR - OrderedLinearSearch

Case			    Best Case		Worst Case		Average Case

item is present		    1			    n			    n/2

item is not present	    n			    n			    n/2
"""

def OrderedLinearSearch(alist, item):
   pos = 0
   found = False
   stop = False
   while pos < len(alist) and not found and not stop:
       if alist[pos] == item:
           found = True
       else:
           if alist[pos] > item:
                stop = True
           else:
                pos = pos+1

   return found

testlist = [0, 1, 2, 8, 13, 17, 19, 32, 42,]
print(OrderedLinearSearch(testlist, 3))
print(OrderedLinearSearch(testlist, 13))