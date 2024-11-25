package javabase.genericity;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Comparator;

public class Exercise {
    public static void main(String[] args) {
        Employee e1=new Employee("1",1000,new MyDate(2021,4,1));
        Employee e2=new Employee("1",2000,new MyDate(2021,3,8));
        Employee e3=new Employee("1",2000,new MyDate(2010,1,1));
        ArrayList<Employee> list=new ArrayList<>();
        list.add(e1);
        list.add(e2);
        list.add(e3);
        list.sort(new Comparator<Employee>() {
            @Override
            public int compare(Employee o1, Employee o2) {
                if(!o1.getName().equals(o2.getName())) {
                    return o1.getName().compareTo(o2.getName());
                }
                if(o1.getBirthday().getYear()==o2.getBirthday().getYear()) {
                    if(o1.getBirthday().getMonth()==o2.getBirthday().getMonth()) {
                        if(o1.getBirthday().getDay()==o2.getBirthday().getDay()) {
                            return 0;
                        }
                        return o1.getBirthday().getDay()-o2.getBirthday().getDay();
                    }
                    return o1.getBirthday().getMonth()-o2.getBirthday().getMonth();
                }
                return o1.getBirthday().getYear() - o2.getBirthday().getYear();

            }
        });
        for(Employee e:list){
            System.out.println(e);
        }
    }
}
class Employee{
    private String name;
    private int sal;
    private MyDate birthday;
    public Employee(String name, int sal, MyDate birthday) {
        this.name = name;
        this.sal = sal;
        this.birthday = birthday;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "name='" + name + '\'' +
                ", sal=" + sal +
                ", birthday=" + birthday.getYear()+"年" +birthday.getMonth()+"月"+birthday.getDay()+"日"+
                '}';
    }

    public String getName() {
        return name;
    }

    @Test
    public void setName(String name) {
        this.name = name;
    }

    public int getSal() {
        return sal;
    }

    public void setSal(int sal) {
        this.sal = sal;
    }

    public MyDate getBirthday() {
        return birthday;
    }

    public void setBirthday(MyDate birthday) {
        this.birthday = birthday;
    }
}
class MyDate{
    private int year;
    private int month;
    private int day;

    public MyDate(int year, int month, int day) {
        this.day = day;
        this.year = year;
        this.month = month;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public int getMonth() {
        return month;
    }

    public void setMonth(int month) {
        this.month = month;
    }

    public int getDay() {
        return day;
    }

    public void setDay(int day) {
        this.day = day;
    }
}