import math
import random 
def FirstNormal(mu, sigma):
	u1 = random.random()
	u2 = random.random()
	r = math.sqrt(-2 * math.log(u1))
	theta = 2 * math.pi * u2
	randn = r * math.cos(theta)
	return mu + (sigma * randn)

def SecondNormal(mu, sigma):
	return random.gauss(mu, sigma)

if __name__ == '__main__':
	mu = float(input("Input the mean: "))
	sigma = float(input("Input the standard deviation: "))
	numbers = int(input("Input the number of trails: "))
	first_mean = 0
	second_mean = 0
	for i in range(numbers):
		x = FirstNormal(mu, sigma)
		y = SecondNormal(mu, sigma)
		first_mean = ((first_mean * i) + x)/(i + 1)
		second_mean = ((second_mean * i) + y)/(i + 1)
		diff = math.fabs(second_mean - first_mean)
		print("The differences in the total mean at episode {} is {}".format(i, diff))
	print("I have finished the trials and the mean of the first distribution is {} and of the second distribution is {}"
		.format(first_mean, second_mean))
	first_zscore = (first_mean - mu)/sigma
	second_zscore = (second_mean - mu)/sigma
	print("After analysis the average z-score for the first distribution it is {} and the for the second distribution it is {} and the difference is {}".format(first_zscore, second_zscore, math.fabs(first_zscore - second_zscore)))

