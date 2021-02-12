#! /bin/bash
sudo docker build . -t hello-world:1.0.5 --build-arg folderVariable="$1";
sudo docker run -it hello-world:1.0.5;