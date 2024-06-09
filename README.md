# README.md

### Notice

查看和修改电机 ID 会让电机切换到工厂模式，如果不手动切换回电机模式，即使给电机重新上电也还会进入工厂模式,**本人第一次使用电机因为没有注意这点而卡了几个小时**

### 我的运行平台
Ubuntu22.04

### 支持的电机
support motor: GO-M8010-6 motor

not support motor: A1 motor、 B1 motor (Check A1B1 branch for support)

### Build
```bash
mkdir build
cd build
cmake ..
make
```

### Run
Run examples with 'sudo',e.g.
```bash
sudo ./motorctrl
```

### tips
查看和修改电机ID 会让电机切换到工厂模式，如果不手动切换回电机模式，即使给电机重新上电也还会进入工厂模式，所以当电机无法运动时，可以检查一下是不是出现这种错误



### ATTENTION
K_w给到1，电机会很响