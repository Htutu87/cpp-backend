#/bin/bash

# Diretorio de trabalho que deseja-se mapear para dentro do container.
WORKSPACE_DIR=$HOME/git/cpp-backend
IMAGE_NAME=arturamaral/ubuntu:0.1

sudo docker create -it --privileged \
	-m 256m\
	--name cpp-backend-dev \
	-p 10000:10000 \
	-v $WORKSPACE_DIR:/home/developer/cpp-backend \
	$IMAGE_NAME


