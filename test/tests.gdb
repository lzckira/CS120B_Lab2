# Test file for Lab2_introToAVR


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n



test "PINA: 0x15, PINB: 0x25, PINC: 0x13 => PORTD: 0x00"
setPINA 0x15
setPINB 0x25
setPINC 0x13
continue 5
expectPORTD 0x00
checkResult

test "PINA: 0x13, PINB: 0x13, PINC: 0x24 => PORTD: 0x00"
setPINA 0x13
setPINB 0x13
setPINC 0x24
continue 5
expectPORTD 0x00
checkResult

test "PINA: 0x62, PINB: 0x45, PINC: 0x72 => PORTD: 0x01"
setPINA 0x62
setPINB 0x45
setPINC 0x72
continue 5
expectPORTD 0x01
checkResult

test "PINA: 0x30, PINB: 0x70, PINC: 0x23 => PORTD: 0x01"
setPINA 0x30
setPINB 0x70
setPINC 0x23
continue 5
expectPORTD 0x01
checkResult

test "PINA: 0x9F, PINB: 0x37, PINC: 0x13 => PORTD: 0x11"
setPINA 0x9F
setPINB 0x37
setPINC 0x13
continue 5
expectPORTD 0x11
checkResult

test "PINA: 0x3D, PINB: 0x09, PINC: 0xC2 => PORTD: 0x11"
setPINA 0x3D
setPINB 0x09
setPINC 0xC2
continue 5
expectPORTD 0x11
checkResult

test "PINA: 0x20, PINB: 0x20, PINC: 0xB3 => PORTD: 0x11"
setPINA 0x20
setPINB 0x20
setPINC 0xB3
continue 5
expectPORTD 0x00
checkResult





# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
