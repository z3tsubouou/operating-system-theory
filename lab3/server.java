import java.net.*;
import java.io.*;
import java.util.Scanner;

public class server{

	public static void main(String[] args) throws IOException{
		Scanner scanner = new Scanner(System.in);

		ServerSocket ss = new ServerSocket(4999);

		int p = 0;

		while(true){

			Socket s = ss.accept(); 

			InputStreamReader in = new InputStreamReader(s.getInputStream());

			BufferedReader bf = new BufferedReader(in);

			System.out.println("Client connected");

			p = 0;

			while(p == 0){

				String str = bf.readLine();

				if(str == null){

					System.out.println("Client : disconnected");
					p = 1;
					break;

				}else {

					System.out.println("Client : " + str);

				}

				PrintWriter pr = new PrintWriter(s.getOutputStream());

				String msg = scanner.nextLine();

				pr.println(msg);
				pr.flush();

				
			}


		}

	}
	

}
