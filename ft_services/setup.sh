#!/bin/sh

minikube --driver=virtualbox --memory='3000' --disk-size 40000MB start

echo "SERVICESS PREPARE, wait"

minikube addons enable metallb
minikube addons enable dashboard

eval $(minikube docker-env)

./srcs/build_all_docker_images.sh
./srcs/apply_all_yaml.sh

sleep 10
kubectl get pods

echo "SERVICESS READY - GOOD LUCK"