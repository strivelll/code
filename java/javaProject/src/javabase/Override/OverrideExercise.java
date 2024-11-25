package javabase.Override;

public class OverrideExercise {
    public static void main(String[] args) {
        Person person=new Person("张三",30);
        person.say();
        Student student=new Student("王五",18,2022,90);
        Student student1=student;
        student1.setId(9999);
        student.say();
        String str ="hello";
        System.out.println(str=="hello");
//        "hello".equals("afdf");
//        person.hashCode();
//        person.toString();
    }
}
