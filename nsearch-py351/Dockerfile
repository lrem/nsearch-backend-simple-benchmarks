FROM szborows/python351
MAINTAINER slawomir.zborowski@nokia.com

ARG http_proxy
ARG https_proxy

ENV http_proxy=$http_proxy https_proxy=$https_proxy

RUN pip3 install aiohttp
RUN pip3 install cchardet
