import java.net.*;
import java.io.*;
import java.util.Scanner;

public class client{

	public static void main(String[] args) throws IOException{
		Scanner scanner = new Scanner(System.in);

		Socket s = new Socket("localhost", 4999);

		int p = 0;

		while(p == 0){

			PrintWriter pr = new PrintWriter(s.getOutputStream());

			InputStreamReader in = new InputStreamReader(s.getInputStream());

			BufferedReader bf = new BufferedReader(in);

			while(p == 0){

				String msg = scanner.nextLine();

				if(msg.equals("false")){

					p = 1;
					break;

				}

				pr.println(msg);
				pr.flush();

				String str = bf.readLine();
				System.out.println("Server : " + str);

			}

		}

	}

}
