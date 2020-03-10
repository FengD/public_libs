# Description

Thread

# Change Log

* Created by feng.ding @Hirain 20200302
- thread base
- thread mutex

## Notice

* 在未经master所有者授权情况下，禁止泄露源码到工程成员以外人员

## 版本说明

| Version | Update | Contractor | Description | Remark |
| ------ | ------- | :----: | --------| --------- |
| V1.0.0 | 2020/03/02 |  丁丰  | 创建 | |
| V1.0.1 | 2020/03/10 |  丁丰  | 添加多消息时间同步机制（目前支持两个消息）| |
| V1.0.2 | 2020/03/10 |  丁丰  | 创建消息头文件 | |
| V1.0.3 | 2020/03/02 |  丁丰  | 创建同步消息队列，支持线程之间单对单通讯 | |

## 依赖
```
yaml-cpp
pthread
tools/hlog
```
