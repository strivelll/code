package javabase.map_;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

@SuppressWarnings({"all"})
public class MapExercise {
    public static void main(String[] args) {
        Map map = new HashMap();
        map.put(1,new work(1,"jack",12000));
        map.put(2,new work(2,"jck",18000));
        map.put(3,new work(3,"jk",12000));
        Set keyset=map.keySet();
        for(Object key:keyset){
            Object getvalue=map.get(key);
            if(((work) getvalue).getSalary()>=18000)
            System.out.println(key+":"+getvalue);
        }
        System.out.println("===============");
        Set entry=map.entrySet();
        for(Object entrykey:entry){
            Map.Entry entrykey1=(Map.Entry)entrykey;
            if(((work)entrykey1.getValue()).getSalary()<18000)
            System.out.println(entrykey1.getKey()+"-"+entrykey1.getValue());
        }
        System.out.println("---------------");
        Iterator iterator=entry.iterator();
        while (iterator.hasNext()) {
            Object next =  iterator.next();

            Map.Entry entry1=(Map.Entry)next;
            if(((work) entry1.getValue()).getSalary()>=18000)
            System.out.println(entry1.getKey()+"-"+entry1.getValue());

        }
    }
}
class work{
    private int id;
    private String name;
    private int salary;
    public work(int id, String name, int salary) {
        this.id = id;
        this.name = name;
        this.salary = salary;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public int getSalary() {
        return salary;
    }

    @Override
    public String toString() {
        return "work{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", salary=" + salary +
                '}';
    }
}
