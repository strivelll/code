package TankGame;

import java.io.Serializable;
import java.util.Vector;

import static java.lang.Math.pow;

public class Tank implements Serializable {
    private int x;
    private int y;
    private final int start_x;//出生点
    private final int start_y;//出生点
    private int direct;//方向
    private int speed;//速度
    private int type;//种类 0.敌方 1.己方
    private boolean isLive = true;//是否存活
    private int health = 3;//血量

    public int getHealth() {
        return health;
    }

    static Vector<Tank> tanks = new Vector();//所有坦克集合
    private transient boolean flag = false;//线程是否开启

    @Override
    public String toString() {
        return "Tank{" +
                "y=" + y +
                ", x=" + x +
                ", type=" + type +
                ", direct=" + direct +
                ", start_x=" + start_x +
                ", start_y=" + start_y +
                ", speed=" + speed +
                ", isLive=" + isLive +
                ", health=" + health +
                ", flag=" + flag +
                '}';
    }

    public boolean isFlag() {
        return flag;
    }

    public void setFlag(boolean flag) {
        this.flag = flag;
    }

    public void injured() {
        health--;
        if (health <= 0) {
            isLive = false;
        } else {
            x = start_x;
            y = start_y;
            while(isCrash(direct)){
                x+=100;
            }
        }
    }

    public boolean isLive() {
        return isLive;
    }

    public Tank(int x, int y) {
        this.x = x;
        this.y = y;
        start_x = x;
        start_y = y;
    }

    public void TankMoveUp() {
        if (y - speed < 0 || isCrash(0)) {
            return;
        }
        y -= speed;
        setDirect(0);
    }

    public void TankMoveDown() {
        if (y + speed > 668 || isCrash(1)) {
            return;
        }
        y += speed;
        setDirect(1);
    }

    public void TankMoveLeft() {
        if (x - speed < 0 || isCrash(2)) {
            return;
        }
        x -= speed;
        setDirect(2);
    }

    public void TankMoveRight() {
        if (x + speed > 935 || isCrash(3)) {
            return;
        }
        x += speed;
        setDirect(3);
    }

    public boolean isCrash(int direct) {
        boolean result = false;
        for (int i = 0; i < tanks.size(); i++) {
            Tank tank = (Tank) tanks.elementAt(i);
            if (this == tanks.get(i)) {
                continue;
            } else {
//                System.out.println("bbbbbbbbbbb");
                if (direct == 0 || direct == 1) {
                    int offset = direct == 0 ? -speed : speed;
                    offset += this.y;
                    if (tank.getDirect() == 1 || tank.getDirect() == 0) {
                        if (((offset >= tank.getY() && offset <= tank.getY() + 50)||(offset+50 >= tank.getY() && offset+50 <= tank.getY() + 50)) &&
                                ((x >= tank.getX() && x <= tank.getX() + 45)||(x+45 >= tank.getX() && x+45 <= tank.getX() +45))) {
                            result = true;
                        }
                    }
                    else{
                        if (((offset >= tank.getY() && offset <= tank.getY() + 45) ||(offset+50 >= tank.getY() && offset+50 <= tank.getY() + 45))&&
                                ((x >= tank.getX() && x <= tank.getX() + 50)||(x+45 >= tank.getX() && x+45 <= tank.getX() +50))) {
                            result = true;
                        }
                    }
                } else if (direct == 2||direct == 3) {
                    int offset = direct == 2 ? -speed : speed;
                    offset += this.x;
                    if (tank.getDirect() == 1 || tank.getDirect() == 0) {
                        if (((offset >= tank.getX() && offset <= tank.getX() + 45)||(offset+50 >= tank.getX() && offset+50 <= tank.getX() + 45))&&
                                ((y >= tank.getY() && y <= tank.getY() + 50)||(y+45 >= tank.getY() && y+45 <= tank.getY() +50))) {
                            result = true;
                        }
                    }
                    else{
                        if (((offset >= tank.getX() && offset <= tank.getX() + 50)||(offset+50 >= tank.getX() && offset+50 <= tank.getX() + 50) )&&
                                ((y >= tank.getY() && y <= tank.getY() + 45)||(y+45 >= tank.getY() && y+45 <= tank.getY() +45))) {
                            result = true;
                        }
                    }
                }
            }
        }
        return result;
    }

    public synchronized void ShotTank() {
        switch (direct) {
            case 0:
                Shot.getShot().add(new Shot(x + 23, y - 7, speed, direct, type));
                break;
            case 1:
                Shot.getShot().add(new Shot(x + 23, y + 53, speed, direct, type));
                break;
            case 2:
                Shot.getShot().add(new Shot(x - 6, y + 23, speed, direct, type));
                break;
            case 3:
                Shot.getShot().add(new Shot(x + 54, y + 23, speed, direct, type));
                break;
        }
        for (int i = 0; i < Shot.getShot().size(); i++) {
            Shot s = Shot.getShot().get(i);
            if (s.getFlag() == 1) {
                s.start();
                s.setFlag(2);
            }
        }
    }

    public int getSpeed() {
        return speed;
    }

    public void setSpeed(int speed) {
        this.speed = speed;
    }

    public int getType() {
        return type;
    }

    public void setType(int type) {
        this.type = type;
    }

    public int getX() {
        return x;
    }

    public void setDirect(int direct) {
        this.direct = direct;
    }

    public int getDirect() {
        return direct;
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
}
