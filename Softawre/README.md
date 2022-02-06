# Robot日志

# 22.2.5 

### orangepi的用户名和密码：

```
root
orangepi
```

### ssh登陆指令为：

```
ssh root@192.168.0.105 //使用wifi直连
ssh root@192.168.1.5 //使用网线连接；
```

### 连接WIFI

首先使用 nmcli dev wifi 命令扫描周围的 WIFI 热点

```
nmcli dev wifi 
```

```shell
nmcli dev wifi connect tianxiaohuawifi password 88888888
```

# 

### 为了测试音乐是不是可以正常输出播放，在orangepi上安装了音乐播放器； https://zhuanlan.zhihu.com/p/94871125

```
sudo apt-get install sox //终端音乐播放器
sudo apt-get install sox libsox-fmt-all //用于解码
```

### 调节音量的大小 linux下使用命令行来调节系统音量的两种方法amixer和pactl

```
alsamixer
```

会谈出可视化窗口，使用界面方式调节声音的大小

