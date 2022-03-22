# docker build -t mettainnovations/efvm:1.0 .
# docker pull nvcr.io/nvidia/cuda:11.2.0-cudnn8-devel-ubuntu18.04

FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive

# Set apt-get to automatically retry if a package download fails
RUN echo 'Acquire::Retries "8";' > /etc/apt/apt.conf.d/99AcquireRetries

# apt update
RUN apt update -y
RUN apt upgrade -y 

RUN apt install -y \
    wget -y \
    git -y \
    vim -y \
	build-essential -y

RUN apt install libboost-all-dev -y

####################################################################################
# Data/hora e Timezone
# https://rtfm.co.ua/en/docker-configure-tzdata-and-timezone-during-build/
####################################################################################

ENV TZ=America/Sao_Paulo
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt update && \
    apt install -y ntp \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory to /app
WORKDIR /home

#Home workdir
RUN mkdir -p /home/developer
ENV HOME /home/developer
WORKDIR /home/developer
