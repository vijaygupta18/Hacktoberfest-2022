# Aryan Bhardwaj
# [weebo-ary](https://www.github.com/weebo-ary)

if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    
    
    for key, value in student_marks.items():
        if query_name == key:
            sum = 0
            count = 0
            for i in value:
                sum += i
                count += 1
            average = sum/count
            print("{:.2f}".format(average))
