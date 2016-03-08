FROM debian:testing
MAINTAINER slawomir.zborowski@nokia.com

ARG http_proxy
ARG https_proxy

ENV http_proxy=$http_proxy https_proxy=$https_proxy

RUN apt-get update -yqq
RUN apt-get install -yqq build-essential git cmake

RUN git clone --recursive https://github.com/Corvusoft/restbed.git /tmp/restbed
RUN mkdir /tmp/restbed/build
WORKDIR /tmp/restbed/build
RUN cmake -DBUILD_SSL=NO -DCMAKE_INSTALL_PREFIX=/usr ..
RUN make install
RUN cp /usr/library/librestbed.a /usr/lib

RUN mkdir /app
COPY src/ /app/src

RUN mkdir /tmp/build
WORKDIR /tmp/build
RUN cmake /app/src/
RUN make

ENTRYPOINT /tmp/build/server
