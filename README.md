# Description
基础库；
可按照vsdk的使用方式在s32v工程中直接执行；
也可使用cmake在x86下执行。

# Change Log
- Created by feng.ding @Hirain 20200302
- Create 5 module "common", "communication", "our_thread", "util" and "tools" by feng.ding @Hirain 20200404
- Create add mqtt & protobuf module in communication by feng.ding @Hirain 20200425
- Create Json module by feng.ding @Hirain 20200501
- update static check module by feng.ding @Hirain 20200601


## 版本说明
| Version | Update | Contractor | Description | Remark |
| ------ | ------- | :----: | --------| --------- |
| V1.0.0 | 2020/03/02 |  丁丰  | 创建 | |
| V2.0.0 | 2020/04/25 |  丁丰  | 更新了mqtt和protobuf模块，支撑感知3.0的开发 | |
| V2.0.1 | 2020/06/01 |  丁丰  | 修复库中代码静态查问题 | |
| V2.0.2 | 2020/07/25 |  丁丰  | socket can can tx 添加example, 添加非阻塞发送 | |
| V2.0.3 | 2020/08/24 |  丁丰  | 添加share memory module, c style and posix style | |

## 怎样使用

* 公共模块使用submodule的形式使用，`切勿复制粘提`

1. 使用 `git submodule add https://github.com/FengD/public_libs.git`将公共模块作为子模块添加进你的工程
2. clone 包含子模块的工程可使用 `git submodule update --init --recursive` 指令
3. `git submodule foreach "git pull origin master"` 可用于所有子模块更新
