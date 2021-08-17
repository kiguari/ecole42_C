# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eshakita <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/05 14:03:38 by eshakita          #+#    #+#              #
#    Updated: 2021/05/31 10:24:34 by eshakita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.12

RUN apk update 
RUN apk upgrade 

RUN apk add bash supervisor openrc libc6-compat wget

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.2_linux_amd64.tar.gz
RUN tar xf telegraf-1.18.2_linux_amd64.tar.gz --strip-components=2 -C /

RUN wget https://dl.grafana.com/enterprise/release/grafana-enterprise-7.5.4.linux-amd64.tar.gz
RUN tar -zxvf grafana-enterprise-7.5.4.linux-amd64.tar.gz --strip-components=1 -C /

COPY ./configs/telegraf.conf /etc/telegraf/
COPY ./configs/supervisord.conf /etc/supervisor.conf
COPY ./configs/supervisor_start.sh /
COPY ./configs/grafana.db /data/grafana.db

EXPOSE 3000

CMD bash supervisor_start.sh