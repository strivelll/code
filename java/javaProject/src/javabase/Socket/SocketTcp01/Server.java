package javabase.Socket.SocketTcp01;

import java.io.*;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;
import java.util.Vector;

public class Server extends Thread {
    private ServerSocket serverSocket;
    private Socket socket;
    private boolean flag = true;

    public void quit() throws IOException {
        serverSocket.close();
        socket.close();
    }

    public boolean isFlag() {
        return flag;
    }

    public void setFlag(boolean flag) {
        this.flag = flag;
    }

    public ServerSocket getServerSocket() {
        return serverSocket;
    }

    public Socket getSocket() {
        return socket;
    }

    public Server(int port) throws IOException {
        serverSocket=new ServerSocket(port);
        System.out.println("服务器运行中，等待客户端连接。。。");
        socket=serverSocket.accept();
        System.out.println("客户端"+socket.getInetAddress().getHostAddress()+"已连接");
        this.start();
    }

    @Override
    public void run() {
        BufferedReader br = null;
        try {
            br = new BufferedReader(new InputStreamReader(socket.getInputStream(),"utf-8"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        String line = null;
        while(flag){
            try {
                if ((line = br.readLine()) != null) {
                    System.out.println(socket.getInetAddress().getHostAddress()+": "+line);
                    if(line.equals("quit")){
                        br.close();
                        flag=false;
                    }
                }
            } catch (IOException e) {
                throw new RuntimeException(e);
            }

        }
    }

    public static void main(String[] args) throws IOException {
        Server  server = new Server(9999);



        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(server.getSocket().getOutputStream(),"utf-8"));

        String line = null;
        Scanner sc = new Scanner(System.in);
        while(server.isFlag()){
            line = sc.nextLine();
            if(line.equals("quit")){
                server.setFlag(false);
            }
            bw.write(line);
            bw.newLine();
            bw.flush();
        }
        bw.close();
        server.quit();
        return ;
    }
}
