package javabase.Override;

public class Student extends Person{
    private int id;
    private float score;
    public Student(String name,int age,int id, float score) {
        super(name, age);
        this.id = id;
        this.score = score;
    }
    public void setId(int id) {
        this.id = id;
    }
    public void say(){
        System.out.print("I am student and my id is"+id+" and my score is"+score);
        super.say();
    }
}
