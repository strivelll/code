package javabase.Socket.SocketTcp02;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) throws IOException {
        String fileName="D:\\编译\\刷题\\java\\javaProject\\src\\javabase\\Socket\\SocketTcp02\\1_mode.jpg";
        ServerSocket serverSocket = new ServerSocket(9999);
        System.out.println("服务器正在运行，等待客户端连接");
        Socket socket = serverSocket.accept();
        System.out.println("客户端"+socket.getRemoteSocketAddress()+"已连接");
        BufferedWriter bos = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));//输出回复
        BufferedInputStream bis = new BufferedInputStream(socket.getInputStream());
        BufferedOutputStream fos = new BufferedOutputStream(new FileOutputStream(fileName));//输出到文件中去
        byte[] buffer = new byte[1024];
        int readLen;
        while((readLen=bis.read(buffer))!=-1){
            fos.write(buffer,0,readLen);
        }
        bos.write("图片接收成功！！！");
        bos.flush();
        bos.close();
        bis.close();
        fos.close();
        serverSocket.close();
    }
}
