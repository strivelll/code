package TankGame;

import org.junit.jupiter.api.Test;

import java.io.*;

public class Recorder {
    private static int num=0;
    public static void keepRecorder() throws IOException {
        String fileName="D:\\编译\\刷题\\java\\javaProject\\src\\TankGame\\myTank.txt";
        String fileName1="D:\\编译\\刷题\\java\\javaProject\\src\\TankGame\\myRecord.txt";
        BufferedWriter bw=new BufferedWriter(new FileWriter(fileName1));
        bw.write(num+" ");
        bw.close();
        try(ObjectOutputStream oos=new ObjectOutputStream(new FileOutputStream(fileName))) {
            for(int i=0;i<Tank.tanks.size();i++){
                Tank t=Tank.tanks.get(i);
                oos.writeObject(t);
            }
        }
        catch(IOException e){
            e.printStackTrace();
        }

    }
    public static void ReadRecorder() throws IOException {
        String fileName="D:\\编译\\刷题\\java\\javaProject\\src\\TankGame\\myTank.txt";
        String fileName1="D:\\编译\\刷题\\java\\javaProject\\src\\TankGame\\myRecord.txt";
        BufferedReader bw=new BufferedReader(new FileReader(fileName1));
        num= bw.read()-48;//48是“0”的ASCLL值
        System.out.println(num);
        bw.close();
        try(ObjectInputStream oos=new ObjectInputStream(new FileInputStream(fileName))) {
            Object b = null;
            while (true) {
                try {
                    // 读取对象
                    Tank t = (Tank) oos.readObject();
                    Tank.tanks.add(t);
                    System.out.println(t); // 打印对象
                } catch (EOFException e) {
                    // 到达文件末尾，退出循环
                    break;
                }
            }
        }
        catch(IOException | ClassNotFoundException e){
            e.printStackTrace();
        }

    }
    public static void setEmpty() throws IOException {
        String fileName="D:\\编译\\刷题\\java\\javaProject\\src\\TankGame\\myTank.txt";
        String fileName1="D:\\编译\\刷题\\java\\javaProject\\src\\TankGame\\myRecord.txt";
        try (FileWriter fw=new FileWriter(fileName1,false);FileWriter fw1=new FileWriter(fileName,false)){
            //System.out.println("文件已清空");
            ;
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }
    public static boolean isEmpty(){
        String fileName="D:\\编译\\刷题\\java\\javaProject\\src\\TankGame\\myTank.txt";
        String fileName1="D:\\编译\\刷题\\java\\javaProject\\src\\TankGame\\myRecord.txt";
        File f=new File(fileName);
        File f1=new File(fileName1);
        if(f.exists()&&f1.exists()){
            if(f.length()==0||f1.length()==0){
                System.out.println("您之前没有游戏记录，奖重新开始新游戏");
                return true;
            }
            return false;
        }
        System.out.println("您之前没有游戏记录，奖重新开始新游戏");
        return true;
    }
    public static int getNum() {
        return num;
    }
    public static void addNum() {
        num++;
    }
}
