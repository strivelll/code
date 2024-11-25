package bookSystem_io;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class text01 {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ArrayList<book> Arr = new ArrayList<>();
        String bookname;
        String bookauthor;
        book B;
        File f=new File("D:/book.txt");
        if (f.createNewFile()) {
            System.out.println("文件已成功创建: " + f.getName());
        }
        else{
            FileInputStream fis = new FileInputStream(f);
            ObjectInputStream fr = new ObjectInputStream(fis);
            Arr = (ArrayList) fr.readObject();
            fis.close();
            fr.close();
        }
        while (true) {
            System.out.println("------欢迎来到【老王书城】------");
            System.out.println("1.展示书籍");
            System.out.println("2.上新书籍");
            System.out.println("3.下架书籍");
            System.out.println("4.退出应用");

            Scanner sc = new Scanner(System.in);
            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    if(Arr.isEmpty()){
                        System.out.println("还未上新书籍！！！！");
                    }
                    else{
                        System.out.println("序号\t\t书名\t\t作者");
                        for(int i=0;i<Arr.size();i++){
                            Arr.get(i).showinfo(i+1);
                        }
                    }
                    break;
                case 2:
                    System.out.print("请输入书名：");
                    bookname=sc.next();
                    System.out.print("请输入作者名：");
                    bookauthor= sc.next();
                    B=new book(bookname,bookauthor);
                    Arr.add(B);
                    System.out.println("添加成功！");
                    break;
                case 3:
                    System.out.print("请输入书籍序号：");
                    int n=sc.nextInt();
                    B=Arr.remove(n-1);
                    System.out.println("下架"+"《"+B.name+"》"+"成功");
                    break;
                case 4:
                    System.out.println("欢迎下次使用！Byb");
                    FileOutputStream fout=new FileOutputStream(f);
                    ObjectOutputStream oos=new ObjectOutputStream(fout);
                    oos.writeObject(Arr);
                    fout.close();
                    oos.close();
                    return;
                default:
                    System.out.println("选择错误，请选择正确选项！");
                    break;
            }
        }
    }
}
