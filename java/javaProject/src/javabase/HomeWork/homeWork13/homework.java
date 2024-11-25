package javabase.HomeWork.homeWork13;

public class homework {

    public static void main(String[] args) {
        Person[] person=new Person[4];
        person[0]=new Student("小明",18,"男",1);
        person[1]=new Student("小红",20,"女",2);
        person[2]=new Teacher("王老师",38,"女",10);
        person[3]=new Teacher("周老师",28,"男",5);
        for (int i = 0; i <person.length ; i++) {
            System.out.println(person[i].toString());
        }
        StringBuffer sbs = new StringBuffer();
        sbs.append(person[0].toString());
        my_sort(person);
        System.out.println("-----------------------");
        for(Person a:person){
            System.out.println(a.toString());
        }
        System.out.println("-----------------------");
        call_foction(person);
    }
    public static void my_sort(Person[] person){
        for (int i =person.length-1 ; i >0; i--) {
            for (int j = 0; j <i; j++) {
                if(person[j].getAge()<person[j+1].getAge()){
                    Person temp = person[j];
                    person[j] = person[j+1];
                    person[j+1] = temp;
                }
            }
        }
    }
    public static void call_foction(Person[] person){
        for(Person p : person){
            if(p instanceof Student){
                System.out.println(((Student) p).study());
            }
            else if(p instanceof Teacher){
                System.out.println(((Teacher) p).teach());
            }
            else{
                System.out.println("普通人");
            }
        }
    }
}
