# push_swap

## Description
push_swap is a 42 School project that focuses on sorting data efficiently. The goal is to sort a stack of integers using a limited set of operations with the smallest possible number of actions. Two stacks (A and B) are available for manipulating the data, and a specific set of operations must be used to achieve the sorting.

## Installation

Clone the repository and compile the program:

```bash
git clone https://github.com/matteo-genovese/push_swap.git
cd push_swap
make
```

Clean object files:
```bash
make clean
```

Clean everything (objects and binary):
```bash
make fclean
```

Recompile:
```bash
make re
```

## Usage

### Basic usage
```bash
./push_swap <numbers>
```

Example:
```bash
./push_swap 4 67 3 87 23
```

You can also use quotes for numbers:
```bash
./push_swap "4 67 3 87 23"
```

### Test with checker
Check if your solution is valid:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
```

### Custom tests
The project includes some testing utilities:
```bash
# Try with a specific set of numbers
make try

# Count the number of operations
make count

# Check if sorting works correctly
make check
```

## Algorithm

The push_swap project implements several sorting algorithms depending on the number of elements:

- **2 numbers**: Simple swap if needed
- **3 numbers**: Hardcoded optimal solution for all possible combinations
- **4-5 numbers**: Find the smallest number, push it to stack B, sort the rest, and push back
- **More than 5 numbers**: Uses a custom algorithm ("mturk algorithm")

The main algorithm for larger sets:
1. Push first 2 elements to stack B
2. For each remaining element in stack A:
   - Calculate the cheapest element to move (based on operation count)
   - Move that element to the top of stack A
   - Find the correct position in stack B and move it there
   - Push the element to stack B
3. Sort the remaining 3 elements in stack A
4. Push all elements back to stack A in the correct order
5. Rotate stack A to complete the sort

## Operations

The following operations are available:

- `sa`: Swap the first two elements at the top of stack A
- `sb`: Swap the first two elements at the top of stack B
- `ss`: `sa` and `sb` at the same time
- `pa`: Push the first element from stack B to stack A
- `pb`: Push the first element from stack A to stack B
- `ra`: Rotate stack A (first element becomes last)
- `rb`: Rotate stack B (first element becomes last)
- `rr`: `ra` and `rb` at the same time
- `rra`: Reverse rotate stack A (last element becomes first)
- `rrb`: Reverse rotate stack B (last element becomes first)
- `rrr`: `rra` and `rrb` at the same time

## Files Structure

- **Main Components**
  - `main.c`: Entry point of the program
  - `Makefile`: Compilation rules

- **Algorithm Implementation**
  - `algo/sort.c`: Contains sorting functions for small sets
  - `algo/mturk.c`, `algo/mturk_a.c`, `algo/mturk_b.c`: Implementation of the main algorithm

- **Operations**
  - `algo/move_s_p.c`: Swap and push operations
  - `algo/move_r.c`: Rotate operations
  - `algo/move_rr.c`: Reverse rotate operations

- **Utility Functions**
  - `utils/random_stack.c`: Stack initialization and management
  - `utils/random.c`: Helper functions for stack manipulation

- **Input Validation**
  - `checks/check_args.c`: Argument validation
  - `checks/final_check.c`: Final validation before sorting

## Bonus

The repository includes checker programs (`checker_linux` and `checker_OS`) that can verify if a sequence of operations correctly sorts the input data.

## Author
[mgenoves](https://profile-v3.intra.42.fr/users/mgenoves)

![image](https://github.com/user-attachments/assets/695ac584-0f00-44a3-be44-f296a01fe557)
