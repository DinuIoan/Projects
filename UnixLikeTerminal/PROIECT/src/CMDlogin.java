import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

public class CMDlogin extends SystemCommand {
	String Username;
	String pass;
	public CMDlogin(String user ,String pass)
	{
		this.Username = user;
		this.pass = pass;
	}

	@Override
	public void execute2(Folder folder) {
		for(User i: Logger.users)
		{
			if(i.username.equals(Username))
			{
				if(i.parola.equals(pass))
				{
					Logger.setUser(i);
					DateFormat format = new SimpleDateFormat("dd/MM/yy HH:mm:ss");
					Date ora = new Date();
					i.dataLogare = "" + format.format(ora);
					Terminal.txtArea.append("<Succes\n");
				}
				else
					Terminal.txtArea.append("<\nEsuat");
			}
			
		}
		
	}

	@Override
	public void execute2(File file) {
		// TODO Auto-generated method stub
		
	}
}
