# mplab_printf_bug

This repository demonstrates a bug in the `snprintf()` function (and probably related `printf()` functions) in MPLAB XC32 v3.0.1 compiler with SAME70_DFP v 4.6.98.

The following code:
```
int main ( void )
{
    char buf[4];
    snprintf(buf, sizeof(buf), "%3.1f", 0.75);
    asm("nop"); // put breakpoint here.
    ...
}
```
should write "0.8\n" in buf[], but instead it writes "0.2\n".

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

