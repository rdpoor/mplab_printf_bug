/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes
#include <stdio.h>

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

// This program demonstrates a problem with XC32 v 3.0.1 / SAME70_DFP 4.6.98
// The system should print
//    "0.0, 0.3, 0.5, 0.8, 1.0, 1.3, 1.5, 1.8, 2.0, 2.3, 2.5, 2.7, 3.0, 3.3..."
// but instead it prints:
//    "0.0, 0.2, 0.5, 0.2, 1.0. 1.2, 1.5, 1.2, 2.0, 1.2, 2.5, 1.2, 3.0, 1.2..."

int main ( void )
{

    /* Initialize all modules */
    SYS_Initialize ( NULL );

    printf("\n%%f:      %%3.1f");
    for (float f=0.0; f<10; f+=0.25) {
        printf("\n%f: %3.1f", f, f);
    }

    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/
