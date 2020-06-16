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

1. 使用git add将内容添加到暂存区(stage/index, 位于xd0615/.git里面)

2. 使用git commit提交更改, 实质上是把暂存区的内容提交到当前分支(的本地副本中, 并没有到服务器)    

   也就是说, 在git add之后即使是同一文件进行的修改也不会重复提交

   可以多次对同一文件进行add, 也可以先commit再add

3. 使用git push把所有本地的修改推送到服务器, 关于git push, [参见GitHub的官方文档](https://help.github.com/cn/github/using-git/pushing-commits-to-a-remote-repository)

   