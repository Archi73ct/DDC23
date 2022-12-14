# docker build -t trusted_solutions .
# docker run -p 1024:1024 --rm -it trusted_solutions
# build bin: docker -v `pwd`:/home/ctf/build run --rm -it trusted_solutions /bin/gcc build/trusted_partners.c -o build/trusted_partners
FROM ubuntu:22.04 as build

RUN apt-get update
RUN apt-get install -y build-essential python3

RUN useradd -d /home/ctf/ -m -p ctf -s /bin/bash ctf
RUN echo "ctf:ctf" | chpasswd

WORKDIR /home/ctf

COPY ynetd .
RUN chmod +x ynetd

RUN chown -R ctf:ctf /home/ctf
COPY trusted_partners.c .
COPY trusted_partners .
COPY secret_exploit.py .
COPY flag .
USER ctf
EXPOSE 1024
CMD ./ynetd -p 1024 ./trusted_partners
