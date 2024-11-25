package bookSystem_io;
import java.io.Serializable;
public class book implements Serializable{
    public String name;
    public String author;

    public book(String name, String author) {
        this.author = author;
        this.name = name;
    }
    public void showinfo(int num){
        System.out.println(num+"\t\t"+"《"+this.name+"》"+"\t\t"+this.author);
    }
}
