package bookSystem_DB;

import java.sql.*;
import java.util.Scanner;

import static java.lang.Class.forName;

public class text01 {
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        forName("com.mysql.cj.jdbc.Driver");
        //2.获取数据库连接
        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/book_System?useSSL=false&useUnicode=true&characterEncoding=UTF-8&serverTimezone=Asia/Shanghai&allowPublicKeyRetrieval=true", "root","123456");
        //3.创建PreparedStatement对象，并预编译SQL语句
        PreparedStatement show_data = connection.prepareStatement("select *from book");
        PreparedStatement add_data = connection.prepareStatement("insert into book values(?,?,?)");
        PreparedStatement drop_data = connection.prepareStatement("delete from book where id=?");
        PreparedStatement find_data = connection.prepareStatement("select* from book where id=?");

        String bookname;
        String bookauthor;
        int book_id;
        while (true) {
            System.out.println("------欢迎来到【老王书城】------");
            System.out.println("1.展示书籍");
            System.out.println("2.上新书籍");
            System.out.println("3.下架书籍");
            System.out.println("4.查询书籍");
            System.out.println("5.退出应用");

            Scanner sc = new Scanner(System.in);
            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.println("编号\t\t书名\t\t作者");
                    ResultSet rs = show_data.executeQuery();
                    boolean count=false;
                    while (rs.next()) {
                        count=true;
                        bookname = rs.getString("name");
                        bookauthor=rs.getString("author");
                        book_id=rs.getInt("id");
                        System.out.println(book_id+"\t\t"+"《"+bookname+"》"+"\t\t"+bookauthor);
                    }
                    if(!count){
                        System.out.println("还未上新书籍！！！！");
                    }
                    break;
                case 2:
                    System.out.print("请输入书编号：");
                    book_id=sc.nextInt();
                    System.out.print("请输入书名：");
                    bookname=sc.next();
                    System.out.print("请输入作者名：");
                    bookauthor= sc.next();
                    add_data.setInt(1,book_id);
                    add_data.setString(2,bookname);
                    add_data.setString(3,bookauthor);
                    if(add_data.executeUpdate()!=0)
                        System.out.println("添加成功！");
                    else
                        System.out.println("添加失败！");
                    break;
                case 3:
                    System.out.print("请输入要下架的书籍编号：");
                    int n=sc.nextInt();
                    drop_data.setInt(1,n);
                    if(drop_data.executeUpdate()!=0)
                        System.out.println("下架成功");
                    break;
                case 4:
                    System.out.print("请输入要查询的书籍编号：");
                    int m=sc.nextInt();
                    find_data.setInt(1,m);
                    ResultSet rs1=find_data.executeQuery();
                    System.out.println("编号\t\t书名\t\t作者");
                    count=false;
                    while (rs1.next()) {
                        count=true;
                        bookname = rs1.getString("name");
                        bookauthor=rs1.getString("author");
                        book_id=rs1.getInt("id");
                        System.out.println(book_id+"\t\t"+"《"+bookname+"》"+"\t\t"+bookauthor);
                    }
                    if(!count){
                        System.out.println("并未找到编号为："+m+"的书籍");
                    }
                    break;
                case 5:
                    System.out.println("欢迎下次使用！Byb");
                    return;
                default:
                    System.out.println("选择错误，请选择正确选项！");
                    break;
            }
        }
    }
}
