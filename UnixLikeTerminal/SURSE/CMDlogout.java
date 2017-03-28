import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

public class CMDlogout extends SystemCommand{
	public CMDlogout()
	{
		
	}
	

	@Override
	public void execute2(Folder folder) {
		for(User i : Logger.users)
		{
			if(i.username.equals("guest"))
			{
				Logger.setUser(i);
				DateFormat format = new SimpleDateFormat("dd/MM/yy HH:mm:ss");
				Date ora = new Date();
				i.dataLogare = "" + format.format(ora);
				Terminal.txtArea.append("<Succes\n");
			}
		}
		
	}

	@Override
	public void execute2(File file) {
		// TODO Auto-generated method stub
		
	}

}
