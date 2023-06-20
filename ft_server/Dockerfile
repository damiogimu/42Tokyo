FROM	debian:buster

ENV	AUTOINDEX on

RUN	apt-get update && \
	apt-get install -y openssl \
	wget \
	nginx \
	mariadb-server \
	php-cgi php-common php-fpm php-pear php-mbstring php-zip php-net-socket php-gd \
	php-xml-util php-gettext php-mysql php-bcmath;


COPY	srcs/server.conf /etc/nginx/sites-available/
COPY	srcs/server_autoindex_off.conf /etc/nginx/sites-available/
COPY	srcs/wp-config.php ./
COPY	srcs/setup.sh ./ 

CMD	bash setup.sh
