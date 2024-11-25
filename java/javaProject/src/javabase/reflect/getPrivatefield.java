package javabase.reflect;

import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class getPrivatefield {
    public static void main(String[] args) throws ClassNotFoundException, NoSuchFieldException, NoSuchMethodException, InstantiationException, IllegalAccessException, InvocationTargetException {
        Class pt=Class.forName("javabase.reflect.PrivateTest");
        Object o=pt.newInstance();
        Field field=pt.getDeclaredField("name");
        field.setAccessible(true);
        Method m=pt.getMethod("getName");
        System.out.println(m.invoke(o));
        field.set(o,"sssssss");
        System.out.println(m.invoke(o));
    }
}
class PrivateTest{
    private String name="helloKitty";

    public String getName() {
        return name;
    }
}
