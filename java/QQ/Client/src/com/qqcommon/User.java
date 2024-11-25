package com.qqcommon;

import java.io.Serializable;
/**
 * @author strive
 * @version 1.0
 * 表示一个用户信息
 */
public class User implements Serializable {
    private static final long serialVersionUID = 1L;
    private String userId;
    private String passwd;
    public User() {}
    public User(String passwd, String userId) {
        this.passwd = passwd;
        this.userId = userId;
    }

    public String getUserId() {
        return userId;
    }

    public void setUserId(String userId) {
        this.userId = userId;
    }

    public String getPasswd() {
        return passwd;
    }

    public void setPasswd(String passwd) {
        this.passwd = passwd;
    }
}
