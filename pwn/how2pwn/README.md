# How2Pwn

This challenge is about leaking information through an arbitrary read primitive, from a remote server.

# Flag(s) 
`DDC{fl4g_3x4mpl3}`

# Domain name (OR) Link to challenge on nextcloud
`coolchallenge.hkn`

# Description(s) (THIS IS WHAT THE USER WILL SEE, YOU CAN USE MARKDOWN HERE))
1. (CHALLENGE NAME,REMEMBER TO ADD LINK OR DOMAIN)
- Proposed difficulty: Easy-medium
- The owner of coolchallenge.hkn has stolen our webshop template. The legal system won't help us. Consultants said that bad PHP implementation made it possible to accomplish RCE, whatever that is... Get the owners user creds for the server so we can shut him down. He might have a local backup file with the creds laying around.

2. (CHALLENGE 2, ONLY IF MULTIPLE FLAGS, REMEMBER TO ADD LINK OR DOMAIN)
- Proposed difficulty: medium-hard
- The bootshop owners credentials were not enough. We think he might be using his services as root the user.
Totally pwning his server will make him more salty anyways, so make it happen.

# Prerequisites and Outcome

Prerequisites
- Know the terms LFI and RFI.
...
- Have an idea of where to find resources such as proof of concepts and exploits
github, exploit-db etc.

Outcome
- Learn how to exploit a RFI.
- Learn how to forward a localhost port so they now also take in connections from 0.0.0.0.
- Learn a little enumeration.

# Solutions (FULL WRITEUP FOR EACH FLAG.)

## Flag 1
- Open `bootshop.com` browse around the different pages and see if you can spot anything in the browser.
- If you havn't noticed how the URL changes each time you change to another page, then now would be a good time to do that :P.
.......
- The flag is placed inside `/var/backups/`

## Flag 2 (ONLY IF MULTIPLE FLAGS)
- For the root part you could find and use linpeas from github, to enumerate the container.
....
- Read the textfile to get the flag.
