FROM ghcr.io/linuxserver/baseimage-ubuntu:focal

# environment variables
ARG DEBIAN_FRONTEND="noninteractive"
ENV MYSQL_DIR="/config"
ENV DATADIR=$MYSQL_DIR/databases
ENV MARIADB="mariadb-server"

RUN \
 echo "**** install gnupg ****" && \
 apt-get update && \
 apt-get install -y gnupg && \
 echo "add mariadb repository ****" && \
 echo "(redundant on armhf platform, but added for consistent dockerfile on all platforms) ****" && \
 apt-key adv --recv-keys --keyserver hkp://keyserver.ubuntu.com:80 0xF1656F24C74CD1D8 && \
 echo "deb http://mirror.rackspace.com/mariadb/repo/10.5/ubuntu focal main" >> /etc/apt/sources.list.d/mariadb.list && \
 echo "deb-src http://mirror.rackspace.com/mariadb/repo/10.5/ubuntu focal main" >> /etc/apt/sources.list.d/mariadb.list && \
 echo "**** install runtime packages ****" && \
 apt-get update && \
 apt-get install -y ${MARIADB} && \
 echo "**** cleanup ****" && \
 rm -rf \
	/tmp/* \
	/var/lib/apt/lists/* \
	/var/lib/mysql \
	/var/tmp/* && \
    mkdir -p \
	/var/lib/mysql

# add local files
COPY root/ /

# ports and volumes
EXPOSE 3306
VOLUME /config
