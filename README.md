# Git&GitHub 笔记
From Optional Course "Opensource Hardware"
As an "External Student"

> 由于我很久以前就注册了GitHub, 一个月前完成了SSH密钥配置, 因此我会直接从使用SSH进行clone/push开始写

## SSH的作用
SSH可以让我们直接连接到GitHub的服务器, 并且不需要每次都输入密码    
和GPG不一样, 它只是一种登陆的方式(对就是远程连接到服务器的那个SSH), 不能验证提交的来源

## 使用SSH clone远程仓库
1. 本地新建文件夹, 作为仓库的本地副本的上层目录, 路径记为FFRRLC (Father Folder of Remote Repository Local Copy, 远程仓库本地副本的父目录)
2. 给它起个好名字
3. 打开Git Bash, 将目录切换到FFRRLC
4. git clone git@github.com:[USERNAME]/xd0615.git
这样, 远程仓库就被clone到了 FFRRLC/xd0615 里面

## 使用SSH 推送修改
