*This project has been created as part of the 42 curriculum by cbozkurt.*

# Libft

## Description

**ft_printf** is a foundational project in the 42 curriculum.  
The goal of this project is to create very own implementation of the C function ft_printf.

Through this project, students learn:
- What is going on under hood of C function printf. 
- Defensive programming in C
- Proper use of headers, Makefiles, and math in programming.
- Learning the compiler differences and behaviours.
### Worth Mentioning:
The original libc function `printf` and my own implementation `ft_printf` doesn't flush the stdout the same way.
Basically; my ft_printf is using the low-level function `write` instead of making us doing the buffer management.
in short, the outputs are being flushed at different times.
In skae of keeping stability intact, using **ONLY** printf or using ft_printf **ONLY** is highly encouraged. 

---

## Instructions

### Compilation

In order to compile the ft_printf, just run:

```bash
make
```

## Resources 

**AI** is used to understand C concepts and to create a summary of how compilers work across all operating systems.

[StackOverflow](https://www.stackoverflow.org/) for concepts and function usages.<br>
[Learn-C](https://www.learn-c.org/) is to write a code and run when I'm too lazy to do it in my own computer.<br>


