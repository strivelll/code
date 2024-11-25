package javabase.Extend;

public class PC extends Comperter{
    public String brand;
    public PC(int CPU, int memory, int HardDisk, String brand) {
        super(CPU, memory, HardDisk);
        this.brand = brand;
    }
    public void printInfo() {
        System.out.println("CPU: " + this.CPU+", memory: " + this.memory+", HardDisk: " + this.HardDisk+", brand: " + this.brand);
    }
}
