package javabase.jdbc;

import java.sql.*;
import java.util.Properties;

public class test {
    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        String url = "jdbc:mysql://localhost:3306/egg?serverTimezone=Asia/Shanghai&useSSL=false";
        String username = "root";
        String password = "123456";
        try {
            Connection connection = DriverManager.getConnection(url, username, password);
            Statement statement = connection.createStatement();
            String sql = "insert into ew values(1111,1111)";
            // 连接成功后可以进行后续数据库操作
            statement.executeUpdate(sql);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
