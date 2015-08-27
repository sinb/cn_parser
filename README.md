##中文分词功能实现:
目前实现了根据词典的最大正向匹配方法和HMM方法,HMM不知道为何(这该如何debug..)效果太差,在另一个main里.
##安装
```shell
mkdir build && cd build
cmake .. && make
```
##使用
echo "我的滑板鞋时尚时尚最时尚" | ./cn_parser 

我的 滑板鞋 时尚 时尚 最 时尚