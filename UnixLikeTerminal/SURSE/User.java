import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;


public class User {
	String username;
	String parola;
	String nume;
	String prenume;
	String dataCreare;
	String dataLogare;
	
	public User(String username,String parola, String nume, String prenume){
		DateFormat format = new SimpleDateFormat("dd/MM/yy HH:mm:ss");
		Date dataCreare = new Date();
		this.dataCreare = "" + format.format(dataCreare);
		this.username = username;
		this.parola = parola;
		this.nume = nume;
		this.prenume = prenume;	
	}
	
}

