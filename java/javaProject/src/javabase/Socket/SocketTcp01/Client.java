package javabase.Socket.SocketTcp01;

import java.io.*;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) throws IOException {
        Socket socket = new Socket(InetAddress.getLocalHost(), 9999);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream(), "utf-8"));
        BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream(), "utf-8"));
        while (true) {
            System.out.println("请提出你的问题，quit.表示退出");
            Scanner sc = new Scanner(System.in);
            String msg = sc.nextLine();
            if(msg.equals("quit")){
                break;
            }
            bw.write(msg);
            bw.newLine();
            bw.flush();
            String str = null;
            while ((str = br.readLine()) != null) {
                System.out.println(str);
                if(str.equals("111")) {
                    break;
                }
            }
        }
        socket.shutdownOutput();
        bw.close();
        br.close();
        socket.close();
        return;
    }
}
