package javabase.Extend;

public class NotePad extends Comperter{
    public String color;
    public NotePad(int CPU, int memory, int HardDisk, String color) {
        super(CPU, memory, HardDisk);
        this.color = color;
    }
    public void printInfo() {
        System.out.println("CPU: " + this.CPU+", memory: " + this.memory+", HardDisk: " + this.HardDisk+", color: " + this.color);
    }
}
