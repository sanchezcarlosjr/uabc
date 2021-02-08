#! /bin/bash
sudo docker build . -t hello-world:1.0.5 --build-arg folderVariable="$1";
sudo docker run hello-world:1.0.5;