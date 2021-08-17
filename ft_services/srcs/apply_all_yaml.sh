#!/bin/sh

cd srcs
kubectl apply -f configmap.yaml
cd nginx/configs
kubectl apply -f nginx_service.yaml
kubectl apply -f nginx_deployment.yaml
cd ..
cd ..
cd wordpress/configs
kubectl apply -f wordpress_service.yaml
kubectl apply -f wordpress_deployment.yaml
cd ..
cd ..
cd phpmyadmin/configs
kubectl apply -f phpmyadmin_service.yaml
kubectl apply -f phpmyadmin_deployment.yaml
cd ..
cd ..
cd mysql/configs
kubectl apply -f mysql_service.yaml
kubectl apply -f mysql_persistentvolumeclaim.yaml
kubectl apply -f mysql_deployment.yaml
cd ..
cd ..
cd influxdb/configs
kubectl apply -f influxdb_persistentvolumeclaim.yaml
kubectl apply -f influxdb_deployment.yaml
kubectl apply -f influxdb_service.yaml
cd ..
cd ..
cd grafana/configs
kubectl apply -f grafana_service.yaml
kubectl apply -f grafana_deployment.yaml
cd ..
cd ..
cd ftps/configs
kubectl apply -f ftps_service.yaml
kubectl apply -f ftps_deployment.yaml