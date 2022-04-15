# mplab_printf_bug

This repository demonstrates a bug in `printf()` and related functions in MPLAB XC32 v3.0.1 compiler with SAME70_DFP v 4.6.98.

The following code:

```
int main ( void ) {
    SYS_Initialize ( NULL );
    printf("\n%%f:      %%3.1f");
    for (float f=0.0; f<10; f+=0.5) {
        printf("\n%f: %3.0f", f, f);
    }
    while ( true ) {
        SYS_Tasks ( );
    }
    return ( EXIT_FAILURE );
}
```
produces the following output (with comments annotated):
```
%f:      %3.1f
0.000000: 0.0
0.250000: 0.2  // should be 0.3
0.500000: 0.5
0.750000: 0.2  // should be 0.7
1.000000: 1.0
1.250000: 1.2  // should be 1.3
1.500000: 1.5
1.750000: 1.2  // should be 1.7
2.000000: 2.0
2.250000: 1.2  // should be 2.3
2.500000: 2.5
2.750000: 1.2  // should be 2.7
3.000000: 3.0
3.250000: 1.2  // etc...
3.500000: 3.5
3.750000: 1.2
4.000000: 4.0
4.250000: 1.2
4.500000: 4.5
4.750000: 1.2
```

## To replicate

* Open the project in MPLAB.X IDE v6.00
* Compile and load the project into a SAME70 XULT demonstration board
* Place a breakpoint at the `asm("nop")` statement in `main()`
* Run the program until it hits the breakpoint
* Examine the contents of buf[], observe that it contains "0.2\n"

## Workaround

None known.

## Comment

This is a serious bug because it will produce erroneous output with no indication that it's erroneous.

## Updates

The same problem has been observed in:
* XC32 v3.0.1 with SAME70_DFP v4.4.78, v4.5.86, v4.6.98
* XC32 v3.0.1 with SAME70_DFP 4.7.120 won't compile due to a previously reported bug

