service mysql start

mysql -u root -e "CREATE DATABASE wordpress;"
mysql -u root -e "CREATE USER 'wpuser'@'localhost' IDENTIFIED BY 'password';"
mysql -u root -e "GRANT ALL PRIVILEGES ON wordpress.* TO 'wpuser'@'localhost';"
mysql -u root -e "FLUSH PRIVILEGES;"

wget --no-check-certificate https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz
wget --no-check-certificate https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-all-languages.tar.gz
tar -xvzf phpMyAdmin-5.1.0-all-languages.tar.gz
rm latest.tar.gz phpMyAdmin-5.1.0-all-languages.tar.gz

mv wordpress /var/www/html/
mv phpMyAdmin-5.1.0-all-languages /var/www/html/phpmyadmin
chown -R www-data:www-data /var/www/html/*

chmod 644 wp-config.php
chown -R www-data:www-data wp-config.php
mv wp-config.php /var/www/html/wordpress/

if [ $AUTOINDEX = on ]; then
	ln -s /etc/nginx/sites-available/server.conf /etc/nginx/sites-enabled/
else
	ln -s /etc/nginx/sites-available/server_autoindex_off.conf /etc/nginx/sites-enabled/
fi
unlink /etc/nginx/sites-enabled/default

mkdir /etc/nginx/ssl
openssl req -new -x509 -sha256 -newkey rsa:2048 -days 365 -nodes -out /etc/nginx/ssl/nginx.pem -keyout /etc/nginx/ssl/nginx.key -subj "/C=JA/ST=Tokyo/L=Roppongi/OU=42tokyo/CN=localhost"

service nginx start
service php7.3-fpm start

tail -f /dev/null
