# pve

```shell
# 备份
cp /usr/share/javascript/proxmox-widget-toolkit/proxmoxlib.js{,.bk}
# 关闭You do not have a valid subscription for this server弹窗
grep -P "!== 'Active'" /usr/share/javascript/proxmox-widget-toolkit/proxmoxlib.js &&
  sed -ri.bak  '/!== '"'Active'"'/{s#\([^)]+\)#(false)#}' /usr/share/javascript/proxmox-widget-toolkit/proxmoxlib.js
# 关闭企业源
mv /etc/apt/sources.list.d/pve-enterprise.list{,.bk}

# 下载秘钥
wget http://download.proxmox.com/debian/proxmox-ve-release-6.x.gpg -O /etc/apt/trusted.gpg.d/proxmox-ve-release-6.x.gpg
# Verify the checksum
sha512sum /etc/apt/trusted.gpg.d/proxmox-ve-release-6.x.gpg
acca6f416917e8e11490a08a1e2842d500b3a5d9f322c6319db0927b2901c3eae23cfb5cd5df6facf2b57399d3cfa52ad7769ebdd75d9b204549ca147da52626 /etc/apt/trusted.gpg.d/proxmox-ve-release-6.x.gpg
# 添加社区源
echo "deb http://download.proxmox.com/debian/pve buster pve-no-subscription" >/etc/apt/sources.list.d/pve-install-repo.list

```

## lede(旁路由)

```shell
# 网卡 intel E1000
# 导入镜像（pve 下）
qemu-img convert -f raw  -O qcow2 openwrt-x86-64-generic-squashfs-combined-efi.img op.qcow2
qemu-img check op.qcow2
qm importdisk 100 op.qcow2 local-lvm

# lede 下
cp /etc/config/network /etc/config/network.bak

vi /etc/config/network
config interface 'eth0'
	option ifname 'eth0'
	option proto 'static'
	option ipaddr '192.168.2.3'
	option netmask '255.255.255.0'
	option gateway '192.168.2.1'

/etc/init.d/network restart

```
