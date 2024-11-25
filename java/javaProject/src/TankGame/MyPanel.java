package TankGame;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.IOException;
import java.util.Objects;
import java.util.Scanner;
import java.util.Vector;

public class MyPanel extends JPanel implements KeyListener, Runnable {
    Heor heor = null;
    Image image1 = null;
    Image image2 = null;
    Image image3 = null;

    public MyPanel() throws IOException {

        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("请选择 1，重新游戏    2，继续游戏 ");
            System.out.print("请选择:>");
            int input = scanner.nextInt();//
            boolean isempty=false;//判断之前是否有记录
            if(input == 2) {
                isempty = Recorder.isEmpty();
            }
            if(!isempty&&input == 2) {//有记录且选择继续游戏
                Recorder.ReadRecorder();
                heor=(Heor) Tank.tanks.get(0);
                break;

            }
            else if(isempty||input == 1) {//无记录或选择新游戏
                heor = new Heor(600, 600);
                Tank.tanks.add(heor);
                for (int i = 0; i < 3; i++) {
                    EnemyTank e = new EnemyTank((i + 1) * 100, 0, 10);
                    Tank.tanks.add(e);
                }
                break;
            }else{
                System.out.println("输入错误！！！请重新输入");
            }
        }


        image1 = Toolkit.getDefaultToolkit().getImage(getClass().getResource("417eadd3b72ff0f727243df357b500de.jpg"));
        image2 = Toolkit.getDefaultToolkit().getImage(getClass().getResource("20230108160603.png"));
        image3 = Toolkit.getDefaultToolkit().getImage(getClass().getResource("20230108161322.png"));
    }

    @Override
    public void run() {
        while (true) {
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            repaint();
            hitTank();
        }
    }
    public void showInfo(Graphics g){
        g.setColor(Color.black);
        Font font = new Font("宋体", Font.BOLD, 20);
        g.setFont(font);
        g.drawString("您累积击毁敌方坦克",1020,30);
        g.drawString("您的血量",1020,140);
        DrawTank(1020,60,g,0,0);
        g.setColor(Color.black);
        g.drawString("x"+Recorder.getNum()+" ",1200,90);
        g.drawString("x"+heor.getHealth()+" ",1200,140);
    }
    @Override
    public void paint(Graphics g) {
        super.paint(g);
        g.fillRect(0, 0, 1000, 750);
        showInfo(g);
        heor.setSpeed(10);
        //画坦克
        for (int i = 0; i < Tank.tanks.size(); i++) {
            Tank en = Tank.tanks.get(i);
            DrawTank(en.getX(), en.getY(), g, en.getDirect(), en.getType());
            if (en.getType() == 0&&!en.isFlag()) {
                Thread t = new Thread((EnemyTank) en);
                t.start();
                en.setFlag(true);
            }
        }
        //画子弹轨迹
        if (!Shot.getShot().isEmpty()) {
            DrawShot(g);
        }
        DrawBomb(g);
        if(Tank.tanks.get(0).getType()!=1){
            System.out.println("您的血量已经耗尽，游戏结束");
            try {
                Recorder.setEmpty();
                System.exit(0);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        else if(Tank.tanks.size()==1){
            System.out.println(Recorder.getNum());
            System.out.println("您已经击杀所有的敌人，游戏结束");
            try {
                Recorder.setEmpty();
                System.exit(0);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }

    /**
     * @param x      坦克左上角x坐标
     * @param y      坦克左上角y坐标
     * @param g      画笔
     * @param direct 方向（上下左右）
     * @param type   类型
     */
    public void DrawTank(int x, int y, Graphics g, int direct, int type) {
        switch (type) {
            case 0://敌人的坦克
                g.setColor(Color.blue);
                break;
            case 1://玩家的坦克
                g.setColor(Color.red);
                break;
        }
        switch (direct) {
            case 0://up
                g.fill3DRect(x, y, 15, 50, false);//履带1
                g.fill3DRect(x + 15, y + 10, 15, 30, false);//中间
                g.fill3DRect(x + 30, y, 15, 50, false);//履带2
                g.fillOval(x + 15, y + 16, 15, 15);//圆
                g.drawLine(x + 23, y + 23, x + 23, y - 7);//炮口
                break;
            case 1://down
                g.fill3DRect(x, y, 15, 50, false);//履带1
                g.fill3DRect(x + 15, y + 10, 15, 30, false);//中间
                g.fill3DRect(x + 30, y, 15, 50, false);//履带2
                g.fillOval(x + 15, y + 16, 15, 15);//圆
                g.drawLine(x + 23, y + 23, x + 23, y + 53);//炮口
                break;
            case 2://left
                g.fill3DRect(x, y, 50, 15, false);//履带1
                g.fill3DRect(x + 10, y + 15, 30, 15, false);//中间
                g.fill3DRect(x, y + 30, 50, 15, false);//履带2
                g.fillOval(x + 16, y + 15, 15, 15);//圆
                g.drawLine(x + 24, y + 23, x - 6, y + 23);//炮口
                break;
            case 3://right
                g.fill3DRect(x, y, 50, 15, false);//履带1
                g.fill3DRect(x + 10, y + 15, 30, 15, false);//中间
                g.fill3DRect(x, y + 30, 50, 15, false);//履带2
                g.fillOval(x + 16, y + 15, 15, 15);//圆
                g.drawLine(x + 24, y + 23, x + 54, y + 23);//炮口
                break;
        }

    }

    public void DrawShot(Graphics g) {
        for (int i = 0; i < Shot.getShot().size(); i++) {
            Shot shot = Shot.getShot().get(i);
            if (shot.getType() == 1) {
                g.setColor(Color.red);
            } else {
                g.setColor(Color.blue);
            }
            if (shot.getFlag() == 2) {
                g.fillOval(shot.getX(), shot.getY(), 4, 4);
                //System.out.println(shot.getX()+"+++++++"+shot.getY());
            }
        }
        // repaint();
        //System.out.println(heor.getShot().getX()+"====="+ heor.getShot().getY());
    }

    public void DrawBomb(Graphics g) {
        if (!Bomb.bomb.isEmpty()) {
            for (int i = 0; i < Bomb.bomb.size(); i++) {
                Bomb b = Bomb.bomb.get(i);
                if (b.live > 6) {
                    g.drawImage(image1, b.x, b.y, 50, 50, this);
                } else if (b.live > 3) {
                    g.drawImage(image2, b.x, b.y, 50, 50, this);
                } else {
                    g.drawImage(image3, b.x, b.y, 50, 50, this);
                }
                b.injure();
            }
        }
    }

    public void hitTank() {
        for (int i = 0; i < Shot.getShot().size(); i++) {
            Shot shot = Shot.getShot().get(i);
            for (int j = 0; j < Tank.tanks.size(); j++) {
                Tank tank = Tank.tanks.get(j);
                if (((tank instanceof Heor)||shot.getType() == 1) && (tank.getDirect() == 0 || tank.getDirect() == 1) &&
                        shot.getX() > tank.getX() && shot.getX() < tank.getX() + 45 &&
                        shot.getY() > tank.getY() && shot.getY() < tank.getY() + 50) {
                    shot.setLive(false);
                    Bomb.bomb.add(new Bomb(tank.getX(), tank.getY()));
                    tank.injured();
                    if(tank instanceof EnemyTank){
                        Recorder.addNum();
                    }
                    //直接删除人机
                    if (!tank.isLive()) {
                        SwingUtilities.invokeLater(() -> {
                            Tank.tanks.remove(tank);
                        });
                    }

                }
                if (((tank instanceof Heor)||shot.getType() == 1) && (tank.getDirect() == 2 || tank.getDirect() == 3) &&
                        shot.getX() > tank.getX() && shot.getX() < tank.getX() + 50 &&
                        shot.getY() > tank.getY() && shot.getY() < tank.getY() + 45) {
                    shot.setLive(false);
                    Bomb.bomb.add(new Bomb(tank.getX(), tank.getY()));
                    tank.injured();
                    if(tank instanceof EnemyTank){
                        Recorder.addNum();
                    }
//                    直接删除人机
                    if (!tank.isLive()) {
                        SwingUtilities.invokeLater(() -> {
                            Tank.tanks.remove(tank);
                        });
                    }
                }
            }
        }
    }

    //有字符输出时就会触发该方法
    @Override
    public void keyTyped(KeyEvent e) {

    }

    //有键被按下时会触发
    @Override
    public void keyPressed(KeyEvent e) {
        if (heor.isLive()) {
            if (e.getKeyCode() == KeyEvent.VK_D) {
                heor.TankMoveRight();
            } else if (e.getKeyCode() == KeyEvent.VK_A) {
                heor.TankMoveLeft();
            } else if (e.getKeyCode() == KeyEvent.VK_W) {
                heor.TankMoveUp();
            } else if (e.getKeyCode() == KeyEvent.VK_S) {
                heor.TankMoveDown();
            } else if (e.getKeyCode() == KeyEvent.VK_J) {
                heor.ShotTank();
            }
            //repaint();
        }
    }

    //有键被释放时触发
    @Override
    public void keyReleased(KeyEvent e) {


    }
}
