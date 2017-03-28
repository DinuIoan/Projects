import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

public class CMDnewuser extends SystemCommand{
	User user;
	
	public CMDnewuser(String username,String password,String nume,String prenume)
	{		
		 this.user = new User(username,password,nume,prenume);
	}

	@Override
	public void execute2(Folder folder) {
		Logger.users.add(user);
		Terminal.txtArea.append("<Success\n");
		
		
	}

	@Override
	public void execute2(File file) {
		// TODO Auto-generated method stub
		
	}
}
