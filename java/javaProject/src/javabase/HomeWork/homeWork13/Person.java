package javabase.HomeWork.homeWork13;

import javax.lang.model.element.Name;

public class Person {
    private String name;
    private int age;
    private String sex;
    public Person(String name, int age,String sex) {
        this.name = name;
        this.age = age;
        this.sex=sex;
    }
    public String play(){
        return "玩泥巴";
    }

    public void setName(String name) {
        this.name = name;
    }
    public void setAge(int age) {
        this.age = age;
    }
    public void setSex(String sex) {
        this.sex = sex;
    }
    public String getName() {
        return name;
    }
    public int getAge() {
        return age;
    }
    public String getSex() {
        return sex;
    }
    public String toString() {
        return "姓名："+name+" 年龄："+age+" 性别："+sex+" "+play();
    }
}
