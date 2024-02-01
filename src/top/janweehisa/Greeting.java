package top.janweehisa;

public class Greeting {
    static {
        System.loadLibrary("simple_jni");
    }

    public native void sayHello();

    public static void main(String[] args) {
        new Greeting().sayHello();
    }
}
