package javabase.set_and_list.hashset.HomeWork;

import java.util.*;

@SuppressWarnings({"all"})
public class Homework01 {
    public static void main(String[] args) {
        News n1 = new News("aaaaaaaaaaaaaaaaaa");
        News n2 = new News("bbbbbbbb");
        List list = new ArrayList();
        list.add(n1);
        list.add(n2);
        Collections.reverse(list);
        for (Object o : list) {
            News tmp = (News) o;
            String t = tmp.getTitle();
            if (t.length() > 15) {
                System.out.println(t.substring(0, 15)+"...");
            } else {
                System.out.println(t);
            }
        }

    }
}

class News {
    private String title;
    private String content;

    public News(String title) {
        this.title = title;
    }

    @Override
    public String toString() {
        return "title='" + title + "'";
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public String getTitle() {
        return title;
    }

    public String getContent() {
        return content;
    }
}