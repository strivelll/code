package javabase.HomeWork.homeWork13;

public class Teacher extends Person{
    private int work_age;
    public Teacher(String Name,int age, String sex, int work_age) {
        super(Name,age,sex);
        this.work_age = work_age;
    }

    public void setWork_age(int work_age) {
        this.work_age = work_age;
    }

    public int getWork_age() {
        return work_age;
    }
    public String play(){
        return super.getName()+"爱玩象棋";
    }
    public String teach(){
        return "我"+super.getName()+"承诺，我会好好上课";
    }
}
