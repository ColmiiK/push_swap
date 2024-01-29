import random
import subprocess

MIN_RANGE_1 = -2147483648
MAX_RANGE_1 = 2147483647
MIN_RANGE_2 = -1000
MAX_RANGE_2 = 1000
amount = 500
num_executions = 1
max_moves = 5500

over_int = 0
over = 0
total_lines = 0

for iteration_num, _ in enumerate(range(num_executions), start=1):
    random_numbers = [random.randint(MIN_RANGE_1, MAX_RANGE_1) for _ in range(amount)]
    random_numbers_str = ' '.join(map(str, random_numbers))
    command = './push_swap "{}"'.format(random_numbers_str)
    output = subprocess.check_output(command, shell=True)
    num_lines = len(output.splitlines())
    if num_lines > max_moves:
        print("Iteration {} -> {} (OVER {} MOVES)".format(iteration_num, num_lines, max_moves))
        over_int += 1
    else:
        print("Iteration {} -> {}".format(iteration_num, num_lines))

    total_lines += num_lines
average_lines_int = total_lines / float(num_executions) if num_executions > 0 else 0

total_lines = 0

for iteration_num in range(1, num_executions + 1):
    unique_numbers = random.sample(range(MIN_RANGE_2, MAX_RANGE_2 + 1), amount)
    random_numbers_str = ' '.join(map(str, unique_numbers))
    command = './push_swap "{}"'.format(random_numbers_str)
    output = subprocess.check_output(command, shell=True)
    num_lines = len(output.splitlines())
    if num_lines > max_moves:
        print("Iteration {} -> {} (OVER {} MOVES)".format(iteration_num, num_lines, max_moves))
        over += 1
    else:
        print("Iteration {} -> {}".format(iteration_num, num_lines))
    total_lines += num_lines
average_lines = total_lines / float(num_executions) if num_executions > 0 else 0
print("\nAverage moves with range from {} to {}: \t{}, {} operations over {}".format(MIN_RANGE_1, MAX_RANGE_1, average_lines_int, over_int, max_moves))
print("Average moves with range from {} to {}: \t\t\t{}, {} operations over {}".format(MIN_RANGE_2, MAX_RANGE_2, average_lines, over, max_moves))
