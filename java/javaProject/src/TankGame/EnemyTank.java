package TankGame;

import static java.lang.Thread.sleep;

public class EnemyTank extends Tank implements Runnable {
    private int count=0;//人机走的步数


    public EnemyTank(int x, int y, int speed) {
        super(x, y);
        setType(0);
        setDirect(1);
        setSpeed(speed);
    }

    @Override
    public void run() {
        while(true) {
            if (this.isLive()) {
                int random = (int) (Math.random() * 10);
                //System.out.println(random);
                int distance = (int) (Math.random() * 30);
                if (random == 1) {
                    try {
                        this.TankMoveRight(distance);
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                } else if (random == 2) {
                    try {
                        this.TankMoveLeft(distance);
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                } else if (random == 3) {
                    try {
                        this.TankMoveUp(distance);
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                } else if (random == 4) {
                    try {
                        this.TankMoveDown(distance);
                    } catch (InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                }
                if (this.getCount() > 30) {
                    ShotTank();
                    this.setCount(0);
                }
                try {
                    sleep(500);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
            else{
                break;
            }
        }
    }
    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }
    //distance 是移动的次数
    public void TankMoveDown(int distance) throws InterruptedException {
        for(int i=0;i<distance;i++) {
            super.TankMoveDown();
            sleep(100);
            count++;
        }
    }
    public void TankMoveUp(int distance) throws InterruptedException {
        for(int i=0;i<distance;i++) {
            super.TankMoveUp();
            sleep(100);
            count++;
        }
    }
    public void TankMoveRight(int distance) throws InterruptedException {
        for(int i=0;i<distance;i++) {
            super.TankMoveRight();
            sleep(100);
            count++;
        }
    }
    public void TankMoveLeft(int distance) throws InterruptedException {
        for(int i=0;i<distance;i++) {
            super.TankMoveLeft();
            sleep(100);
            count++;
        }
    }
}
