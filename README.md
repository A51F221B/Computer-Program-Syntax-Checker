# DSA PROJECT

## Syntax Checker

### DEVELOPERS:

### ASIF MASOOD (190794) AND OZAIR MALIK

### ( 19079 8)


Data Structures and Algorithms Used:

- String Array/Pointer:
    Firstly, read the file in a string and then copied the whole content in string array for the
    purpose of extraction of content and comparison. Using pointer the array is allocated at
    run time according to the size of file.
- Linked-list Stack (string):
    We already have an algorithm for checking parentheses using stack basic operations
    (push, pop, top) so and Linked-list stack is used due to the fact that it adds nodes on run
    time dynamically according to the input and as we do not know that the exact length of
    data in file so that’s why we needed a data structure to allocate memory on run time.

Methods:

- Parentheses checker:
    This function takes input from file content as string and performs comparison between
    the opening and closing braces.
    Firstly, we extracted the braces from file.
    Then, they were pushed into a string to form a string expression.
    Verification functions comes after this and it uses the above string expression to verify
    braces.
    This operation is done using stack.
    The rest of the comparison operation is performed using the pre-defined parentheses
    checking algorithm of stack which is one of its application.
- Keywords Checker:
    This function takes input from file content as string and performs comparison between
    the opening and closing keywords.
    Firstly, we extracted the keywords from file and copied them into a string array.
    Then, the comparison was made using that array.
    Verification functions comes after this and it uses the keywords string array to verify
    balancing.
    This operation is done using stack.
    The rest of the comparison/verification operation is performed using the pre-defined
    parentheses checking algorithm of stack which is one of its application. The algorithm
    was modified for keywords instead of parentheses.


**Class Diagram:**


Flow Chart:

**Project is hosted on Github at this link:**

```
https://github.com/A51F221B/Computer-Program-Syntax-Checker
```

