package TankGame;

import javax.swing.*;
import java.awt.event.*;
import java.io.IOException;

public class TankGame01 extends JFrame  {
    MyPanel myPanel=null;
    public static void main(String[] args) throws IOException {
        TankGame01 tg = new TankGame01();
    }
    public TankGame01() throws IOException {
        myPanel = new MyPanel();
        this.setSize(1300, 750);
        Thread thread = new Thread(myPanel);
        thread.start();
        this.add(myPanel);//添加面板
        this.addKeyListener(myPanel);
        this.setTitle("Tank Game");//设置边框名字
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//点击x退出程序
        this.setVisible(true);

        //在JFrame中加入关闭窗口处理
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                try {
                    Recorder.keepRecorder();
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }
                System.exit(0);
            }
        });
    }

}
