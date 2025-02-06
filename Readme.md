# ft_printf


- [1 About](#1-about)
- [2 Documentation](#2-documentation)
  - [2.1 Conversions](#21-conversions)
  - [2.2 Flags](#22-flags)
    - [Flag interactions](#flag-interactions)
  - [2.3 External functions](#23-external-functions)
  - [2.4 Internal structure](#24-internal-structure)

# 1 About

This is my **printf** function!

The goal of this project is to create a replicate of the `printf()`
function, from `libc`. It is a good project to learn more about variadic
functions, and advanced uses of `printf` (conversions, flags).

# 2 Documentation

`int ft_printf(char const *, ...)`

**ft_printf** prints an output in console, according to a format.

## 2.1 Conversions

- **%c**, **%s**: Single character, string
- **%p**: Pointer address, in hexadecimal
- **%d**, **%i**, **%u**: Integer and unsigned integer
- **%x**, **%X**: Hexadecimal number (lower and upper)
- **%%**: Percentage symbol %

## 2.2 Flags

- **‘min width’**: \[all\] It’s a decimal. Adds padding to the result,
  to the right. Never truncates the result
  - **‘-’**: \[all\] Adds the padding to the right instead
  - **‘0’**: \[%d %i %u %x %X\] Adds ‘0’ instead of spaces
- **‘.’**: \[%d %i %u %x %X\] Precision symbol. Adds ‘0’ until it reach
  the precision number. \[s\] Limits the maximum number of characters to
  print (removing end characters)
- **‘+’**: \[%i %d\] Always puts the sign
- **’ ’**: \[%i %d\] Add space if it’s positive
- **‘\#’**: \[%x %X\] Add 0x or 0X at the start of the number

### Flag interactions

- **‘0’ + ’ ’**: Adds space near the number, ignoring a 0 if there would
  be (I should change it so the space is at the start)
- **‘0’ + ‘-’**: Ignore 0 flag
- **‘0’ + ‘.’**: Ignore 0 flag
- **‘+’ + ’ ’**: Ignores ’ ’

## 2.3 External functions

- `malloc`, `free`: Memory management
- `write`: Print in console
- `va_start`, `va_arg`, `va_copy`, `va_end`: Variadic arguments
  management

## 2.4 Internal structure
