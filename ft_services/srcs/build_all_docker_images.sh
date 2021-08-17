#!/bin/sh

srcs/nginx/docker_build_nginx.sh
srcs/wordpress/docker_build_wordpress.sh
srcs/phpmyadmin/docker_build_phpmyadmin.sh
srcs/mysql/build_mysql.sh
srcs/influxdb/build_influxdb.sh
srcs/grafana/build_grafana.sh
srcs/ftps/docker_build_ftps.sh