# nextcloud

mysql script
```shell
CREATE USER 'nextcloud'@'%' IDENTIFIED BY 'password';
CREATE DATABASE IF NOT EXISTS nextcloud CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci;
GRANT ALL PRIVILEGES on nextcloud.* to 'nextcloud'@'%';
FLUSH privileges;
```
