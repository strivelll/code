package javabase.IntOut;

import java.io.*;

public class Homework01 {
    public static void main(String[] args) throws IOException {
        String filePath="D:\\mytemp";
        String file="D:\\mytemp\\hello.txt";
        BufferedWriter br=new BufferedWriter(new FileWriter(file));
        File f=new File(filePath);
        File f1=new File(file);
        int read;
        if(f.exists()){
            System.out.println("mytemp已经存在");
        }else{
            if(f.mkdir()){
                System.out.println("mytemp创建成功");
            }
            else{
                System.out.println("mytemp创建失败");
            }

        }
        if(f1.exists()){
            System.out.println("hello.txt已经存在");
        }
        else{
            if(f1.createNewFile()){
                System.out.println("hello.txt创建成功");
            }
            else{
                System.out.println("hello.txt创建失败");
            }
        }
        br.write("hello,world");
        br.close();
    }
}
