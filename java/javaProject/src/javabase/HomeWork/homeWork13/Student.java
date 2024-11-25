package javabase.HomeWork.homeWork13;

import javax.lang.model.element.Name;

public class Student extends Person {
    private int std_id;
    public Student(String Name,int age,String sex, int std_id){
        super(Name,age,sex);
        this.std_id = std_id;
    }

    public void setStd_id(int std_id) {
        this.std_id = std_id;
    }

    public int getStd_id() {
        return std_id;
    }
    public String play(){
        return super.getName()+"爱玩足球";
    }
    public String study(){
        return "我"+super.getName()+"承诺，我会好好学习。";
    }
}
