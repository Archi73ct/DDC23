# How2Pwn

This challenge is about leaking information through an arbitrary read primitive, from a remote server.

# Flag(s) 
`DDC{fl4g_3x4mpl3}`

# Domain name (OR) Link to challenge on nextcloud
`how2pwn.hkn`

# Description(s) (THIS IS WHAT THE USER WILL SEE, YOU CAN USE MARKDOWN HERE))
## how2pwn game
- Proposed difficulty: Easy
- Can you find the flag, it's hidden!

# Prerequisites and Outcome

Prerequisites:
None

# Solutions (FULL WRITEUP FOR EACH FLAG.)

## Flag 1
Run the program locally in a debugger, and note the address of the flag variable.
Open a connection to the remote server and enter the `look around` menu.
Enter the address of the flag in base 10.
Flag will be printed to stdout.