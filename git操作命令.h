一、CocoaPods安装
1.移除现有Ruby默认源
$gem sources --remove https://rubygems.org/

2.使用新的源
$gem sources -a https://ruby.taobao.org/

3.验证新源是否替换成功
$gem sources -l

4.安装CocoaPods
(1) $sudo gem install cocoapods 备注：苹果系统升级 OS X EL Capitan 后改为 $sudo gem install -n /usr/local/bin cocoapods
(2) $pod setup

5.更新gem
$sudo gem update --system

二、第三方库操作
$pod search 第三方（查找第三方库）

1.项目导入第三方
（1）终端用cd指令到文件夹内
（2）新建文件 vim “Podfile”
（3）写入以下内容并保存 小提示：（终端vim文件 按 i 可编辑 ，esc 退出编辑，：wq  可保存退出）
platform:ios, ’10.0’
target “项目名” do
pod 'MBProgressHUD', '~> 0.9.2'    <-------第三方
end
（4）保存并退出vim后终端输入命令 $pod install


三、git上传项目流程
1.GitHub 上注册账号  https://github.com/ 去这上面注册下就行。

2.配置 SSH key
 ①  defaults write com.apple.finder AppleShowAllFiles -bool true     终端 显示隐藏文件（需要重新运行Finder)。
 ② 点击桌面顶部菜单  前往>个人  看看自己电脑上有没有个 .ssh 的隐藏文件，有的话个人建议删除，新建个。
 ③  mkdir .ssh    终端新建个 .ssh文件
 ④  cd .ssh   进入到刚才新建的.ssh文件目录下
 ⑤  ssh-Keygen -t rsa -C "your_email@example.com"       后面“ ”里面 随意输入个邮箱就行,回车会提示你输入密码什么的，可以无视一直回车下去。
 ⑥  ls -la      查看是否存在 id_rsa(私钥)  id_rsa.pub(公钥) 这两个东西，如果存在就成功了。
 ⑦ pbcopy < ~/.ssh/id_rsa.pub     拷贝 公钥
 ⑧ 进入GitHub 登入 。创建一个项目。如图4 - 图6 所示 添加你刚才生成的SSH Key 到GitHub上，也就是最后一张图的 Add SSH Key 点击 会让你输入秘钥 以及秘钥的名称。 秘钥 pbcopy < ~/.ssh/id_rsa.pub 这个终端命令就已经复制过了  直接command + V 粘贴上去就行，秘钥名称随意。
⑨  ssh -T git@github.com   新添加到github上的秘钥左边的点一开始是灰色的，终端执行这个命令后，刷新网页会看到灰色点变成了绿色。

3.在GitHub 上创建公开项目

4. 上传本地项目到GitHub。
   （1） 在电脑上新建个项目 。
   （2） cd + 刚才新建的项目文件夹路径（如何在终端输入路径，可以直接把你想要知道路径的文件夹拖到终端里 这样自动就要该文件夹的路径了）
（3）git init    (git 仓库的初始化)
   （4）git add .    (这里注意：add 空格 再加 .)
   （5） git status    (查看add 成功没)
   （6）git commit -m "描述"   （“ ” 引号里面输入你的描述 随意）
   （7）git remote add origin https://github.com/账号名/项目名.git //添加到远程项目，别名为origin
（8）git push -u origin master        (最后push到GitHub上)

5. 克隆github项目到本地
    git clone + GitHub 上创建的项目地址    （GitHub 上创建的项目地址如下图所示）这样你在GitHub 上创建的项目就克隆下来了

6. 更新项目到github
（1）cd 到需要跟新的项目
（2）git add .    (这里注意：add 空格 再加 .)
（3）git commit -m "描述"   （“ ” 引号里面输入你的描述 随意）
（4）git push origin master或（git push -u origin master）       (最后push到GitHub上)

7.github远程pull到本地
（1）cd 到需要跟新的项目
（2）git pull origin master或（git pull -u origin master） //从Github上pull到本地源码库

四、.github常用命令
git push origin master //把本地源码库push到Github上
git pull origin master //从Github上pull到本地源码库
git config --list //查看配置信息
git status //查看项目状态信息
git branch //查看项目分支
git checkout -b host//添加一个名为host的分支
git checkout master //切换到主干
git merge host //合并分支host到主干
git branch -d host //删除分支host
>>>删除远程分支
命令：$ git push origin 【空格】【冒号】【你的分支名字】
比如我github上有master和feature分支，我现在想着删除feature分支，命令如下：
$ git push origin :feature

五、git修改远程仓库地址 ，方法有三种：
（1）.修改命令
git remote origin set-url [url]
（2）.先删后加
git remote rm origin
git remote add origin [url]
（3）.直接修改config文件

六、github创建tag
1.查看tag—列出所有tag：
git tag
这样列出的tag是按字母排序的，和创建时间没关系。如果只是想查看某些tag的话，可以加限定：
git tag -l v1.*
这样就只会列出1.几的版本。

2.创建tag
创建轻量级tag：
git tag v1.0
这样创建的tag没有附带其他信息，与之相应的是带信息的tag：
git tag -a v1.0-m 'first version'
-m后面带的就是注释信息，这样在日后查看的时候会很有用，这种是普通tag，还有一种有签名的tag：
git tag -s v1.0-m 'first version'
前提是你有GPG私钥，把上面的a换成s就行了。除了可以为当前的进度添加tag，我们还可以为以前的commit添加tag：

#首先查看以前的commit
git log --oneline
#假如有这样一个commit：8a5cbc2 updated readme
#这样为他添加tag
git tag -a v1.18a5cbc2

3.删除tag
很简单，知道tag名称后：
git tag -d v1.0
删除远程标签
git push origin :refs/tags/v1.01

4.验证tag
如果你有GPG私钥的话就可以验证tag：
git tag -v v1.0

5.共享tag
我们在执行git push的时候，tag是不会上传到服务器的，比如现在的github，创建tag后git push，在github网页上是看不到tag的，
为了共享这些tag，你必须这样：
git push origin --tags

