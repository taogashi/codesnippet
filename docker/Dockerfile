# chrome.Dockerfile
FROM ubuntu:20.04
RUN apt update \
    && apt install -y ca-certificates
COPY ./sources.list /etc/apt/
RUN apt update \
    && apt install -y sudo ccrypt
RUN useradd -rm -d /home/me -s /bin/bash -g root -G sudo -p $(perl -e 'print crypt($ARGV[0], "password")' "'") me
USER me
WORKDIR /home/me
