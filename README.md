# Description
基础库；
可按照vsdk的使用方式在s32v工程中直接执行；
也可使用cmake在x86下执行。

# Change Log

* Created by feng.ding @Hirain 20200302
- Create 5 module "common", "communication", "our_thread", "util" and "tools"

## Notice

* 在未经master所有者授权情况下，禁止泄露源码到工程成员以外人员

## 版本说明

| Version | Update | Contractor | Description | Remark |
| ------ | ------- | :----: | --------| --------- |
| V1.0.0 | 2020/03/02 |  丁丰  | 创建 | |

## 怎样使用

* 公共模块使用submodule的形式使用，`切勿复制粘提`

1. 使用 `git submodule add http://itdipdhmi.hirain.com:9990/feng.ding/itd_ipd_libs.git`将公共模块作为子模块添加进你的工程
2. clone 包含子模块的工程可使用 `git submodule updata --init --recursive` 指令
3. `git submodule foreach "git pull origin master"` 可用于所有子模块更新
