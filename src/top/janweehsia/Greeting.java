package top.janweehsia;

public class Greeting {
    static {
        System.loadLibrary("greeting_lib.dll");
    }

    public native void sayHello();

    public static void main(String[] args) {
        new Greeting().sayHello();
    }
}
