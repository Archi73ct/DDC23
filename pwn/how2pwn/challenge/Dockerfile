# docker build -t how2pwn .
# docker run -p 1024:1024 --rm -it how2pwn
# build bin: docker -v `pwd`:/home/ctf/build run --rm -it how2pwn /bin/gcc build/how2pwn.c -o build/how2pwn
FROM ubuntu:22.04 as build

RUN apt-get update
RUN apt-get install -y build-essential

RUN useradd -d /home/ctf/ -m -p ctf -s /bin/bash ctf
RUN echo "ctf:ctf" | chpasswd

WORKDIR /home/ctf

COPY ynetd .
RUN chmod +x ynetd

RUN chown -R ctf:ctf /home/ctf
COPY how2pwn.c .
COPY how2pwn .
USER ctf
EXPOSE 1024
CMD ./ynetd -p 1024 ./how2pwn