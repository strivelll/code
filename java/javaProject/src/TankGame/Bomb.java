package TankGame;

import javax.swing.*;
import java.util.Vector;

public class Bomb {
    static Vector<Bomb> bomb=new Vector<>();
    int x;
    int y;
    int live=9;
    boolean isLive=true;

    public Bomb(int x, int y) {
        this.x = x;
        this.y = y;
    }
    public void injure() {
        if(live>0){
            live--;
        }
        else{
            SwingUtilities.invokeLater(() -> {
                bomb.remove(this);
            });
        }
    }
}
