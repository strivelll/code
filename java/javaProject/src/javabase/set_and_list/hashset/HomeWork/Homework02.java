package javabase.set_and_list.hashset.HomeWork;

import java.util.ArrayList;
import java.util.Iterator;

public class Homework02 {
    public static void main(String[] args) {
        ArrayList list=new ArrayList();
        Car car=new Car("宝马",400000);
        Car car1=new Car("宾利",500000);
        list.add(car);
        list.add(car1);
        ArrayList list1=new ArrayList(list);
        list.remove(car);
        System.out.println("car:"+list.contains(car));
        System.out.println("car1:"+list.contains(car1));
        System.out.println(list.size());
        System.out.println(list.isEmpty());
        list.clear();
        list.addAll(list1);
        System.out.println("containsAll"+list.containsAll(list1));
        System.out.println("removeAll"+list.removeAll(list1));
        for(Object o:list1){
            System.out.println(o);
        }
        System.out.println("==================");
        Iterator itr=list1.iterator();
        while (itr.hasNext()) {
            Object next =  itr.next();
            System.out.println(next);

        }

    }
}
class Car{
    private String name;
    private int price;

    public Car(String name, int price) {
        this.name = name;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    @Override
    public String toString() {
        return "Car{" +
                "name='" + name + '\'' +
                ", price=" + price +
                '}';
    }
}