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
