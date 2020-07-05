import numpy as np 
def ChineseRemainderThm(x):
	lcm_index = 1
	for a in x: 
		lcm_index = np.lcm(a[1], lcm_index)
	counter = 0
	for i in range(lcm_index):
		Correct = True
		for j in range(len(x)):
			if (i % x[j][1] != x[j][0]):
				Correct = False
		if (Correct):
			print("The value you are looking for is {} and the lcm is {}".format(i, lcm_index))
			counter += 1
			break
	if (counter == 0):
		print("There are no values that satisfy")

if __name__ == '__main__':
	length = int(input("Input the number of congruences: "))
	x = []
	for i in range(length):
		y = str(input("Input the mod and then the base (e.g. 2 3): "))
		z = (int(y.split()[0]), int(y.split()[1]))
		x.append(z)
	"""x = str(input("Input the list of congruences (e.g. [(1, 2), (2, 3)]: "))
	x = x.pop(0)
	x = x.pop(-1)
	x = x.split(", ")
	for i in len(x):
		if (i % 2 == 0):
			x[i] = int(x[i].pop(0))
		elif (i % 2 == 1):
			x[i] = int(x[i].pop(-1))"""
	ChineseRemainderThm(x)
	print("Done")