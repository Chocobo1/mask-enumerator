# Mask enumerator
Enumerate masked numbers

[![Travis CI status](https://travis-ci.org/Chocobo1/mask-enumerator.svg?branch=master)](https://travis-ci.org/Chocobo1/mask-enumerator)

## Features
Operates in range of 32bits, eg. 0~0xFFFFFFFF

## Example
Suppose we have a value `27000` and a mask `0xfff8` (the 3 bits counting from LSB is being masked out)

Run the program as follow:
```
$ ./mask_enum 27000 0xfff8
```
The program enumerates all the numbers starting from `27000` and is covered/masked by the mask `0xfff8`.

The result is: `[27000, 27007]`. Program output as below:
```
value: 27000, mask: 0xfff8

Results:
27000
27001
27002
27003
27004
27005
27006
27007
```

## Compiler Requirements
C++

## License
This program is licensed under zlib License

## Notes
This program was created to verify the solution of [Mask calculator](https://github.com/Chocobo1/mask-calculator)
