import random
import subprocess

INT_MIN = -2147483648
INT_MAX = 2147483647

x = 500
over_int = 0
over = 0
num_executions = 100
total_lines = 0

for iteration_num, _ in enumerate(range(num_executions), start=1):
    random_numbers = [random.randint(INT_MIN, INT_MAX) for _ in range(x)]
    random_numbers_str = ' '.join(map(str, random_numbers))
    command = './push_swap "{}"'.format(random_numbers_str)
    output = subprocess.check_output(command, shell=True)
    num_lines = len(output.splitlines())
    if num_lines > 5500:
        print("Iteration {} -> {} (OVER 5500 MOVES)".format(iteration_num, num_lines))
        over_int += 1
    else:
        print("Iteration {} -> {}".format(iteration_num, num_lines))

    total_lines += num_lines
average_lines = total_lines / float(num_executions) if num_executions > 0 else 0
print("\nAverage number of lines: {}, {} operations over 5500".format(average_lines, over_int))

INT_MIN = -1000
INT_MAX = 1000

total_lines = 0

for iteration_num in range(1, num_executions + 1):
    unique_numbers = random.sample(range(INT_MIN, INT_MAX + 1), x)
    random_numbers_str = ' '.join(map(str, unique_numbers))
    command = './push_swap "{}"'.format(random_numbers_str)
    output = subprocess.check_output(command, shell=True)
    num_lines = len(output.splitlines())
    if num_lines > 5500:
        print("Iteration {} -> {} (OVER 5500 MOVES)".format(iteration_num, num_lines))
        over += 1
    else:
        print("Iteration {} -> {}".format(iteration_num, num_lines))
    total_lines += num_lines
average_lines = total_lines / float(num_executions) if num_executions > 0 else 0
print("\nAverage number of lines: {}, {} operations over 5500".format(average_lines, over))

print("With INT_MAX and INT_MIN: {} over\nWith -1000 and 1000: {} over\n".format(over_int, over))