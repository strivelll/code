package com.qqcommon;
/**
 * @author strive
 * @version 1.0
 * 表示消息类型
 */
public interface MessageType {
    String MESSAGE_LOGIN_SUCCEED = "1";//登录成功
    String MESSAGE_LOGIN_FAIL = "2";//登录失败
    String MESSAGE_FLUSH = "3";//显示在线用户
    String MESSAGE_SEND_EVERYBODY = "4";//群发消息
    String MESSAGE_SEND_PRIVATE = "5";//私聊消息
    String MESSAGE_SEND_FILE = "6";//发送文件
    String MESSAGE_QUIT_SYSTEM = "7";//退出系统
}
