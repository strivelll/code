package javabase.Thread;

public class thread01 {
    public static void main(String[] args) {
        Cat cat=new Cat();
        cat.start();
    }
}

class Cat extends Thread{
    @Override
    public void run() {
        int times=0;
        while(true) {
            System.out.println("小猫 喵喵喵"+(++times));
            try {
                sleep(1000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            if(times==10) {
                break;
            }
        }
    }
}