import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

import javax.swing.JFrame;
import javax.swing.JTextArea;

public class Main {
	public static void main(String[] arg){
		
		
		User root = new User("root","rootpass",null,null);
		User guest = new User("guest",null,null,null);

		Logger.users.add(root);
		Logger.users.add(guest);
		Logger.user = guest;
		DateFormat format = new SimpleDateFormat("dd/MM/yy HH:mm:ss");
		Date ora = new Date();
		guest.dataLogare = "" + format.format(ora);
		
		Terminal term = new Terminal("Terminal");
		term.setVisible(true);
        term.open();
        
		
	}

}
