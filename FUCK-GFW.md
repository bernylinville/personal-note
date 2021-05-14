# FUCK-GFW

## git

http git 代理:

```shell
git config --global https.proxy http://127.0.0.1:7890
git config --global http.proxy http://127.0.0.1:7890
```

ssh git 代理:

```config
Host github.com
  ProxyCommand nc -X 5 -x 127.0.0.1:7890 %h %p
```
