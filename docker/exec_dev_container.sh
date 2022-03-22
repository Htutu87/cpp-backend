#!/bin/bash
xhost +
sudo docker start cpp-backend-dev
sudo docker exec -it cpp-backend-dev bash
