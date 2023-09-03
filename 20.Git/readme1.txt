master 主分支(或主干) git上自带的

master 存放永远可用的稳定的版本 不推荐直接在master分支上去开发

在分支上开发，等分支开发完成，并且也测试成功了，我们要合并在master分支上

创建分支
git branch feature-git
查看分支
git branch
切换分支
git checkout feature-git

// 如何提交 这里在分支上的功能是实现了，需要合并到主分支上
git status
git add .
git commit -m ""
git push origin <分支名>
// git pull --rebase origin <分支名>
// git push origin <分支名>
这里想要合并到主干，这时就要切换到master分支

