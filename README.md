<div align="center">
    <img src="https://github.com/15Galan/42_project-readmes/blob/master/banners/cursus/projects/push_swap-light.png?raw=true#gh-light-mode-only" alt="Banner (claro)" />
    <img src="https://github.com/15Galan/42_project-readmes/blob/master/banners/cursus/projects/push_swap-dark.png?raw=true#gh-dark-mode-only" alt="Banner (oscuro)" />
    <br>
    This proyect consists of sorting a stack of numbers using two stacks and a limited set of instructions.
    <br>
    <a href='https://profile.intra.42.fr/users/alvega-g' target="_blank">
        <img alt='42 (oscuro)' src='https://img.shields.io/badge/Málaga-black?style=flat&logo=42&logoColor=white'/>
    </a>
    <img src="https://img.shields.io/badge/score- WIP%20%2F%20100-success?color=%2312bab9&style=flat" />
    <img src="https://wakatime.com/badge/user/018cd069-7ab6-4658-9d62-78d9b3970dd2/project/018cd073-0acf-4efc-a0c5-b1890ca6054a.svg" alt="Tiempo" />
</div>

---

# Mandatory part

<table>
  <tr>
    <th>Program name</th>
    <td><em>push_swap</em></td>
  </tr>
  <tr>
    <th>Turn in files</th>
    <td>Makefile, <code>*.h</code>, <code>*.c</code></td>
  </tr>
  <tr>
    <th>Makefile</th>
    <td><em>NAME</em>, <em>all</em>, <em>clean</em>, <em>fclean</em>, <em>re</em></td>
  </tr>
  <tr>
	<th>Arguments</th>
	<td><em>stack a</em>: a list of integers</td>
  </tr>
  <tr style>
    <th>External functions</th>
    <td><code>read()</code>, <code>write()</code>, <code>malloc()</code>, <code>free()</code>, <code>exit()</code> , <code>ft_printf()</code> and any equivalent YOU coded</td>
  </tr>
  <tr>
	<th>Libft authorized</th>
	<td>Yes</td>
  </tr>  
  <tr>
    <th>Description</th>
    <td>Sort stacks</td>
  </tr>
</table>

## Observations

- Global variables are forbidden
- You have to write a program named push_swap that takes as an argument the stack
a formatted as a list of integers. The first argument should be at the top of the
stack (be careful about the order).
- The program must display the smallest list of instructions possible to sort the stack
a, the smallest number being at the top.
- Instructions must be separaed by a ’\n’ and nothing else.
- The goal is to sort the stack with the minimum possible number of operations.
- If no argument is given push_swap must display nothing.
- In case of error, you must display "`Error`" followed by a ’\n’ on the standard error. This includes for example: some arguments are not integers, some arguments are bigger than an integer, and/or there are duplicates.

## Rules

- You have 2 stacks named a and b.
- At the beginning:
  - The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
  - The stack b is empty
- The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:
  - `sa` (`swap a`): swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
  - `sb` (`swap b`): swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
  - `ss`: `sa` and `sb` at the same time.
  - `pa` (`push a`): take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
  - `pb` (`push b`): take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
  - `ra` (`rotate a`): shift up all elements of stack a by 1. The first element becomes the last one.
  - `rb` (`rotate b`): shift up all elements of stack b by 1. The first element becomes the last one.
  - `rr`: `ra` and `rb` at the same time.
  - `rra` (`reverse rotate a`): shift down all elements of stack a by 1. The last element becomes the first one.
  - `rrb` (`reverse rotate b`): shift down all elements of stack b by 1. The last element becomes the first one.
  - `rrr`: `rra` and `rrb` at the same time.

# Bonus part

<table>
  <tr>
    <th>Program name</th>
    <td><em>checker</em></td>
  </tr>
  <tr>
    <th>Turn in files</th>
    <td><code>*.h</code>, <code>*.c</code></td>
  </tr>
  <tr>
    <th>Makefile</th>
    <td><em>bonus</em></td>
  </tr>
  <tr>
	<th>Arguments</th>
	<td><em>stack a</em>: a list of integers</td>
  </tr>
  <tr style>
    <th>External functions</th>
    <td><code>read()</code>, <code>write()</code>, <code>malloc()</code>, <code>free()</code>, <code>exit()</code> , <code>ft_printf()</code> and any equivalent YOU coded</td>
  </tr>
  <tr>
	<th>Libft authorized</th>
	<td>Yes</td>
  </tr>  
  <tr>
    <th>Description</th>
    <td>Execute the sorting instructions</td>
  </tr>
</table>

## Observations

- Write a program named checker that takes as an argument the stack a formatted
as a list of integers. The first argument should be at the top of the stack (be careful
about the order). If no argument is given, it stops and displays nothing.
- It will then wait and read instructions on the standard input, each instruction will
be followed by ’\n’. Once all the instructions have been read, the program has to
execute them on the stack received as an argument.
- If after executing those instructions, the stack a is actually sorted and the stack b
is empty, then the program must display "OK" followed by a ’\n’ on the standard
output.
- In every other case, it must display "KO" followed by a ’\n’ on the standard output.
- In case of error, you must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments are not integers, some arguments
are bigger than an integer,