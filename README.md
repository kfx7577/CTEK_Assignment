# CTEK_Assignment
Coding Assignment for CTEK
Task description:

Bus problem

A bus link has N stops numbered from 1 to N in the order of the bus movement.

At i-th stop a[i] passengers exit the bus and b[i] passengers enter it. The bus is empty at the first stop and all passengers exit at the last stop. The task is to calculate the bus minimum capacity such that the number of the passengers at any time never exceeds it. Note that at each stop all exiting passengers exit before any entering passenger enters the bus.

Input format:

The input is a vector of pairs , (0 <= a[i], b[i] <= 1000) that describe passengers that exit and enter the bus at the i-th stop. The number of people who exit at a given stop should not exceed the number of people present in the bus. At the last stop, b[i] should be equal to 0 and a[i] to the current number of passengers.

Output format:

An unsigned integer with the capacity of the bus. 0 is a valid value.

Example:

Input: [(0,3), (2,5), (4,2), (4,0)] Output: 6

Explanation:

For the first example, a capacity of 6 is sufficient:

• At the first stop, the number of passengers inside the bus is 0. Then 3 passengers enter the bus, and the total number on the bus becomes 3.

• At the second stop, 2 passengers exit the bus (1 passenger remains inside). Then 5 passengers enter the bus. The total is now 6.

• At the third stop, 4 passengers exit the bus (2 passengers remain inside). Then 2 passengers enter the bus. There are now 4 passengers on the bus.

• Finally, all the remaining passengers on the bus exit at the last stop. There are no passengers on the bus now, in line with the constraints.

Since the number of passengers on the bus never exceeds 6, a capacity of 6 is sufficient.
