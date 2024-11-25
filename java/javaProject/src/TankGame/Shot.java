package TankGame;

import javax.swing.*;
import java.awt.*;
import java.util.Vector;

public class Shot extends Thread {
    private static Vector<Shot> shot = new Vector<>();
    private int x;
    private int y;
    private int speed;
    private int direct = 0;
    private int flag = 1;//子弹处于的阶段 1.初始化线程未启动 2.线程运行中
    private int type;
    private boolean isLive = true;

    public boolean isLive() {
        return isLive;
    }

    public void setLive(boolean live) {
        isLive = live;
    }

    public synchronized int getFlag() {
        return flag;
    }
    public void setFlag(int flag) {
        this.flag = flag;
    }

    public static Vector<Shot> getShot() {
        return shot;
    }
    public static void setShot(Vector<Shot> shot) {
        Shot.shot = shot;
    }

    @Override
    public void run() {
        flag=2;
        while (isLive&&x > 0 && y > 0 && x < 1000 && y < 750) {
            switch (direct) {
                case 0:
                    y -= speed;
                    break;
                case 1:
                    y += speed;
                    break;
                case 2:
                    x -= speed;
                    break;
                case 3:
                    x += speed;
                    break;
            }
            try {
                sleep(50);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            //System.out.println(x+"=========="+y);
        }
        flag=0;
        SwingUtilities.invokeLater(()->{
            shot.remove(this);
        });
        //System.out.println("攻击线程结束"+shot.size());
    }

    public int getType() {
        return type;
    }

    public void setType(int type) {
        this.type = type;
    }

    public Shot(int x, int y, int speed, int direct, int type) {
        this.x = x;
        this.y = y;
        this.speed = speed;
        this.direct = direct;
        this.type = type;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getSpeed() {
        return speed;
    }

    public void setSpeed(int speed) {
        this.speed = speed;
    }

    public int getDirect() {
        return direct;
    }

    public void setDirect(int direct) {
        this.direct = direct;
    }


}
