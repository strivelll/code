package javabase.Override;

public class Person {
    private String name;
    private int age;
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
    public void say(){
        System.out.println("my name is " + name + " and age is " + age);
        return;
    }
}
