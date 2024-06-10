# FunnyJsonExplorer

中山大学软件工程小型课程项目

是一个基于C++实现的JSON文件可视化的命令行界面小工具

- 可以指定不同的可视化风格
- 可以设置节点图标样式



## 开发环境

- 操作系统：Window10
- IDE：VSCode



## 构建可执行文件

在项目根目录，执行以下命令以构建可执行文件

```shell
mkdir build
cd build
cmake ..
cmake --build .
```



## 运行

在项目根目录，执行以下命令以运行

```shell
cd build
./Debug/fje -f <json file path> -s <style> -i <icon family>
```

