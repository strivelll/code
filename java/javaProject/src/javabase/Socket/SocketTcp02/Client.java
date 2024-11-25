package javabase.Socket.SocketTcp02;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class Client {
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket(InetAddress.getLocalHost(), 9999);
        String filename_src="D:\\编译\\刷题\\java\\javaProject\\src\\javabase\\Socket\\SocketTcp02\\1.jpg";
        BufferedInputStream bis = new BufferedInputStream(new FileInputStream(filename_src));
        BufferedOutputStream bos = new BufferedOutputStream(socket.getOutputStream());
        BufferedInputStream bis1 = new BufferedInputStream(socket.getInputStream());
        byte[] buf = new byte[1024];
        int len;
        while ((len = bis.read(buf)) != -1) {
            bos.write(buf, 0, len);
        }
        bos.flush();
        socket.shutdownOutput();
        while ((len = bis1.read(buf)) != -1) {
            System.out.println(new String(buf, 0, len));
        }
        bos.close();
        bis.close();
        socket.close();

    }
}
