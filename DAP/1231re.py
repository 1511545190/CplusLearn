import re  #正则表达式
print(re.match("[*]",""))

#squence list
a=list()
a.append(11)
a.append(22)
a.append(33)  #压栈
print(a)

a.insert(0,0)
print(a)

a.pop(0)    #出栈
print(a)

a.remove(22)
print(a)

#后缀式求值2022年12月31日
# expression = input().split() #用空格分开组成列表
# st = list()
# def cal(x, y, op):
#     if op == '+':
#         return x+y
#     elif op == '-':
#         return x-y
#     elif op == '/':
#         return x/y
#     elif op == "*":
#         return x*y
#
# print(expression)
# for i in expression:
#     if i in '+-*/':
#         b = st.pop()
#         a = st.pop()
#         st.append(cal(a, b, i))
#     else:
#         st.append(float(i)) #类型转换
#
# #栈底为结果
# print("%.1f" % st.pop())
#

#银行排队
N = int(input())
op = input().split()
q = []   #队列
while op[0] != '#':
    if op[0] == 'In':
        pid = op[1]
        if len(q) == N:
            print("reject")
        else:
            q.append(pid)
            print(pid, "joined . Total:%d" % len(q))
    else:
        if len(q) == 0:
            print("No one")
        else:
            pid = q.pop(0)
            print(pid, "is called Total: %d" % len(q))
    op = input().split()





