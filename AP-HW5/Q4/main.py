import random 
import math
import 
def IsInCircle(x,y):
	if (x**2 + y**2) <=1:
		return 1
	return 0

count=1

def find():
	num=0
	count=1
	while abs(math.pi-(4*num/count)) >.01:
		count+=1
		num=0
		a=[(random.uniform(0,1),random.uniform(0,1)) for _ in range(count)]
		for i in range(count):
			num+=IsInCircle(a[i][0],a[i][1])
		if abs(math.pi-(4*num/count)) <.01:
			print('count: {} and {} '.format(count, 4 * num / count))
			return [4 * num / count,count]


rank = input("How many times have you gotten the program?")
b=0
for i in range(int(rank)):
	f,c=find()
	b+=f
b=b/int(rank)
print(f'The Resualt Of Estimation Pi: {b}')
