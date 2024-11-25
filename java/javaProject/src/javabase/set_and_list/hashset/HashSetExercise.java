package javabase.set_and_list.hashset;

import java.util.HashSet;
import java.util.Objects;
import java.util.Set;
public class HashSetExercise {
    public static void main(String[] args) {
        Set set = new HashSet();
        System.out.println(set.add(new employee("jack",20)));
        System.out.println(set.add(new employee("jck",20)));
        System.out.println(set.add(new employee("jack",20)));
    }
}
class employee{
    private String name;
    private int age;
    public employee(String name, int age){
        this.name = name;
        this.age = age;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        employee employee = (employee) o;
        return age == employee.age && Objects.equals(name, employee.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, age);
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }
}
